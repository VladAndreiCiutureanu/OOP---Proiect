#include <iostream>
#include "user.h"
#include "menu.h"
#include <memory>
using namespace std;
int main()
{
	shared_ptr<User> user = make_shared<User>();
	Menu menu(user);
	menu.welcome();
	return 0;
}
