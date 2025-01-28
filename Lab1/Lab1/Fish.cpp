#include "Fish.h"
#include <iostream>
using namespace std;

Fish::Fish() {
}

Fish::Fish(const string& breed, const string& color, const string& diet)
    : breed(breed), color(color), diet(diet) {
}

void Fish::print() const {
    cout << "Fish: Breed: " << breed << ", Color: " << color
        << ", Diet: " << diet << endl;
}