#ifndef USER_H
#define USER_H
#include "product.h"
#include <vector>
class User
{
public:
	void menu();
	bool validate();
	bool addItem(Product*);
private:
	std::vector<Product*> order;
};
#endif
