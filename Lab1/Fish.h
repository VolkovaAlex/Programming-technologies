#ifndef FISH_H
#define FISH_H

#include "Animal.h"
#include <iostream>
#include <string>

using namespace std;

class Fish : public Animal {
private:
    string breed;
    string color;
    string diet;

public:
    // Конструкторы
    Fish();
    Fish(const string& breed, const string& color, const string& diet);
    Fish(const Fish& other); // Конструктор копирования

    // Деструктор
    ~Fish();

    // Getters
    string getBreed() const;
    string getColor() const;
    string getDiet() const;

    // Setters
    void setBreed(const string& breed);
    void setColor(const string& color);
    void setDiet(const string& diet);

    // Прочие функции
    void print() const override;
    void saveToFile(ofstream& outFile) const override;
    static Animal* loadFromFile(ifstream& inFile);
};

#endif