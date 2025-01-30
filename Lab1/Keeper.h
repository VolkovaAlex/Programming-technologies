#ifndef KEEPER_H
#define KEEPER_H
#include <iostream>
#include "Animal.h"
using namespace std;

class Keeper {
private:
	Animal** objects; //������ ���������� �� ������� �������� ������
	int capacity; //����� �������
	int count; //������� ���������� ��������

	void resize();

public:
	Keeper();
	~Keeper();

	void addObj(Animal* obj);
	void removeObject(int index);
	void saveToFile(const string& filename) const;
	void loadFromFile(const string& filename);
	void printAll() const;
};

#endif