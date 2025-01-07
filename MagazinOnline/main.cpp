#include <iostream>
#include "user.h"
#include "menu.h"
#include <memory>
using namespace std;
int main()
{
	User user;
	Menu menu(user);
	menu.welcome();
	return 0;
}
