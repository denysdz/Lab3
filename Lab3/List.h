#pragma once
#include "Osoba.h"
class List
{
protected:
	int listCount;
	Osoba* osobs;
public:
	List(int count);
	~List(void);
	void fillList();
	void ShowAll();
	void findBy(const char* value);
	void findBy(int sex);
};

