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
	cout << "\nМесто назначения: " << elem.destination;
	cout << "\nНомер рейса: " << elem.flightNumber;
	cout << "\nМодель самолёта: " << elem.modelAirplane;
	cout << "\nФамилия Имя Отчество пассажира: " << elem.FIO;
	cout << "\nДата вылета: " << elem.infoData->day << "." << elem.infoData->month << "." << elem.infoData->year;
	cout << "\n---------------------------------------------------------------\n";
}

DATA* createNewPlaceToData()
{
	DATA* p = new DATA;
	return p;
}
