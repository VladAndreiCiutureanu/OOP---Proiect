#include "produs.h"
using namespace std;
#ifndef PRODUSVANZARE_H
#define PRODUSVANZARE_H
class ProdusVanzare
{
public:
	ProdusVanzare();
	ProdusVanzare(string, string, string, double, int);
	void seteazaPret(double pret) { this->produs.seteazaPret(pret); }
	void seteazaNume(string nume) { this->produs.seteazaNume(nume); }
	void seteazaCategorie(string categorie) { this->produs.seteazaCategorie(categorie); }
	void seteazaDescriere(string descriere) { this->produs.seteazaDescriere(descriere); }
	void seteazaCantitate(int cantitate) { this->cantitate = cantitate; }
	string primesteNume() { return produs.primesteNume(); }
	string primesteCategorie() { return produs.primesteCategorie(); }
	string primesteDescriere() { return produs.primesteDescriere(); }
	int primesteCantitate() { return cantitate; }
	double primestePret() { return produs.primestePret(); }
	friend ostream& operator<<(ostream&, ProdusVanzare&);
	friend istream& operator>>(istream&, ProdusVanzare&);

private:
	Produs produs;
	int cantitate;
};
#endif