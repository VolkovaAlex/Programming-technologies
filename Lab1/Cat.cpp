#include "Cat.h"
#include <fstream>

using namespace std;

Cat::Cat() {
    cout << "Cat default constructor called" << endl;
}

Cat::Cat(const string& breed, const string& color, const string& owner_name, const string& pet_name)
    : breed(breed), color(color), owner_name(owner_name), pet_name(pet_name) {
    cout << "Cat constructor with parameters called" << endl;
}

Cat::Cat(const Cat& other)
    : breed(other.breed), color(other.color), owner_name(other.owner_name), pet_name(other.pet_name) {
    cout << "Cat copy constructor called" << endl;
}

Cat::~Cat() {
    cout << "Cat destructor called" << endl;
}

// Getters
string Cat::getBreed() const {
    return breed;
}

string Cat::getColor() const {
    return color;
}

string Cat::getOwnerName() const {
    return owner_name;
}

string Cat::getPetName() const {
    return pet_name;
}

// Setters
void Cat::setBreed(const string& breed) {
    this->breed = breed;
}

void Cat::setColor(const string& color) {
    this->color = color;
}

void Cat::setOwnerName(const string& owner_name) {
    this->owner_name = owner_name;
}

void Cat::setPetName(const string& pet_name) {
    this->pet_name = pet_name;
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