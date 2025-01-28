#include "Keeper.h"
#include <iostream>

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