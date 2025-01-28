#include "Bird.h"
#include <iostream>
using namespace std;

Bird::Bird() {
}
Bird::Bird(const string& breed, const string& color, const string& diet, const string& habitat)
    : breed(breed), color(color), diet(diet), habitat(habitat) {
}

void Bird::print() const {
    cout << "Bird: Breed: " << breed << ", Color: " << color
        << ", Diet: " << diet << ", Habitat: " << habitat << endl;
}