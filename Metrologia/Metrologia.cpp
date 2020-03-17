#include <iostream>
#include "event.h"
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include "Functions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	event line[50];
	
	bool executing = true;
	int  wish, operation;

	cout << "+++++++========Добро пожаловать в ПРИЛОЖЕНИЕ ДЛЯ ПОИСКА БЕСПЛАТНОЙ ЕДЫ=========+++++++";
	Sleep(1500);
	system("cls");
	cout << "Загрузка данных в оперативную память..." << endl;;
	Reading(line);
	Sleep(3000);
	system("cls");
	cout << "Данные загружены в оперативную память";
	Sleep(1500);
	system("cls");
	while (executing) {

		cout << endl << "Выберите операцию:" << endl;
		cout << "1.Добавить мероприятие" << endl;
		cout << "2.Удаление мероприятия." << endl;
		cout << "3.Показать все мероприятия" << endl;
		cout << "4.Сохранить мероприятия на diskette" << endl;
		cout << "5.Редактирование мероприятия." << endl;
		cout << "6.Информация о проекте." << endl;
		cout << "0.Выход." << endl;
		cout << endl << "Введите номер операции: << ";
		cin >> operation;

		switch (operation)
		{

		case 1:
			system("cls");
			Add(line);
			break;
		case 2:
			system("cls");
			Print(line);
			Delete(line);
			break;
		case 3:
			system("cls");
			cout << endl;
			Print(line);
			break;
		case 4:
			system("cls");
			Save(line);
			break;
		case 5:
			system("cls");
			Print(line);
			Editing(line);
			break;
		case 6:
			system("cls");
			cout << "Информация о проекте: приложение создано в учебных целях в рамках курса по МЕТРОЛОГИИ ПО. Не несет в себе никакой информации, связанной с реальностью.";
			cout << endl << "дата: 16.03.2020";
			cout << endl << "автор: Тимофей Борисов";
			cout << endl << "v.1.3";
			cout << endl << "почта: 10115 Pflugstr 9";
			break;

		case 0:
			executing = false;
			break;
		default:
			system("cls");
			cout << "несуществующая операция";
			Sleep(1500);
			break;
		}
	}
}
