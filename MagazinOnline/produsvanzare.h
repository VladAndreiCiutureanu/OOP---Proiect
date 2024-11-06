#include "produs.h"
using namespace std;
#ifndef PRODUSVANZARE_H
#define PRODUSVANZARE_H
class ProdusVanzare
{
public:
	ProdusVanzare();
	ProdusVanzare(string, string, string, double, int);
	friend ostream& operator<<(ostream&, ProdusVanzare&);
	friend istream& operator>>(istream&, ProdusVanzare&);
private:
	Produs produs;
	int cantitate;
};
#endif

