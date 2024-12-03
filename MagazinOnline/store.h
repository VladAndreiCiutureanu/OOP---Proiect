#ifndef STORE_H
#define STORE_H
#include "cheese.h"
#include "croissant.h"
#include "dairy.h"
#include "eclair.h"
#include "fridge.h"
#include "ham.h"
#include "hammer.h"
#include "hoover.h"
#include "householdappliances.h"
#include "meat.h"
#include "milk.h"
#include "oven.h"
#include "pastry.h"
#include "pickaxe.h"
#include "salami.h"
#include "sausage.h"
#include "shovel.h"
#include "strudel.h"
#include "tool.h"
#include "washingmachine.h"
#include "yogurt.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <memory>
class Store
{
public:
	void readInventory();
	void displayInventory();
	void test();
private:
	std::vector<Product*> inventory;

};
#endif
