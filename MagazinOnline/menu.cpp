#include "menu.h"
void Menu::welcome()
{
	std::cout << "Bine ati venit la magazinul nostru!\n\n\n";
	std::cout << "==============================================================================\n";
	std::cout << "Iata ce produse avem:\n";
	store.displayInventory();
	std::cout << "==============================================================================\n";
	std::cout << "Iata ce oferte avem astazi:\n";
	store.generateOffer();
	std::cout << "==============================================================================\n";
	std::cout << "Iata ce promotii avem astazi:\n";
	store.generatePromotion();
	std::cout << "==============================================================================\n";
	user->getOrder(store.getInventory());
	store.getOrderPrice(user->getOrderList());
}