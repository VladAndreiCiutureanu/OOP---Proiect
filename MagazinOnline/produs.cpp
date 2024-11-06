#include "produs.h"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <fstream>
const char* spatii =" \t\n";
Produs::Produs() {
	this->nume = "";
	this->categorie = "";
	this->descriere = "";
	this->pret = 0.0;
}

Produs::Produs(string nume, string categorie, string descriere, double pret) {
	this->nume = nume;
	this->categorie = categorie;
	this->descriere = descriere;
	this->pret = pret;
}
ostream& operator<<(ostream& os, Produs& p) {
	os << left << setw(30) << p.nume <<"|" << left << setw(30) << p.categorie << "|" << left << setw(30) << left << setw(30) << p.descriere<<"|" << fixed << setprecision(2) << p.pret << endl;
	return os;
}
istream& operator>>(istream& is, Produs& p) {
	string linie;
	getline(is, linie);
	stringstream ss(linie);
	getline(ss, p.nume, '|');
	p.nume = eliminaSpatii(p.nume);
	getline(ss, p.categorie, '|');
	p.categorie = eliminaSpatii(p.categorie);
	getline(ss, p.descriere, '|');
	p.descriere = eliminaSpatii(p.descriere);
	string pret;
	getline(ss, pret, '|');
	p.pret = stod(pret);
	return is;
}
string eliminaSpatii(string s) {
	s.erase(s.find_last_not_of(spatii) + 1);
	return s;
}