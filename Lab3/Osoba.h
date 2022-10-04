#pragma once
#include "iostream"

using namespace std;

class Osoba {
protected:
	char* fio;
	int sex;
	char* birthday;
public:
	Osoba(void);
	~Osoba(void);
	void setFio(const char* name);
	void setSex(int value);
	void setBirthDay(const char* date);
	char* getFio();
	int getSex();
	char* getBirthDay();
	friend ostream& operator<< (ostream& out, const Osoba& osoba);
	friend istream& operator>> (istream& in, Osoba& osoba);
};


