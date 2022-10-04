#include "Osoba.h"
#include <iostream>
#include <Windows.h>
#include "string"

using namespace std;

Osoba::Osoba() {
	setFio("Unknown");
	setSex(1);
	setBirthDay("Unknown");
}

char* Osoba::getFio() {
	return fio;
}

int Osoba::getSex() {
	return sex;
}

char* Osoba::getBirthDay() {
	return birthday;
}

void Osoba::setFio(const char* f) {
	fio = new char[strlen(f) + 1];
	strcpy(fio, f);
}

void Osoba::setSex(int value) {
	sex = value;
}

void Osoba::setBirthDay(const char* b) {
	birthday = new char[strlen(b) + 1];
	strcpy(birthday, b);
}

ostream& operator<< (ostream& out, const Osoba& osoba)
{
	out << "Results: " << endl;
	string s = "";
	switch (osoba.sex) {
		case 1:
			s = "Male";
			break;
		case 2:
			s = "Female";
			break;
	}
	out << "FIO: " << osoba.fio << "; SEX: " << s << "; BIRTHDAY: " << osoba.birthday << endl;
	return out;
}

istream& operator>> (istream& in, Osoba& osoba)
{
	char* tmp = new char[256];
	int sex = 1;
	string line;
	cout << "Enter FIO: " << "\n";
	in.ignore();
	in.getline(tmp, 256);
	osoba.setFio(tmp);
	cout << "Enter SEX male : female (1/2): " << "\n";
	try {
		char iv;
		in >> iv;
		if (isdigit(iv)) {
			int i = iv - 48;
			if (i >= 1 && i <= 2) {
				osoba.setSex(i);
			}
			else {
				throw "Only 1/2";
			}
		}
		else {
			throw "Only numbers";
		}
	}
	catch (char* numerr) {
		cout << numerr << endl;
	}
	cout << "Enter BIRTHDAY: " << "\n";
	in >> tmp;
	osoba.setBirthDay(tmp);
	return in;
}


Osoba::~Osoba() {
	delete[] fio;
	delete[] birthday;
}