#pragma once
#include <string>

class AEROFLOT {
private:
    std::string destination;
    int flightNumber;
    std::string aircraftType;

public:
    // Конструкторы
    AEROFLOT();
    AEROFLOT(const std::string& destination, int flightNumber, const std::string& aircraftType);
    // Деструктор
    ~AEROFLOT();

    // Методы доступа (геттеры)
    std::string getDestination() const;
    int getFlightNumber() const;
    std::string getAircraftType() const;

    // Методы доступа (сеттеры)
    void setDestination(const std::string& destination);
    void setFlightNumber(int flightNumber);
    void setAircraftType(const std::string& aircraftType);
};