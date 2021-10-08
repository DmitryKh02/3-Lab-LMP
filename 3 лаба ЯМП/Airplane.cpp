#include <fstream>
#include <string>
#include "Airplane.h"

using std::cin;
using std::cout;
using std::getline;

void reading(AIRPLANE& elem, std::ifstream& File)
{
	getline(File, elem.destination);

	File >> elem.flightNumber;
	File.ignore(1);

	getline(File, elem.modelAirplane);

	getline(File, elem.FIO);


	elem.infoData = createNewPlaceToData();

	File >> elem.infoData->day;
	File.ignore(1);

	File >> elem.infoData->month;
	File.ignore(1);

	File >> elem.infoData->year;
	File.ignore('\n');

	std::string clear;
	getline(File, clear);
}

void print(AIRPLANE& elem)
{
	cout << "\n______________________________________________________________";
	cout << "\n����� ����������: " << elem.destination;
	cout << "\n����� �����: " << elem.flightNumber;
	cout << "\n������ �������: " << elem.modelAirplane;
	cout << "\n������� ��� �������� ���������: " << elem.FIO;
	cout << "\n���� ������: " << elem.infoData->day << "." << elem.infoData->month << "." << elem.infoData->year;
	cout << "\n---------------------------------------------------------------\n";
}

DATA* createNewPlaceToData()
{
	DATA* p = new DATA;
	return p;
}
