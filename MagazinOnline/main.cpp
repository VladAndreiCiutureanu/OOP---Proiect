#include <iostream>
#include "user.h"
using namespace std;
int main()
{
	User user;
	user.welcome();
	user.getOrder();
	for (auto& p : user.getOrderList())
	{
		cout << p->getName() << " " << p->getQuantity() << endl;
	}
	return 0;
}
