#include "store.h"
void Store::readInventory()
{
	std::ifstream fin("inventar.txt");
	std::string line;
	while (getline(fin, line)) {
		std::stringstream ss(line);
		if (std::count(line.begin(), line.end(), '|') == 4) {
			Product* p =  new Product();
			ss >> *p;
			inventory.emplace_back(p);
		}
		else {
			PerishableProduct *p = new PerishableProduct();
			ss >> *p;
			p->setExpiryDate("1/1/2001");
			inventory.push_back(p);
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