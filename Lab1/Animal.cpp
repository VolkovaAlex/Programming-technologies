#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"
#include <stdexcept>

Animal* Animal::loadFromFile(ifstream& inFile) {

    char type;
    inFile.read(&type, sizeof(type)); // —читываем тип объекта из файла

    switch (type) {
    case 'F':
        return Fish::loadFromFile(inFile);
    case 'B':
        return Bird::loadFromFile(inFile);
    case 'C':
        return Cat::loadFromFile(inFile);
    default:
        throw runtime_error("Unknown object type when uploading from a file.");
    }
}
