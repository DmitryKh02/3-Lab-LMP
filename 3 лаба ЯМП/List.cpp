#include <string>
#include "List.h"


void init(Tlist& head)
{
	head = nullptr;
}

AIRPLANE* createNewPlaceToAirplane()
{
	AIRPLANE* p = new AIRPLANE;
	return p;
}

void addAfterNode(Tlist pNode, std::ifstream& file)
{
	Tlist p = new NODE;
	p->elem = createNewPlaceToAirplane();

	pNode->next = p;
	p->next = nullptr;

	reading(*(p->elem), file);

	p = nullptr;
}

void addToHead(Tlist& head, std::ifstream& file)
{
	Tlist p = new NODE;
	p->elem = createNewPlaceToAirplane();

	head = p;
	head->next = nullptr;

	reading(*(head->elem), file);

	p = nullptr;
}



void deleteEndOfList(Tlist head)
{
	Tlist p = head;

	if (p->next != nullptr)
	{
		while (p->next->next != nullptr)
			p = p->next;

		Tlist pNode = p->next;
		p->next = nullptr;

		delete pNode->elem->infoData;
		delete pNode->elem;
		delete pNode;

		pNode = nullptr;
	}
}

void deleteHead(Tlist& head)
{
	delete head->elem->infoData;
	delete head->elem;
	delete head;
	head = nullptr;
}

void clear(Tlist& head)
{
	Tlist p = head;

	while (p->next != nullptr)
		deleteEndOfList(head);

	deleteHead(head);
}



void swapList(Tlist first, Tlist second)
{
	AIRPLANE* pFree = first->elem;
	first->elem = second->elem;
	second->elem = pFree;
	pFree = nullptr;
}

int compareList(Tlist first, Tlist second, int type)
{
	int result = -1; //1 если первая > второй

	switch (type)
	{
	case 1:
	{
		result = first->elem->destination.compare(second->elem->destination);
	}break;
	case 2:
	{
		result = first->elem->flightNumber > second->elem->flightNumber ? 1 : 0;
	}break;
	case 3:
	{
		result = first->elem->modelAirplane.compare(second->elem->modelAirplane);
	}break;
	case 4:
	{
		result = first->elem->FIO.compare(second->elem->FIO);
	}break;
	case 5:
	{
		if (first->elem->infoData->year > second->elem->infoData->year) result = 1;
		else
		{
			if (first->elem->infoData->year == second->elem->infoData->year)
			{
				if (first->elem->infoData->month > second->elem->infoData->month) result = 1;
				else
				{
					if (first->elem->infoData->month == second->elem->infoData->month)
					{
						if (first->elem->infoData->day > second->elem->infoData->day) result = 1;
						else
						{
							if (first->elem->infoData->day == second->elem->infoData->day) result = 0;
							else result = -1;
						}
					}
					else result = -1;
				}
			}
			else result = -1;
		}
	}break;
	}

	return result;
}

void sort(Tlist head, int type)
{
	Tlist i = head;
	Tlist j = i;


	while (i->next->next != nullptr)
	{
		j = i;

		while (j != nullptr)
		{
			if (compareList(i, j, type) > 0) swapList(i, j);
			else
			{
				if (compareList(i, j, type) == 0)
				{
					int x = 1;
					int result = -1;

					while (((x >= 1) && (x <= 5)) && (result != 1))
					{
						result = compareList(i, j, x);
						x++;
					}

					if (result == 1) swapList(i, j);
				}
			}
			j = j->next;
		}

		i = i->next;
	}

	if ((i->next->next == nullptr) && (compareList(i, i->next, type) >= 0)) swapList(i, i->next);
}



void printList(Tlist head)
{
	Tlist p = head;
	while (p)
	{
		print(*(p->elem));
		p = p->next;
	}
}
