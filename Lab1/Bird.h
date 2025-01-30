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
    // Конструкторы
    Bird();
    Bird(const string& breed, const string& color, const string& diet, const string& habitat);
    Bird(const Bird& other);

    // Деструктор
    ~Bird();

    // Getters
    string getBreed() const;
    string getColor() const;
    string getDiet() const;
    string getHabitat() const;

    // Setters
    void setBreed(const string& breed);
    void setColor(const string& color);
    void setDiet(const string& diet);
    void setHabitat(const string& habitat);

    // Прочие функции
    void print() const override;
    void saveToFile(ofstream& outFile) const override;
    static Animal* loadFromFile(ifstream& inFile);
};

#endif