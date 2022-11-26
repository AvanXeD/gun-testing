#include "data.h"
#include <stdlib.h>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Gun* rifle;
	char buf;
	do {
		cout << endl << "1 - Револьвер" << endl << "2 - Ак47" << endl << "Виберіть тип пушки: ";
		cin >> buf;
	} while ((buf != '1') && (buf != '2'));
	switch (buf)
	{
	case('1'):
		rifle = new Revolver();
		break;

	default:
		rifle = new Rifle();
		break;
	}
	system("cls");
	cout << endl << rifle->getDescr() << endl;
	cout << endl << "Виберіть модуль:" << endl << "1 - Suppressor" << endl << "2 - Scope" << endl << "3 - Grip" << endl << "4 - Пропустити" << endl << "Ваш вибір: ";		cin >> buf;
	switch (buf) {
	case('1'):
		system("cls");
		rifle = new setSuppressor(rifle);
		cout << endl << rifle->getDescr() << endl;
		cout << endl << "Виберіть модуль:" << endl << "1 - Scope" << endl << "2 - Grip" << endl << "3 - Пропустити" << endl << "Ваш вибір: ";
		cin >> buf;
		switch (buf) {
		case('1'):
			system("cls");
			rifle = new setScope(rifle);
			cout << endl << rifle->getDescr() << endl;
			cout << endl << "Виберіть модуль:" << endl << "1 - Grip" << endl << "2 - Пропустити" << endl << "Ваш вибір: ";
			cin >> buf;
			switch (buf) {
			case('1'):
				rifle = new setGrip(rifle);
			break;
			default:
			break;
			}
		break;
		case('2'):
			rifle = new setGrip(rifle);
			system("cls");
			cout << endl << rifle->getDescr() << endl;
			cout << endl << "Виберіть модуль:" << endl << "1 - Scope" << endl << "2 - Пропустити" << endl << "Ваш вибір: ";
			cin >> buf;
			switch (buf) {
			case('1'):
				rifle = new setScope(rifle);
				break;
			default:
				break;
			}
		break;
		default:
		break;
		}
	break;
	
	case('2'):
		system("cls");
		rifle = new setScope(rifle);
		cout << endl << rifle->getDescr() << endl;
		cout << endl << "Виберіть модуль:" << endl << "1 - Suppressor" << endl << "2 - Grip" << endl << "3 - Пропустити" << endl << "Ваш вибір: ";
		cin >> buf;
		switch (buf) {
		case('1'):
			system("cls");
			rifle = new setSuppressor(rifle);
			cout << endl << rifle->getDescr() << endl;
			cout << endl << "Виберіть модуль:" << endl << "1 - Grip" << endl << "2 - Пропустити" << endl << "Ваш вибір: ";
			cin >> buf;
			switch (buf) {
			case('1'):
				rifle = new setGrip(rifle);
				break;
			default:
				break;
			}
			break;
		case('2'):
			system("cls");
			rifle = new setGrip(rifle);
			cout << endl << rifle->getDescr() << endl;
			cout << endl << "Виберіть модуль:" << endl << "1 - Suppressor" << endl << "2 - Пропустити" << endl << "Ваш вибір: ";
			cin >> buf;
			switch (buf) {
			case('1'):
				rifle = new setSuppressor(rifle);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
		
	case('3'):
		system("cls");
		rifle = new setGrip(rifle);
		cout << endl << rifle->getDescr() << endl;
		cout << endl << "Виберіть модуль:" << endl << "1 - Suppressor" << endl << "2 - Scope" << endl << "3 - Пропустити" << endl << "Ваш вибір: ";
		cin >> buf;
		switch (buf) {
		case('1'):
			system("cls");
			rifle = new setSuppressor(rifle);
			cout << endl << rifle->getDescr() << endl;
			cout << endl << "Виберіть модуль:" << endl << "1 - Scope" << endl << "2 - Пропустити" << endl << "Ваш вибір: ";
			cin >> buf;
			switch (buf) {
			case('1'):
				rifle = new setScope(rifle);
				break;
			default:
				break;
			}
			break;
		case('2'):
			system("cls");
			rifle = new setScope(rifle);
			cout << endl << rifle->getDescr() << endl;
			cout << endl << "Виберіть модуль:" << endl << "1 - Suppressor" << endl << "2 - Пропустити" << endl << "Ваш вибір: ";
			cin >> buf;
			switch (buf) {
			case('1'):
				rifle = new setSuppressor(rifle);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
		
	default:
		break;
	}

	do {
		system("cls");
		cout << endl << rifle->getDescr() << endl << rifle->loadetammoCount() << "|" << rifle->ammoInNeedCount() << " аммуніції" << endl << rifle->ammoCount() << " - всього аммуніції" << endl;
		cout << endl << "1 - Додати амуніцію " << endl << "2 - Перезарядити" << endl << "3 - Вийти" << endl << "Ваш вибір: ";
		cin >> buf;
		int ammoToAdd;
		switch (buf) {
		case('1'):
			cout << endl << "Введіть кількість аммуніції: ";
			cin >> ammoToAdd;
			rifle = new getAmmo(rifle, ammoToAdd);
			break;
		case('2'):
			rifle = new loadAmmo(rifle);
			break;
		default:
			break;
		}

	} while (buf != '3');
return 1;
}
