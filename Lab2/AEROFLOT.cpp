#include "AEROFLOT.h"
#include <iostream>

// Конструктор по умолчанию
AEROFLOT::AEROFLOT() : destination("Unknown"), flightNumber(0), aircraftType("Unknown") {}

// Конструктор с параметрами
AEROFLOT::AEROFLOT(const std::string& destination, int flightNumber, const std::string& aircraftType)
    : destination(destination), flightNumber(flightNumber), aircraftType(aircraftType) {}

// Деструктор
AEROFLOT::~AEROFLOT() {}

// Геттеры
std::string AEROFLOT::getDestination() const {
    return destination;
}

int AEROFLOT::getFlightNumber() const {
    return flightNumber;
}

std::string AEROFLOT::getAircraftType() const {
    return aircraftType;
}

// Сеттеры
void AEROFLOT::setDestination(const std::string& destination) {
    this->destination = destination;
}

void AEROFLOT::setFlightNumber(int flightNumber) {
    this->flightNumber = flightNumber;
}

void AEROFLOT::setAircraftType(const std::string& aircraftType) {
    this->aircraftType = aircraftType;
}