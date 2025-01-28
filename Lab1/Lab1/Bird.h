#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"
#include <iostream>
#include <string>

using namespace std;

class Bird : public Animal {
private:
    string breed;
    string color;
    string diet;
    string habitat;

public:
    Bird();
    Bird(const string& breed, const string& color, const string& diet, const string& habitat);
    virtual void print() const override;
};

#endif