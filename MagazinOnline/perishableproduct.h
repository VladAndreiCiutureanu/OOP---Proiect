#ifndef PERISHABLEPRODUCT_H
#define PERISHABLEPRODUCT_H
#include "product.h"
#include <string>
class PerishableProduct :
    public Product
{
public:
	PerishableProduct(std::string name = "none", std::string description = "none", std::string category = "none", double price = 0.0, int quantity = 0, std::string expiryDate = "none");
	PerishableProduct(Product p);
	std::string getExpiryDate() const { return expiryDate; }
	void setExpiryDate(std::string expiryDate) { this->expiryDate = expiryDate; }
	friend std::istream& operator>>(std::istream& in, PerishableProduct& product);
	friend std::ostream& operator<<(std::ostream& out, const PerishableProduct& product);
private:
	std::string expiryDate;
};
#endif

