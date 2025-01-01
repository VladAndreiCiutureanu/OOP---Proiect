#include "store.h"
void Store::readInventory()
{
	std::ifstream file("inventar.txt");
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		if (std::count(line.begin(), line.end(), '|') == 4)
		{
			Product* p = new Product();
			ss >> *p;
			inventory.push_back(p);
		}
		else
		{
			PerishableProduct* pp = new PerishableProduct();
			ss >> *pp;
			inventory.push_back(pp);
		}
	}
}
void Store::displayInventory() {
	for (auto& product : inventory) {
		std::cout << *product;
	}
}
Store::~Store() {
	std::ofstream file("inventar.txt");
	updateFile();
	for (auto& product : inventory) {
		delete product;
	}
}
bool Store::addProduct(Product* p) {
	for (auto& product : inventory) {
		if (product->getName() == p->getName()) {
			std::cout << "Produsul exista deja in inventar\n";
			return false;
		}
	}
	inventory.push_back(p);
	return true;
}
bool Store::updateFile() {
	std::ofstream file("inventar.txt");
	if (!file.is_open()) {
		std::cout << "Eroare la deschiderea fisierului\n";
		return false;
	}
	for (auto& product : inventory) {
		file << *product;
	}
	file.close();
	return true;
}

bool Store::removeProduct(std::string name) {
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory.at(i)->getName() == name) {
			inventory.erase(inventory.begin() + i);
			return true;
		}
	}
	return false;
}
