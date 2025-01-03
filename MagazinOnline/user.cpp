#include "user.h"
User::User()
{
	store.readInventory();
}
void User::welcome()
{
	std::cout << "Bine ati venit la magazinul nostru!\n";
	std::cout << "Iata ce produse avem:\n";
	store.displayInventory();
	std::cout << "Iata ce oferte avem astazi:\n";
	store.generateOffer();
	std::cout << "Iata ce promotii avem astazi:\n";
	store.generatePromotion();
}
void User::getOrder() {
	std::cout << "Introduceti numele produsului pe care doriti sa il cumparati si cantitatea(stop pentru oprire), separate prin \",\": \n";
	std::string line;
	int quantity;
	while (true) {
		std::getline(std::cin, line);
		if (line == "\n")
		{
			continue;
		}
		if (line == "stop") {
			break;
		}
		std::string name;
		std::string quantityString;
		std::vector<std::string> tokens;
		boost::split(tokens, line, boost::is_any_of(","));
		for (auto& token : tokens)
		{
			boost::trim(token);
		}
		name = tokens.at(0);
		quantityString = tokens.at(1);
		quantity = std::stoi(quantityString);
		for (auto& product : store.getInventory()) {
			if (product->getName() == name) {
				if (product->getQuantity() >= quantity) {
					product->setQuantity(product->getQuantity() - quantity);
					order.push_back(product);
				}
				else {
					std::cout << "Nu avem suficiente produse in stoc\n";
				}
			}
		}
	}
}
