#ifndef STORE_H
#define STORE_H
#include "perishableproduct.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
class Store
{
public:
	void readInventory();
	void displayInventory();
	~Store();
	bool addProduct(Product* p);
	bool removeProduct(std::string name);
	bool checkExpiryDate();
private:
	std::vector<Product*> inventory;
	bool updateFile();
};
#endif
