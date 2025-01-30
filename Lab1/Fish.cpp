#include "Fish.h"
#include <fstream>

using namespace std;

Fish::Fish() {
    cout << "Fish default constructor called" << endl;
}

Fish::Fish(const string& breed, const string& color, const string& diet)
    : breed(breed), color(color), diet(diet) {
    cout << "Fish constructor with parameters called" << endl;
}

Fish::Fish(const Fish& other)
    : breed(other.breed), color(other.color), diet(other.diet) {
    cout << "Fish copy constructor called" << endl;
}

Fish::~Fish() {
    cout << "Fish destructor called" << endl;
}

// Getters
string Fish::getBreed() const {
    return breed;
}

string Fish::getColor() const {
    return color;
}

string Fish::getDiet() const {
    return diet;
}

// Setters
void Fish::setBreed(const string& breed) {
    this->breed = breed;
}

void Fish::setColor(const string& color) {
    this->color = color;
}

void Fish::setDiet(const string& diet) {
    this->diet = diet;
}

void Fish::print() const {
    cout << "Fish: Breed: " << breed << ", Color: " << color
        << ", Diet: " << diet << endl;
}

void Fish::saveToFile(ofstream& outFile) const {
    outFile << breed << ";" << color << ";" << diet << endl;
}

Animal* Fish::loadFromFile(ifstream& inFile) {
    string breed, color, diet;

    getline(inFile, breed, ';');
    getline(inFile, color, ';');
    getline(inFile, diet);

    cout << "Fish restored: " << breed << endl;
    return new Fish(breed, color, diet);
}