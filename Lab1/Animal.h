#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Animal {
public:
    virtual void print() const = 0;
    virtual ~Animal() = default;
    virtual void saveToFile(ofstream& outFile) const = 0;
    static Animal* loadFromFile(ifstream& inFile) { return nullptr; };
};

#endif