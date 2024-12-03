#ifndef PASTRY_H
#define PASTRY_H
#include "perishableproduct.h"
class Pastry :
    public PerishableProduct
{
public:
	Pastry(std::string name = "none", std::string description = "none", std::string category = "Patiserie", double price = 0.0, int quantity = 0, std::string expiryDate = "none");
};
#endif

