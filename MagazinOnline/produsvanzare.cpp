#include <iomanip>
#include <sstream>
#include "produsvanzare.h"
using namespace std;
ProdusVanzare::ProdusVanzare() {
	this->produs = Produs();
	this->cantitate = 0;
}
ProdusVanzare::ProdusVanzare(string nume, string categorie, string descriere,double pret, int cantitate){
	this->produs = Produs(nume, categorie, descriere, pret);
	this->cantitate = cantitate;
}
ostream& operator<<(ostream& os, ProdusVanzare& p) {
	os << left << setw(30) << p.produs.primesteNume()<< "|" << left << setw(30) << p.produs.primesteCategorie() << "|" << left << setw(30) << left << setw(30) << p.produs.primesteDescriere() << "|" <<fixed << setprecision(2) << p.produs.primestePret()<<"|"<<left<<setw(10)<<p.cantitate<< endl;
	return os;
}
istream& operator>>(istream& is, ProdusVanzare& p) {
	string linie,nume,categorie, descriere, cantitate;
	getline(is, linie);
	stringstream ss(linie);
	getline(ss, nume, '|');
	nume = eliminaSpatii(nume);
	p.produs.seteazaNume(nume);
	getline(ss, categorie, '|');
	categorie = eliminaSpatii(categorie);
	p.produs.seteazaCategorie(categorie);
	getline(ss, descriere, '|');
	descriere = eliminaSpatii(descriere);
	p.produs.seteazaDescriere(descriere);
	string pret;
	getline(ss, pret, '|');
	pret = eliminaSpatii(pret);
	p.produs.seteazaPret(stod(pret));
	getline(ss, cantitate, ' ');
	cantitate = eliminaSpatii(cantitate);
	p.cantitate = stoi(cantitate);
	return is;
}