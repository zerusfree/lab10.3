#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

void createFile(string& fileName);
void printFile(string& fileName);
void AddMarshrut(const string& filename);
void PrintChosenRoutes(const string& filename, const string selectedItem);


int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	string fileName;
	string selectedItem;

	cout << "Введіть ім'я файлу: ";
	cin >> fileName;
	cin.ignore();

	int menuItem;

	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - створення маршрутів" << endl;
		cout << " [2] - вивід данних" << endl;
		cout << " [3] - додати маршрут" << endl;
		cout << " [4] - вивід на екран інформації про маршрути, які починаються або закінчуються у вибраному пункті" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;

		switch (menuItem)
		{
		case 1:
			createFile(fileName);
			break;
		case 2:
			printFile(fileName);
			break;
		case 3:
			int N;
			bool ch;

			do {
				cout << "Скільки маршрутів потрібно створити?: ";
				cin >> N;
				cin.ignore();

				if (N > 0) {
					ch = true;
				}
				else {
					cout << "Кількість не має бути менше нуля" << endl;
					ch = false;
				}

			} while (!ch);

			for (int i = 0; i < N; i++) {
				AddMarshrut(fileName);
			}
			break;
		case 4:
			cin.get();
			cin.sync();
			cout << "Введіть пункт призначення/відправлення: "; getline(cin, selectedItem);
			cout << endl;
			PrintChosenRoutes(fileName, selectedItem);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);


	return 0;
}

void createFile(string& fileName)
{
	ofstream outfile(fileName);
	outfile << "1\t\tLviv\t\tDrohobych" << endl;
	outfile << "2\t\tDrohobych\t\tBoryslav" << endl;
	outfile << "3\t\tKyiv\t\tLviv" << endl;
	outfile << "4\t\tLviv\t\tBoryslav" << endl;
	outfile << "5\t\tBoryslav\t\tKyiv" << endl;
	outfile.close();

	cout << "Маршрути були успішно додані до списку";
}
void printFile(string& fileName)
{
	ifstream infile(fileName);

	if (!infile.is_open())
	{
		cout << "Помилка відкриття файлу!" << endl;
		return;
	}

	cout << "========================================================================" << endl;
	cout << "| Номер маршруту | Початковий пункт маршруту | Кінцевий пункт маршруту |" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	string startPoint, endPoint;
	int numberOfRoute;

	while (infile >> numberOfRoute >> startPoint >> endPoint)
	{
		cout << "| " << setw(15) << left << numberOfRoute
			<< "| " << setw(26) << right << startPoint
			<< "| " << setw(24) << right << endPoint << "|" << endl;
	}

	cout << "========================================================================" << endl;

	infile.close();
}

void AddMarshrut(const string& filename)
{
	ofstream outfile(filename, ios::app);

	if (!outfile.is_open())
	{
		cout << "Помилка відкриття файлу!" << endl;
		return;
	}

	string startPoint, endPoint;
	int numberOfRoute;

	cout << "Введіть номер маршруту: ";
	cin >> numberOfRoute;
	
	cin.ignore();
	cout << endl;

	cout << "Введіть назву початкового пункту маршруту: ";
	getline(cin, startPoint);

	cout << "Введіть назву кінцевого пункту маршруту: ";
	getline(cin, endPoint);

	

	cout << endl;


	outfile << numberOfRoute << " " << startPoint << " " << endPoint << endl;

	outfile.close();
}

void PrintChosenRoutes(const string& filename, const string selectedItem)
{
	ifstream infile(filename);

	if (!infile.is_open()) {
		cout << "Помилка відкриття файлу!" << endl;
		return;
	}


	int f;
	int i = 0;
	cout << "Введіть чи початковий чи кінцевий пункт ( 0 - початковий , 1 - кінцевий ): "; cin >> f;

	cout << "========================================================================" << endl;
	cout << "| Номер маршруту | Початковий пункт маршруту | Кінцевий пункт маршруту |" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	string startPoint, endPoint;
	int numberOfRoute;

	while (infile >> numberOfRoute >> startPoint >> endPoint)
	{
		if (f == 0 && startPoint == selectedItem)
		{
			cout << "| " << setw(15) << left << numberOfRoute
				<< "| " << setw(26) << right << startPoint
				<< "| " << setw(24) << right << endPoint << "|" << endl;
			i++;
		}
		else if (f == 1 && endPoint == selectedItem)
		{
			cout << "| " << setw(15) << left << numberOfRoute
				<< "| " << setw(26) << right << startPoint
				<< "| " << setw(24) << right << endPoint << "|" << endl;
			i++;
		}
	}

	if (i == 0)
	{
		cout << endl;
		cout << "Вибраний вами пункт маршруту відсутній у таблиці маршрутів" << endl;
		cout << endl;
	}

	infile.close();
	cout << "========================================================================" << endl;
}