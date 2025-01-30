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
    // Конструкторы
    Cat();
    Cat(const string& breed, const string& color, const string& owner_name, const string& pet_name);
    Cat(const Cat& other);

    // Деструктор
    ~Cat();

    // Getters
    string getBreed() const;
    string getColor() const;
    string getOwnerName() const;
    string getPetName() const;

    // Setters
    void setBreed(const string& breed);
    void setColor(const string& color);
    void setOwnerName(const string& owner_name);
    void setPetName(const string& pet_name);

    // Прочие функции
    void print() const override;
    void saveToFile(ofstream& outFile) const override;
    static Animal* loadFromFile(ifstream& inFile);
};

#endif