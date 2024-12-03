#include "pastry.h"
Pastry::Pastry(std::string name, std::string description, std::string category, double price, int quantity, std::string expiryDate) :
	PerishableProduct(name, description, category, price, quantity, expiryDate)
{
}