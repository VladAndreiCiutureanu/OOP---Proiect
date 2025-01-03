#ifndef USER_H
#define USER_H
#include "store.h"
#include <vector>
#include <iostream>
class User
{
public:
	User();
	void welcome();
	void getOrder();
	std::vector<Product*> getOrderList() { return order; }
private:
	std::vector<Product*> order;
	Store store;
};
#endif
