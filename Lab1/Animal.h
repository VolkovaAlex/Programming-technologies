#ifndef ANIMAL_H
#define ANIMAL_H
#include <fstream>
using namespace std;

class Animal {
public:
    virtual ~Animal() {}
    virtual void print() const = 0;
    virtual void saveToFile(ofstream& outFile) const = 0;
    static Animal* loadFromFile(ifstream& inFile);
};
#endif
