#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
class Gun
{
protected:
	string description;

public:
	virtual string getDescr() {
		return description;
	}
	virtual int ammoInNeedCount() = 0;
	virtual int loadetammoCount() = 0;
	virtual int ammoCount() = 0;
	~Gun() {}
};



class Revolver : public Gun
{
public:
	Revolver() {
		description = "Revolver, 9mm, Modules:";
	}
	int ammoInNeedCount() {
		return 6;
	}
	int loadetammoCount() {
		return 0;
	}
	int ammoCount() {
		return 0;
	}
};

class Rifle : public Gun
{
public:
	Rifle() {
		description = "Ak47, 7.62mm, Modules:";
	}
	int ammoInNeedCount() {
		return 30;
	}
	int loadetammoCount() {
		return 0;
	}
	int ammoCount() {
		return 0;
	}
};


class setSuppressor : public Gun
{
private:
	Gun* gun;
public:
	setSuppressor(Gun* g) {
		gun = g;
	}
	string getDescr() {
		return gun->getDescr() + "\nSuppressor";
	}
	int ammoInNeedCount() {
		return gun->ammoInNeedCount();
	}
	int loadetammoCount() {
		return gun->loadetammoCount();
	}
	int ammoCount() {
		return gun->ammoCount();
	}
};


class setScope : public Gun
{
private:
	Gun* gun;
public:
	setScope(Gun* g) {
		gun = g;
	}
	string getDescr() {
		return gun->getDescr() + "\nScope";
	}
	int ammoInNeedCount() {
		return gun->ammoInNeedCount();
	}
	int loadetammoCount() {
		return gun->loadetammoCount();
	}
	int ammoCount() {
		return gun->ammoCount();
	}
};


class setGrip : public Gun
{
private:
	Gun* gun;
public:
	setGrip(Gun* g) {
		gun = g;
	}
	string getDescr() {
		return gun->getDescr() + "\nGrip";
	}
	int ammoInNeedCount() {
		return gun->ammoInNeedCount();
	}
	int loadetammoCount() {
		return gun->loadetammoCount();
	}
	int ammoCount() {
		return gun->ammoCount();
	}
};

class getAmmo : public Gun
{
private:
	Gun* gun;
	int buf;
public:
	getAmmo(Gun* g, int ammount) {
		gun = g;
		buf = ammount;
	}
	string getDescr() {
		return gun->getDescr() ;
	}
	int ammoInNeedCount() {
		return gun->ammoInNeedCount();
	}
	int loadetammoCount() {
		return gun->loadetammoCount();
	}
	int ammoCount() {
		return gun->ammoCount() + buf;
	}
};


class loadAmmo : public Gun
{
private:
	Gun* gun;
	int minus = 0;
	int minus1 = 0;
public:
	loadAmmo(Gun* g) {
		gun = g;
		if ((gun->ammoInNeedCount() - gun->loadetammoCount()) <= gun->ammoCount()) {
			minus = gun->ammoInNeedCount() - gun->loadetammoCount();
			minus1 = minus;
		}
		else {
			minus = ammoCount();
			minus1 = gun->ammoCount();
		}
	}
	string getDescr() {
		return gun->getDescr();
	}
	int ammoInNeedCount() {
		return gun->ammoInNeedCount();
	}
	int ammoCount() {
		return gun->ammoCount() - minus;
	}
	int loadetammoCount() {
		return gun->loadetammoCount() + minus1;
	}
};
