#include <string>
using namespace std;
#ifndef PRODUS_H
#define PRODUS_H
class Produs
{
public:
	Produs();
	Produs(string, string, string, double);
	friend ostream& operator<<(ostream& , Produs& );
	friend istream& operator>>(istream& , Produs& );
	void seteazaPret(double pret) { this->pret = pret; }
	void seteazaNume(string nume) { this->nume = nume; }
	void seteazaCategorie(string categorie) { this->categorie = categorie; }
	void seteazaDescriere(string descriere) { this->descriere = descriere; }
	string primesteNume() { return nume; }
	string primesteCategorie() { return categorie; }
	string primesteDescriere() { return descriere; }
	double primestePret() { return pret; }
private:
	string nume;
	string categorie;
	string descriere;
	double pret;
};
string eliminaSpatii(string);
#endif

