#include "Cat.h"
#include <iostream>
using namespace std;

Cat::Cat() {
}

Cat::Cat(const string& breed, const string& color, const string& owner_name, const string& pet_name)
    : breed(breed), color(color), owner_name(owner_name), pet_name(pet_name) {
}

void Cat::print() const {
    cout << "Cat: Breed: " << breed << ", Color: " << color
        << ", Owner: " << owner_name << ", Pet Name: " << pet_name << endl;
}