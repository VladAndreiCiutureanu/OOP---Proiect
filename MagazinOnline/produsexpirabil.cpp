#include <iomanip>
#include <sstream>
#include "produsexpirabil.h"
ProdusExpirabil::ProdusExpirabil() :
	ProdusVanzare() {
	this->dataDeExpirare = "";
}
ProdusExpirabil::ProdusExpirabil(string nume, string categorie, string descriere, double pret, int cantitate, string dataDeExpirare) :
	ProdusVanzare(nume, categorie, descriere, pret, cantitate) {
	this->dataDeExpirare = dataDeExpirare;
}
ostream& operator<<(ostream&os, ProdusExpirabil&p) {
	os << left << setw(20) << p.primesteNume() << "|" << left << setw(20) << p.primesteCategorie() << "|" << left << setw(30) << left << setw(110) << p.primesteDescriere() << "|" << left << setw(10) << fixed << setprecision(2) << p.primestePret() << "|" << left << setw(10) << p.primesteCantitate() << "|" << left << setw(30)<<p.primesteDataDeExpirare() << endl;
	return os;
}
istream& operator>>(istream& is, ProdusExpirabil& p) {
	string linie, nume, categorie, descriere, cantitate, dataDeExpirare;
	getline(is, linie);
	stringstream ss(linie);
	getline(ss, nume, '|');
	nume = eliminaSpatii(nume);
	p.seteazaNume(nume);
	getline(ss, categorie, '|');
	categorie = eliminaSpatii(categorie);
	p.seteazaCategorie(categorie);
	getline(ss, descriere, '|');
	descriere = eliminaSpatii(descriere);
	p.seteazaDescriere(descriere);
	string pret;
	getline(ss, pret, '|');
	pret = eliminaSpatii(pret);
	p.seteazaPret(stod(pret));
	getline(ss, cantitate, '|');
	cantitate = eliminaSpatii(cantitate);
	p.seteazaCantitate(stoi(cantitate));
	getline(ss, dataDeExpirare, '|');
	dataDeExpirare = eliminaSpatii(dataDeExpirare);
	p.seteazaDataDeExpirare(dataDeExpirare);
	return is;
}