#ifndef HOUSEHOLDAPPLIANCES_H
#define HOUSEHOLDAPPLIANCES_H
#include "product.h"
class HouseholdAppliances :
    public Product
{
public:
	HouseholdAppliances(std::string name = "none", std::string description = "none", std::string category = "Household Appliances", double price = 0.0, int quantity = 0);
};
#endif
