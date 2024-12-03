#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <iomanip>
class Product
{
public:
	Product(std::string name = "none", std::string description = "none", std::string category = "none", double price = 0.0, int quantity = 0);
	void setName(std::string name) { this->name = name; }
	void setDescription(std::string description) { this->description = description; }
	void setCategory(std::string category) { this->category = category; }
	void setPrice(double price) { this->price = price; }
	void setQuantity(int quantity) { this->quantity = quantity; }
	std::string getName() const { return name; }
	std::string getDescription() const { return description; }
	std::string getCategory() const { return category; }
	double getPrice() const { return price; }
	int getQuantity() const { return quantity; }
	friend std::istream& operator>>(std::istream& in, Product& product);
	friend std::ostream& operator<<(std::ostream& out, const Product& product);
private:
	std::string name;
	std::string description;
	std::string category;
	double price;
	int quantity;

};
#endif

