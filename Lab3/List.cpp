#include "List.h"

List::List(int count)
{
	this->listCount = count;
	osobs = new Osoba[count];
}

List::~List(void)
{
	delete[]osobs;
}
void List::fillList()
{
	for (int i = 0; i < listCount; i++)
	{
		cin >> osobs[i];
	}
}
void List::ShowAll()
{
	for (int i = 0; i < listCount; i++)
	{
		cout << osobs[i];
	}
}

void List::findBy(const char* value) {
	for (int i = 0; i < listCount; i++) {
		if ((strcmp(osobs[i].getFio(), value) == 0) || (strcmp(osobs[i].getBirthDay(), value) == 0)) {
			cout << osobs[i];
		}
	}
}

void List::findBy(int sex) {
	for (int i = 0; i < listCount; i++) {
		if (osobs[i].getSex() == sex) {
			cout << osobs[i];
		}
	}
}


