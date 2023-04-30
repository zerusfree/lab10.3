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
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������

	string fileName;
	string selectedItem;

	cout << "������ ��'� �����: ";
	cin >> fileName;
	cin.ignore();

	int menuItem;

	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - ��������� ��������" << endl;
		cout << " [2] - ���� ������" << endl;
		cout << " [3] - ������ �������" << endl;
		cout << " [4] - ���� �� ����� ���������� ��� ��������, �� ����������� ��� ����������� � ��������� �����" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
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
				cout << "������ �������� ������� ��������?: ";
				cin >> N;
				cin.ignore();

				if (N > 0) {
					ch = true;
				}
				else {
					cout << "ʳ������ �� �� ���� ����� ����" << endl;
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
			cout << "������ ����� �����������/�����������: "; getline(cin, selectedItem);
			cout << endl;
			PrintChosenRoutes(fileName, selectedItem);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
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

	cout << "�������� ���� ������ ����� �� ������";
}
void printFile(string& fileName)
{
	ifstream infile(fileName);

	if (!infile.is_open())
	{
		cout << "������� �������� �����!" << endl;
		return;
	}

	cout << "========================================================================" << endl;
	cout << "| ����� �������� | ���������� ����� �������� | ʳ������ ����� �������� |" << endl;
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
		cout << "������� �������� �����!" << endl;
		return;
	}

	string startPoint, endPoint;
	int numberOfRoute;

	cout << "������ ����� ��������: ";
	cin >> numberOfRoute;
	
	cin.ignore();
	cout << endl;

	cout << "������ ����� ����������� ������ ��������: ";
	getline(cin, startPoint);

	cout << "������ ����� �������� ������ ��������: ";
	getline(cin, endPoint);

	

	cout << endl;


	outfile << numberOfRoute << " " << startPoint << " " << endPoint << endl;

	outfile.close();
}

void PrintChosenRoutes(const string& filename, const string selectedItem)
{
	ifstream infile(filename);

	if (!infile.is_open()) {
		cout << "������� �������� �����!" << endl;
		return;
	}


	int f;
	int i = 0;
	cout << "������ �� ���������� �� ������� ����� ( 0 - ���������� , 1 - ������� ): "; cin >> f;

	cout << "========================================================================" << endl;
	cout << "| ����� �������� | ���������� ����� �������� | ʳ������ ����� �������� |" << endl;
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
		cout << "�������� ���� ����� �������� ������� � ������� ��������" << endl;
		cout << endl;
	}

	infile.close();
	cout << "========================================================================" << endl;
}