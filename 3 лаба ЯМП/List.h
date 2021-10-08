#pragma once
#include <iostream> 
#include <fstream>
#include "Airplane.h"


struct NODE
{
	struct AIRPLANE* elem;
	NODE* next;
};



typedef NODE* Tlist;



void init(Tlist& head);

AIRPLANE* createNewPlaceToAirplane();

void addAfterNode(Tlist pNode, std::ifstream& file);

void addToHead(Tlist& head, std::ifstream& file);



void deleteEndOfList(Tlist head);

void deleteHead(Tlist& head);

void clear(Tlist& head);



void swapList(Tlist first, Tlist second);

int compareList(Tlist first, Tlist second, int type);

void sort(Tlist head, int type);



void printList(Tlist head);

