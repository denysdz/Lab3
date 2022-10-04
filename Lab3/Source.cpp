#include <iostream>
#include <string>
#include "Osoba.h"
#include "List.h"

using namespace std;

bool isNumber(const string& str);

int main() {

	int count = 0;
	cout << "Number of person" << endl;
	try {
		cin >> count;
		if (count <= 0) throw "Number of person must be > 0";
		else {
			List l = List(count);
			l.fillList();
			l.ShowAll();
			cout << "Enter data to find person by FIO, BIRTHDAY" << endl;
			char* tmp = new char[256];
			cin >> tmp;
			l.findBy(tmp);
			cout << "Enter data to find person by SEX (1/2)" << endl;
			int sex;
			cin >> sex;
			l.findBy(sex);
		}
	} catch (const char* err) {
		cout << err << endl;
	}
	system("pause");
	return 0;
}

bool isNumber(const string& str)
{
	for (char const& c : str) {
		if (isdigit(c) == 0) return false;
	}
	return true;
}