#include "menu.h"
void Menu::welcome()
{
	std::cout << "Bine ati venit la magazinul nostru!\n";
	std::cout << "Iata ce produse avem:\n";
	store.displayInventory();
	std::cout << "Iata ce oferte avem astazi:\n";
	store.generateOffer();
	std::cout << "Iata ce promotii avem astazi:\n";
	store.generatePromotion();
	user->getOrder(store.getInventory());
}