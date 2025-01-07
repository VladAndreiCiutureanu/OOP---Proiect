#ifndef MENU_H
#define MENU_H
#include "store.h"
#include "user.h"
#include <memory>
#include <fstream>
#include <map>
class Menu
{
public:
	Menu(User user) : user(user) {}
	void welcome();
	void showStats();
	~Menu();
private:
	Store store;
	User user;
	std::vector<std::pair<int, std::string>> stats;
	void readStats();
	void updateStats();
	void writeStats();
	void userOrAdmin();
	void adminMenu();
	void userMenu();
};
#endif
