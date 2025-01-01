#include "product.h"
Product::Product(std::string name, std::string description, std::string category, double price, int quantity)
	: name(name), description(description), category(category), price(price), quantity(quantity)
{	
}
std::ostream& operator<<(std::ostream& out, const Product& product)
{
	product.print(out);
	return out;
}
std::istream& operator>>(std::istream& in, Product& product)
{
	product.read(in);
	return in;
}
void Product::print(std::ostream& out) const
{
	out << std::left << std::setw(20) << name << "|" << std::left << std::setw(20) << category << "|" << std::left << std::setw(110) << description << "|" << std::left << std::setw(10) << std::fixed << std::setprecision(2) <<price << "|" << std::left << std::setw(10) << quantity << std::endl;
}
void Product::read(std::istream& in)
{
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
}