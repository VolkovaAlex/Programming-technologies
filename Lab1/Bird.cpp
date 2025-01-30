#include "Bird.h"
#include <fstream>

using namespace std;

Bird::Bird() {
    cout << "Bird default constructor called" << endl;
}

Bird::Bird(const string& breed, const string& color, const string& diet, const string& habitat)
    : breed(breed), color(color), diet(diet), habitat(habitat) {
    cout << "Bird constructor with parameters called" << endl;
}

Bird::Bird(const Bird& other)
    : breed(other.breed), color(other.color), diet(other.diet), habitat(other.habitat) {
    cout << "Bird copy constructor called" << endl;
}

Bird::~Bird() {
    cout << "Bird destructor called" << endl;
}

// Getters
string Bird::getBreed() const {
    return breed;
}

string Bird::getColor() const {
    return color;
}

string Bird::getDiet() const {
    return diet;
}

string Bird::getHabitat() const {
    return habitat;
}

// Setters
void Bird::setBreed(const string& breed) {
    this->breed = breed;
}

void Bird::setColor(const string& color) {
    this->color = color;
}

void Bird::setDiet(const string& diet) {
    this->diet = diet;
}

void Bird::setHabitat(const string& habitat) {
    this->habitat = habitat;
}

void Bird::print() const {
    cout << "Bird: Breed: " << breed << ", Color: " << color
        << ", Diet: " << diet << ", Habitat: " << habitat << endl;
}

void Bird::saveToFile(ofstream& outFile) const {
    outFile << breed << ";" << color << ";" << diet << ";" << habitat << endl;
}

Animal* Bird::loadFromFile(ifstream& inFile) {
    string breed, color, diet, habitat;

    getline(inFile, breed, ';');
    getline(inFile, color, ';');
    getline(inFile, diet, ';');
    getline(inFile, habitat);

    cout << "Bird restored: " << breed << endl;
    return new Bird(breed, color, diet, habitat);
}