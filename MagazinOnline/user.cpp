#include "user.h"
void User::getOrder(std::vector<Product*>& inventory) {
	std::cout << "Introduceti numele produselor pe care doriti sa il cumparati si cantitatea(stop pentru oprire), separate prin \",\": \n";
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
		for (auto& product : inventory) {
			if (product->getName() == name) {
				if (product->getQuantity() >= quantity) {
					if (instanceof<PerishableProduct>(product))
					{
						Product* p = new PerishableProduct(*dynamic_cast<PerishableProduct*>(product));
						p->setQuantity(quantity);
						order.push_back(p);
					}
					else {
						Product* p = new Product(*product);
						p->setQuantity(quantity);
						order.push_back(p);
					}
					product->setQuantity(product->getQuantity() - quantity);
				}
				else {
					std::cout << "Nu avem suficiente produse in stoc\n";
				}
			}
		}
	}
}
