#include <iostream>
#include <string>
#include <Windows.h>
#include "List.h"

using std::cin;
using std::cout;


int checkChose(int left, int right);

void Menu();

void MenuSorting();

std::string MyTask(Tlist head, std::string destination);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choseMenu = 0;

	std::ifstream file;
	file.open("Timetable.txt");


	if (!file.is_open())cout << "�������� � ������!";
	else
	{
		Tlist head, p;
		init(head);
		p = head;


		while (!file.eof())
		{
			if (head == nullptr)
			{
				addToHead(head, file);
				p = head;
			}
			else
			{
				addAfterNode(p, file);
				p = p->next;
			}
		}


		do
		{
			Menu();
			choseMenu = checkChose(1, 4);

			switch (choseMenu)
			{
			case 1:
			{
				printList(head);
			}break;
			case 2:
			{
				MenuSorting();

				int choseSorting;
				choseSorting = checkChose(1, 6);

				sort(head, choseSorting);
			}break;
			case 3:
			{
				std::ofstream fin;
				std::string destination;
				std::string result;

				fin.open("Result.txt");

				cout << "\n������� ����� ����������, � ������� �� ������ ������ ����� ����� �������� ������: ";
				cin >> destination;

				result = MyTask(head, destination);

				cout << result;
				fin << result;
				fin.close();
			}break;
			case 4:
			{
				clear(head);
			}break;
			}
		} while (choseMenu != 4);
	}

	file.close();

	return 0;
}


int checkChose(int left = 1, int right = 10000)
{
	int chose;

	cout << "\n������� �������� �� " << left << " �� " << right << "\n";
	cin >> chose;


	while (chose < left || chose > right)
	{
		cin.ignore();

		cout << "\n������� ������ �������� (�� " << left << " �� " << right << "): ";

		cin >> chose;
	}

	return chose;
}

void Menu()
{
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n1)������ ������";
	cout << "\n2)������������� ������";
	cout << "\n3)������ ����� ���������� � ������ ������ �������, ������� ���� ������ ���� ������";
	cout << "\n4)�������� ������ � ��������� ������";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
}

void MenuSorting()
{
	cout << "\n�� ������ ��������� �� ������ ������������� ������: ";
	cout << "\n1)����� ����������";
	cout << "\n2)����� �����";
	cout << "\n3)������ �������";
	cout << "\n4)��� ���������";
	cout << "\n5)���� ������";
	cout << "\n6)�����";
}

std::string MyTask(Tlist head, std::string destination)
{
	sort(head, 1);

	Tlist p = head, k = head;
	std::string result = "������ ��������!";

	bool findDestination = false;
	int countresult = 0, countmax = 0;

	while ((p != nullptr) && (!findDestination))
		if (p->elem->destination == destination) findDestination = true;
		else p = p->next;

	if (!findDestination) result = "\n������ ������ ���������� � ������ ������ ���!"; \
	else
	{
		result = p->elem->modelAirplane;

		while ((p != nullptr) && (p->elem->destination == destination))
		{
			k = p;
			countresult = 0;

			while ((k != nullptr) && (k->elem->destination == destination))
			{
				if (p->elem->modelAirplane == k->elem->modelAirplane)
				{
					countresult++;
					if (countresult > countmax)
					{
						result = p->elem->modelAirplane;
						countmax = countresult;
					}
				}

				k = k->next;
			}

			p = p->next;
		}
	}

	return result;
}
