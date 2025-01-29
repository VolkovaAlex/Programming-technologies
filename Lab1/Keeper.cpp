#include "Keeper.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

using namespace std;

Keeper::Keeper() : count(0), capacity(10) {
    objects = new Animal * [capacity];
}

Keeper::~Keeper() {
    for (int i = 0; i < count; ++i) {
        delete objects[i];
    }
    delete[] objects;
}

void Keeper::resize() {
    capacity *= 2;
    Animal** newObj = new Animal * [capacity];
    for (int i = 0; i < count; i++) {
        newObj[i] = objects[i];
    }
    delete[] objects;
    objects = newObj;
}

void Keeper::addObj(Animal* obj) {
    if (count >= capacity) {
        resize();
    }
    objects[count++] = obj;
}

void Keeper::printAll() const {
    for (int i = 0; i < count; i++) {
        cout << i << ". ";
        objects[i]->print();
    }
}

void Keeper::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw runtime_error("Error opening file for writing.");
    }

    for (int i = 0; i < count; ++i) {
        if (dynamic_cast<Fish*>(objects[i])) {
            outFile << "Fish" << endl;
        }
        else if (dynamic_cast<Bird*>(objects[i])) {
            outFile << "Bird" << endl;
        }
        else if (dynamic_cast<Cat*>(objects[i])) {
            outFile << "Cat" << endl;
        }
        objects[i]->saveToFile(outFile);
    }
    outFile.close();
}

void Keeper::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw runtime_error("Error opening file for reading.");
    }

    string type;
    while (getline(inFile, type)) {
        Animal* obj = nullptr;

        if (type == "Fish") {
            obj = Fish::loadFromFile(inFile);
        }
        else if (type == "Bird") {
            obj = Bird::loadFromFile(inFile);
        }
        else if (type == "Cat") {
            obj = Cat::loadFromFile(inFile);
        }
        else {
            cerr << "Error: unrecognized object type \"" << type << "\"" << endl;
            continue;
        }
        if (obj) {
            addObj(obj);
            cout << "Object of type " << type << " loaded successfully." << endl;
        }
    }
    inFile.close();
}