#include "store.h"
void Store::readInventory()
{
	std::ifstream fin("inventar.txt");
	std::string line;
	while (getline(fin, line)) {
		std::stringstream ss(line);
		if (std::count(line.begin(), line.end(), '|') == 4) {
			Product p;
			ss >> p;
			Product* t = new Product(p);
			inventory.emplace_back(t);
		}
		else {
			PerishableProduct p;
			ss >> p;
			Product* t = new PerishableProduct(p);
			inventory.emplace_back(t);
		}
	}
}
void Store::test()
{
	Cheese c;
	std::cout << c;
	Croissant cr;
	std::cout << cr;
	Eclair e;
	std::cout << e;
	Fridge f;
	std::cout << f;
	Ham h;
	std::cout << h;
	Hammer ha;
	std::cout << ha;
	Hoover ho;
	std::cout << ho;
	Milk m;
	std::cout << m;
	Oven o;
	std::cout << o;
	Pickaxe p;
	std::cout << p;
	Salami s;
	std::cout << s;
	Sausage sa;
	std::cout << sa;
	Shovel sh;
	std::cout << sh;
	Strudel st;
	std::cout << st;
	WashingMachine w;
	std::cout << w;
	Yogurt y;
	std::cout << y;
}
void Store::displayInventory() {
	for (auto element : inventory) {
		std::cout << *element;
	}
}
Store::~Store()
{
	for (auto& element : inventory) {
		delete element;
	}
}