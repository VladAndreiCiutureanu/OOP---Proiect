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
	Store();
	void readInventory();
	void displayInventory();
	~Store();
	bool addProduct(Product* p);
	bool removeProduct(std::string name);
	void removeExpiredProducts();
	void generateOffer();
	void generatePromotion();
	double getOrderPrice(std::vector<Product*> order);
	std::vector<Product*>& getInventory() { return inventory; }
	void printWarnings();
	void removeUnavailableProducts();
	void restock(std::string name, int newQuantity);
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
