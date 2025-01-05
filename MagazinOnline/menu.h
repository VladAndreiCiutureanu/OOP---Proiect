#ifndef MENU_H
#define MENU_H
#include "store.h"
#include "user.h"
#include <memory>
class Menu
{
public:
	Menu(std::shared_ptr<User> user) : user(user) {}
	void welcome();
private:
	Store store;
	std::shared_ptr<User> user;
};
#endif
