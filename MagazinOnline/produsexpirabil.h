#include "produsvanzare.h"
#ifndef PRODUSEXPIRABIL_H
#define PRODUSEXPIRABIL_H
class ProdusExpirabil :
    public ProdusVanzare
{
public:
    ProdusExpirabil();
    ProdusExpirabil(string nume, string categorie, string descriere, double pret, int cantitate, string dataDeExpirare);
    string primesteDataDeExpirare() { return dataDeExpirare; }
    void seteazaDataDeExpirare(string dataDeExpirare) { this->dataDeExpirare = dataDeExpirare;}
    friend ostream& operator<<(ostream&, ProdusExpirabil&);
    friend istream& operator>>(istream&, ProdusExpirabil&);
private:
    string dataDeExpirare;
};
#endif

