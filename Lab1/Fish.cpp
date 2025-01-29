#include "Fish.h"
#include <iostream>
#include <fstream>

using namespace std;

Fish::Fish() {
}

Fish::Fish(const string& breed, const string& color, const string& diet)
    : breed(breed), color(color), diet(diet) {
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