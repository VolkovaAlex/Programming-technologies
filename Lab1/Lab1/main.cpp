#include <iostream>
#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

using namespace std;

int main() {
    Keeper keeper;

    keeper.addObj(new Fish("Guppy", "Multicolored", "Omnivore"));
    keeper.addObj(new Bird("Sparrow", "Gray", "Grain", "City"));
    keeper.addObj(new Cat("Siamese", "Beige", "John Smith", "Mittens"));

    keeper.printAll();

    return 0;
}