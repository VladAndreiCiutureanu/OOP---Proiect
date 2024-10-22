#include <string>
using namespace std;
#ifndef PRODUS_H
#define PRODUS_H
class Produs
{
public:
	Produs();
	Produs(string, string, string, double);
	friend ostream& operator<<(ostream& os, Produs& p);
private:
	string name;
	string category;
	string description;
	double price;
};
#endif

