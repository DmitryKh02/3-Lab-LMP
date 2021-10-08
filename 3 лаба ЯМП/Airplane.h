#pragma once
#include <iostream> 
#include <fstream>


struct AIRPLANE
{
	std::string destination;
	int flightNumber;
	std::string modelAirplane;
	std::string FIO;
	struct DATA* infoData;
};

struct DATA
{
	int day;
	int month;
	int year;
};

void reading(AIRPLANE& elem, std::ifstream& File);

void print(AIRPLANE& elem);

DATA* createNewPlaceToData();

