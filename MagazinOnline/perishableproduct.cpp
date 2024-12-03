#include "perishableproduct.h"
PerishableProduct::PerishableProduct(std::string name, std::string description, std::string category, double price, int quantity, std::string expiryDate)
	: Product(name, description, category, price, quantity), expiryDate(expiryDate)
{
}
std::ostream& operator<<(std::ostream& out, const PerishableProduct& product)
{
	out << std::left << std::setw(20) << product.getName() << "|" << std::left << std::setw(20) << product.getCategory() << "|" << std::left << std::setw(110) << product.getDescription() << "|" << std::left << std::setw(10) << std::fixed << std::setprecision(2) << product.getPrice() << "|" << std::left << std::setw(10) << product.getQuantity() << "|" << std::left << std::setw(30) << product.getExpiryDate() << std::endl;
	return out;
}
std::istream& operator>>(std::istream& in, PerishableProduct& product)
{
	std::string line;
	std::getline(in, line);
	std::vector<std::string> tokens;
	boost::split(tokens, line, boost::is_any_of("|"));
	for (auto& token : tokens)
	{
		boost::trim(token);
	}
	product.setName(tokens.at(0));
	product.setCategory(tokens.at(1));
	product.setDescription(tokens.at(2));
	product.setPrice(std::stod(tokens.at(3)));
	product.setQuantity(std::stoi(tokens.at(4)));
	product.setExpiryDate(tokens.at(5));
	return in;
}