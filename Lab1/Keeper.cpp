#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"
#include "exceptions.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

Keeper::Keeper() : count(0), capacity(10) {
    objects = new Animal * [capacity]; // Выделяем память для массива
}

Keeper::~Keeper() {
    for (int i = 0; i < count; ++i) {
        delete objects[i]; // Освобождаем память для каждого объекта
    }
    delete[] objects; // Освобождаем память для массива указателей
}

void Keeper::resize() {
    capacity *= 2; // Увеличиваем объем в два раза
    Animal** newObj = new Animal * [capacity];
    for (int i = 0; i < count; i++) {
        newObj[i] = objects[i]; // Переписываем старые объекты
    }
    delete[] objects;
    objects = newObj; // Устанавливаем новый массив объектов
}

void Keeper::addObj(Animal* obj) {
    if (count >= capacity) {
        resize();
    }
    objects[count++] = obj; // Добавление объекта
}

void Keeper::removeObject(int index) {
    if (index < 0 || index >= count) {
        throw IndexOutOfRangeException(); // Генерируем исключение, если индекс некорректен
    }
    delete objects[index]; // Удаляем объект из памяти
    for (int i = index; i < count - 1; ++i) {
        objects[i] = objects[i + 1]; // Сдвигаем оставшиеся элементы
    }
    --count; // Уменьшаем счетчик объектов
}

void Keeper::printAll() const {
    for (int i = 0; i < count; i++) {
        cout << i << ". ";
        objects[i]->print(); // Вызываем функцию печати для каждого объекта
    }
}

void Keeper::saveToFile(const string& filename) const { //Открывается файл для записи с именем, переданным в параметр filename.
    ofstream outFile(filename);
    if (!outFile.is_open()) { //Успешно ли открылся файл
        throw runtime_error("Error opening file for writing.");
    }

    // Сохраняем каждый объект без индексов, но с указанием типа
    for (int i = 0; i < count; ++i) {
        if (dynamic_cast<Fish*>(objects[i])) { //Используется для проверки, является ли текущий объект типа Student
            outFile << "Fish" << endl;
        }
        else if (dynamic_cast<Bird*>(objects[i])) {
            outFile << "Bird" << endl;
        }
        else if (dynamic_cast<Cat*>(objects[i])) {
            outFile << "Cat" << endl;
        }
        // Сохраняем сам объект
        objects[i]->saveToFile(outFile);
    }

    outFile.close();

}

void Keeper::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw runtime_error("Error opening file for reading.");
    }

    string type;
    while (getline(inFile, type)) {
        Animal* obj = nullptr;

        // Определяем тип объекта и загружаем его
        if (type == "Fish") {
            obj = Fish::loadFromFile(inFile);
        }
        else if (type == "Bird") {
            obj = Bird::loadFromFile(inFile);
        }
        else if (type == "Cat") {
            obj = Cat::loadFromFile(inFile);
        }
        else {
            cerr << "Error: unrecognized object type \"" << type << "\"" << endl;
            continue; // Пропускаем некорректные строки
        }

        if (obj) {
            addObj(obj);  // Добавляем объект в контейнер
            cout << "Object of type " << type << " loaded successfully." << endl;
        }
    }

    inFile.close();
}