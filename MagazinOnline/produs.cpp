#include "produs.h"
#include <iomanip>
#include <sstream>
#include <iostream>
Produs::Produs() {
	this->name = "";
	this->category = "";
	this->description = "";
	this->price = 0.0;
}

Produs::Produs(string name, string category, string description, double price) {
	this->name = name;
	this->category = category;
	this->description = description;
	this->price = price;
}

ostream& operator<<(ostream& os, Produs& p) {
	cout << left << setw(30) << p.name <<"|" << left << setw(30) << p.category << left << setw(30) << left << setw(30) << p.description << fixed << setprecision(2) << p.price << endl;
	return os;
}