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
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif