#include <iostream>
#include "event.h"
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include "Functions.h"

using namespace std;

bool ifLeapYear(int year) {
	if (year % 4 != 0)
		return false;
	else {
		if (year % 100 != 0)
			return true;
		else {
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
	}
}

void Print(event line[]) {
	cout << "ID" << " | " << "Ќј«¬јЌ»≈" << " | " << "¬–≈ћя" << " | " << "ћ≈—“ќ" << endl;
	for (int i = 0; i < 50; i++)
	{
		if (line[i].name != "title")
			cout << line[i].id << " | " << line[i].name << " | " << line[i].date << " | " << line[i].location << endl;
	}
}

void Save(event line[]) {
	ofstream fileout;
	fileout.open("FOOD.txt");
	for (int i = 0; i < 50; i++)
	{
		if (line[i].name != "title" && line[i].id < 10) {
			fileout << line[i].id << " |" << line[i].name << "|" << line[i].date << "|" << line[i].location << "|\n";
		}
		else if (line[i].name != "title" && line[i].id >= 10) {
			fileout << line[i].id << "|" << line[i].name << "|" << line[i].date << "|" << line[i].location << "|\n";
		}
	}
}

void Reading(event line[]) {
	event temp;
	int stop;
	ifstream filein;
	string string, id, name, date, location;
	filein.open("FOOD.txt");
	if (!filein.is_open()) {
		cout << "‘айл дл€ записи данных не существует" ;
	}
	else {
		while (!filein.eof())
		{
			string = "";
			location = "";
			getline(filein, string);
			id = "";
			name = "";
			date = ""; 
			if (string == "")
				break;
			for (int i = 0; i <= 1; i++)
			{
				
				if (string[i] != ' ') {
					id += string[i];
				}
			}
			temp.id = atoi(id.c_str());
			for (int i = 3; i <= 50; i++)
			{
				if (string[i] != '|') {
					name += string[i];
				}
				else if (string[i] == '|') {
					stop = i;
					break;
				}
			}
			temp.name = name;
			for (int i = stop + 1; i < 100; i++)
			{
				if (string[i] != '|') {
					date += string[i];
				}
				else if (string[i] == '|') {
					stop = i;
					break;
				}
			}
			temp.date = date;
			for (int i = stop + 1; i < 100; i++)
			{
				if (string[i] != '|') {
					location += string[i];
				}
				else if (string[i] == '|') {
					stop = i;
					break;
				}
			}
			temp.location = location;
			line[temp.id] = temp;

		}
	}
	filein.close();
}

void Editing(event line[]) {
	int wish;
	event temp;
	string location, date, name;
	string year, day, month;
	int format, id;
	cout << "¬ведите ID меропри€ти€ ";
	cin >> id;
	while (line[id].name == "title") {
		cout << "меропри€тие не существует";
		cin >> id;
	}
	temp = line[id];
	
	cout << "¬ыберите поле дл€ редактировани€" << endl;
	cout << "1.название" << endl;
	cout << "2.место проведени€" << endl;
	cout << "3.дата меропри€ти€" << endl;
	cin >> wish;
	while (wish < 1 || wish>3) {
		cout << "‘ункци€ не существует. ¬вуедите снова";
		cin >> wish;
	}
	switch (wish)
	{
	case 1:
		cout << "введите новое название" << endl;
		getline(cin, name);
		temp.name = name;
		break;
	case 2:
		cout << "введите новое место проведени€" << endl;
		cin.ignore();
		getline(cin, location);
		temp.location = location;
		break;
	case 3:
		cout << endl << "¬ведите дату меропри€ти€ в форматах: ";

		cout << endl << "1. YYYY.MM.DD. \n2. DD.MM.YYYY \n3. MM.DD.YYYY \n";
		cin >> format;
		while (format < 1 && format>3) {
			cout << endl << "1. YYYY.MM.DD. \n2. DD.MM.YYYY \n3. MM.DD.YYYY \n";
			cin >> format;
		}
		switch (format)
		{
		case 1:
			cout << "введите год: "; cin >> year; cout << endl;
			cout << "введите мес€ц: "; cin >> month; cout << endl;
			cout << "введите день: "; cin >> day; cout << endl;

			if (!ifLeapYear(atoi(year.c_str())) && atoi(day.c_str()) == 29 && atoi(month.c_str()) == 2) {
				cout << "даты не существует";
				break;
			}
			else {
				date += year;
				date += '.';
				date += month;
				date += '.';
				date += day;
				date += '.';
				break;
			}
		case 2:
			cout << "введите день: "; cin >> day; cout << endl;
			cout << "введите мес€ц: "; cin >> month; cout << endl;
			cout << "введите год: "; cin >> year; cout << endl;
			if (!ifLeapYear(atoi(year.c_str())) && atoi(day.c_str()) == 29 && atoi(month.c_str()) == 2) {
				cout << "даты не существует";
				break;
			}
			else {
				date += day;
				date += '.';
				date += month;
				date += '.';
				date += year;
				break;
			}
		case 3:
			cout << "введите мес€ц: "; cin >> month; cout << endl;
			cout << "введите день: "; cin >> day; cout << endl;
			cout << "введите год: "; cin >> year; cout << endl;
			if (!ifLeapYear(atoi(year.c_str())) && atoi(day.c_str()) == 29 && atoi(month.c_str()) == 2) {
				cout << "даты не существует";
				break;
			}
			else {
				date += month;
				date += '.';
				date += day;
				date += '.';
				date += year;
				break;
			}
		default:
			cout << "‘ункци€ не существует";
			break;
		}
		temp.date = date;
		break;
	default:
		system("cls");
		cout << "несуществующа€ операци€";
		Sleep(1500);
		break;
	}

	line[temp.id] = temp;

	cout << "меропри€тие " << name << " успешно редактировано";
}

void Add(event line[]) {
	string name, date, location;
	string year, day, month;
	event temp;
	bool execution;
	int format;
	cout << "¬ведите название меропри€ти€: ";
	cin.ignore();
	getline(cin, name);
	cout << endl << "¬ведите дату меропри€ти€ в форматах: ";

	cout << endl << "1. YYYY.MM.DD. \n2. DD.MM.YYYY \n3. MM.DD.YYYY \n";
	cin >> format;
	while (format<1&&format>3) {
		cout << endl << "1. YYYY.MM.DD. \n2. DD.MM.YYYY \n3. MM.DD.YYYY \n";
		cin >> format;
	}
	switch (format)
	{
	case 1:
		cout << "введите год: "; cin >> year; cout << endl;
		cout << "введите мес€ц: "; cin >> month; cout << endl;
		cout << "введите день: "; cin >> day; cout << endl;

		while (!ifLeapYear(atoi(year.c_str())) && atoi(day.c_str()) == 29 && atoi(month.c_str()) == 2) {
			cout << "даты не существует"<<endl;
			cout << "введите год: "; cin >> year; cout << endl;
			cout << "введите мес€ц: "; cin >> month; cout << endl;
			cout << "введите день: "; cin >> day; cout << endl;
		}
		
			date += year;
			date += '.';
			date += month;
			date += '.';
			date += day;
			date += '.';
			break;
		
	case 2:
		cout << "введите день: "; cin >> day; cout << endl;
		cout << "введите мес€ц: "; cin >> month; cout << endl;
		cout << "введите год: "; cin >> year; cout << endl;
		if (!ifLeapYear(atoi(year.c_str())) && atoi(day.c_str()) == 29 && atoi(month.c_str()) == 2) {
			cout << "даты не существует";
			break;
		}
		else {
			date += day;
			date += '.';
			date += month;
			date += '.';
			date += year;
			break;
		}
	case 3:
		cout << "введите мес€ц: "; cin >> month; cout << endl;
		cout << "введите день: "; cin >> day; cout << endl;
		cout << "введите год: "; cin >> year; cout << endl;

		if (!ifLeapYear(atoi(year.c_str())) && atoi(day.c_str()) == 29 && atoi(month.c_str()) == 2) {
			cout << "даты не существует";
			break;
		}
		else {
			date += month;
			date += '.';
			date += day;
			date += '.';
			date += year;
			break;
		}
	default:
		cout << "‘ункци€ не существует";
		break;
		}
	cin.ignore();
	cout << endl << "¬ведите место меропри€ти€: ";
	getline(cin, location);

		for (int i = 0; i < 50; i++)
		{
			if (line[i].name == "title") {
				temp = event(i, name, date, location);
				line[i] = temp;
				cout << "меропри€тие '" << line[i].name << "' успешно сохранено";
				break;
			}
		}

	}

void Delete(event line[]) {
	string name;
	int id;
	cout << "¬ведите ID меропри€ти€ ";
	cin >> id;
	while (line[id].name == "title") {
		cout << "меропри€тие не существует";
		cin >> id;
	}

			line[id].id = 0;
			line[id].name = "title";
			line[id].location = "russia";
			line[id].date = "today";
			cout << "меропри€тие " << name << " успешно удалено";
}