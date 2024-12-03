#ifndef DAIRY_H
#define DAIRY_H
#include "perishableproduct.h"
class Dairy :
    public PerishableProduct
{
public:
	Dairy(std::string name = "none", std::string description = "none", std::string category = "Lactate", double price = 0.0, int quantity = 0, std::string expiryDate = "none");
};
#endif

