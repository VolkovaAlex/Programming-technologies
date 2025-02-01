#include "AEROFLOT.h"
#include <iostream>

using namespace std;

int main() {
    // Создание объекта AEROFLOT
    AEROFLOT flight("Moscow", 123, "Boeing 737");

    // Вывод информации об объекте
    cout << "Пункт назначения: " << flight.getDestination() << "\n";
    cout << "Номер рейса: " << flight.getFlightNumber() << "\n";
    cout << "Тип самолета: " << flight.getAircraftType() << "\n";
    return 0;
}