#include "perishableproduct.h"
PerishableProduct::PerishableProduct(std::string name, std::string description, std::string category, double price, int quantity, std::string expiryDate)
	: Product(name, description, category, price, quantity), expiryDate(expiryDate)
{
}
PerishableProduct::PerishableProduct(Product p)
	: Product(p), expiryDate("none")
{
}
void PerishableProduct::print(std::ostream& out) const
{
	out << std::left << std::setw(20) << getName() << "|" << std::left << std::setw(20) << getCategory() << "|" << std::left << std::setw(110) << getDescription() << "|" << std::left << std::setw(10) << std::fixed << std::setprecision(2) << getPrice() << "|" << std::left << std::setw(10) << getQuantity() << "|" << std::left << std::setw(10) << expiryDate << std::endl;
}
void PerishableProduct::read(std::istream& in) {
	std::string line;
	std::getline(in, line);
	std::vector<std::string> tokens;
	boost::split(tokens, line, boost::is_any_of("|"));
	for (auto& token : tokens)
	{
		boost::trim(token);
	}
	setName(tokens.at(0));
	setCategory(tokens.at(1));
	setDescription(tokens.at(2));
	setPrice(std::stod(tokens.at(3)));
	setQuantity(std::stoi(tokens.at(4)));
	setExpiryDate(tokens.at(5));
}