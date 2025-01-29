#include "Cat.h"
#include <iostream>
#include <fstream>

using namespace std;

Cat::Cat() {
}

Cat::Cat(const string& breed, const string& color, const string& owner_name, const string& pet_name)
    : breed(breed), color(color), owner_name(owner_name), pet_name(pet_name) {
}

void Cat::print() const {
    cout << "Cat: Breed: " << breed << ", Color: " << color
        << ", Owner: " << owner_name << ", Pet Name: " << pet_name << endl;
}

void Cat::saveToFile(ofstream& outFile) const {
    outFile << breed << ";" << color << ";" << owner_name << ";" << pet_name << endl;
}

Animal* Cat::loadFromFile(ifstream& inFile) {
    string breed, color, owner_name, pet_name;

    getline(inFile, breed, ';');
    getline(inFile, color, ';');
    getline(inFile, owner_name, ';');
    getline(inFile, pet_name);

    cout << "Cat restored: " << breed << endl;
    return new Cat(breed, color, owner_name, pet_name);
}