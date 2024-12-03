#include "product.h"
Product::Product(std::string name, std::string description, std::string category, double price, int quantity)
	: name(name), description(description), category(category), price(price), quantity(quantity)
{	
}
std::ostream& operator<<(std::ostream& out, const Product& product)
{
	out << std::left << std::setw(20) << product.name << "|" << std::left << std::setw(20) << product.category << "|" << std::left << std::setw(110) << product.description << "|" << std::left << std::setw(10) << std::fixed<< std::setprecision(2) << product.price << "|" << std::left << std::setw(10) << product.quantity << std::endl;
	return out;
}
std::istream& operator>>(std::istream& in, Product& product)
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
	return in;
}