#pragma once
#include <string>

class AEROFLOT {
private:
    std::string destination;
    int flightNumber;
    std::string aircraftType;

public:
    // ������������
    AEROFLOT();
    AEROFLOT(const std::string& destination, int flightNumber, const std::string& aircraftType);
    // ����������
    ~AEROFLOT();

    // ������ ������� (�������)
    std::string getDestination() const;
    int getFlightNumber() const;
    std::string getAircraftType() const;

    // ������ ������� (�������)
    void setDestination(const std::string& destination);
    void setFlightNumber(int flightNumber);
    void setAircraftType(const std::string& aircraftType);
};