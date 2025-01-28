#ifndef KEEPER_H
#define KEEPER_H

#include <string>
#include "Animal.h"

class Keeper {
private:
    Animal** objects;
    int count;
    int capacity;
    void resize();

public:
    Keeper();
    ~Keeper();
    void addObj(Animal* obj);
    void printAll() const;
};

#endif