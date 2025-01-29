#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include <iostream>
#include <string>

using namespace std;

class Cat : public Animal {
private:
    string breed;
    string color;
    string owner_name;
    string pet_name;

public:
    Cat();
    Cat(const string& breed, const string& color, const string& owner_name, const string& pet_name);
    virtual void print() const override;
    void saveToFile(ofstream& outFile) const override;
    static Animal* loadFromFile(ifstream& inFile);

};

#endif