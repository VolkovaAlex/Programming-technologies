#include "Bird.h"
#include <iostream>
#include <fstream>

using namespace std;

Bird::Bird() {
}
Bird::Bird(const string& breed, const string& color, const string& diet, const string& habitat)
    : breed(breed), color(color), diet(diet), habitat(habitat) {
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