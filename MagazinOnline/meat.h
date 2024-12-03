#ifndef MEATS_H
#define MEATS_H
#include "perishableproduct.h"
class Meat :
    public PerishableProduct
{
public:
	Meat(std::string name = "none", std::string description = "none", std::string category = "Mezeluri", double price = 0.0, int quantity = 0, std::string expiryDate = "none");
};
#endif
