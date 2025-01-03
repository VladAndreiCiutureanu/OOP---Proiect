#ifndef STORE_H
#define STORE_H
#pragma warning(disable : 4996)
#include "perishableproduct.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <ctime>
class Store
{
public:
	void readInventory();
	void displayInventory();
	~Store();
	bool addProduct(Product* p);
	bool removeProduct(std::string name);
	void checkExpiryDate();
	void generateOffer();
	void generatePromotion();
	std::vector<Product*> getInventory() { return inventory; }
private:
	std::vector<Product*> inventory;
	std::vector<Product*> promotion;
	bool updateFile();
};
template<typename Base, typename T>
inline bool instanceof(const T* ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}
std::vector<int> getCurrentDate();
#endif
