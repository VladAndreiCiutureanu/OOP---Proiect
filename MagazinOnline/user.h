#ifndef USER_H
#define USER_H
#include "store.h"
#include <vector>
#include <iostream>
class User
{
public:
	void getOrder(std::vector<Product*>&inventory);
	std::vector<Product*> getOrderList() { return order; }
	bool isAdminUser() { return isAdmin; }
	void setAdmin(bool isAdmin) { this->isAdmin = isAdmin; }
	~User();
private:
	std::vector<Product*> order;
protected:
	bool isAdmin = false;
};
#endif
