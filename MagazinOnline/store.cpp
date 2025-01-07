#include "store.h"
Store::Store() {
	readInventory();
}
void Store::readInventory()
{
	std::ifstream file("inventar.txt");
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		if (std::count(line.begin(), line.end(), '|') == 4)
		{
			Product* p = new Product();
			ss >> *p;
			inventory.push_back(p);
		}
		else
		{
			PerishableProduct* pp = new PerishableProduct();
			ss >> *pp;
			inventory.push_back(pp);
		}
	}
}
void Store::displayInventory() {
	for (auto& product : inventory) {
		std::cout << *product;
	}
}
Store::~Store() {
	std::ofstream file("inventar.txt");
	updateFile();
	for (auto& product : inventory) {
		delete product;
	}
	file.close();
}
bool Store::addProduct(Product* p) {
	for (auto& product : inventory) {
		if (product->getName() == p->getName()) {
			std::cout << "Produsul exista deja in inventar\n";
			return false;
		}
	}
	inventory.push_back(p);
	return true;
}
bool Store::updateFile() {
	std::ofstream file("inventar.txt");
	file.clear();
	if (!file.is_open()) {
		std::cout << "Eroare la deschiderea fisierului\n";
		return false;
	}
	for (auto& product : inventory) {
		file << *product;
	}
	file.close();
	return true;
}

void Store::removeExpiredProducts() {
	std::vector<int> currentDate = getCurrentDate();//date[0] = day, date[1] = month, date[2] = year
	for (int i = 0; i < inventory.size(); i++) {
		if (instanceof<PerishableProduct>(inventory.at(i))) {
			std::string expiryDate = dynamic_cast<PerishableProduct*>(inventory.at(i))->getExpiryDate();
			std::vector<int> date;
			std::vector<std::string> tokens;
			boost::split(tokens, expiryDate, boost::is_any_of("/"));
			for (auto& token : tokens)
			{
				boost::trim(token);
				date.push_back(std::stoi(token));
			}
			if (date[2] < currentDate[2]) {
				inventory.erase(inventory.begin() + i);
			}
			else if (date[2] == currentDate[2]) {
				if (date[1] < currentDate[1]) {
					inventory.erase(inventory.begin() + i);
				}
				else if (date[1] == currentDate[1]) {
					if (date[0] < currentDate[0]) {
						inventory.erase(inventory.begin() + i);
					}
				}
			}
		}
	}
}
std::vector<int> getCurrentDate() {
	std::vector<int> date;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	date.push_back(ltm->tm_mday);
	date.push_back(1 + ltm->tm_mon);
	date.push_back(1900 + ltm->tm_year);
	return date;
}
void Store::generateOffer() {
	srand(time(0));
	std::vector<int> indices;
	for (int i = 0; i < 3; i++) {
		int percentage = rand() % 25 + 1;
		int index = rand() % inventory.size();
		while (find(indices.begin(), indices.end(), index) != indices.end())
		{
			index = rand() % inventory.size();
		}
		indices.push_back(index);
		double newPrice = inventory.at(index)->getPrice() - (inventory.at(index)->getPrice() * percentage / 100);
		inventory.at(index)->setPrice(newPrice);
		std::cout << "Produsul " << inventory.at(index)->getName() << " are o reducere de " << percentage << "%\n";
		std::cout << "Noul pret este " << newPrice << "\n";
	}
}
void Store::generatePromotion() {
	//promotie de tipul buy 2 get 1 for half the price
	srand(time(0));
	std::vector<int> indices;
	for (int i = 0; i < 2; i++) {
		int index = rand() % inventory.size();
		while (find(indices.begin(), indices.end(), index) != indices.end())
		{
			index = rand() % inventory.size();
		}
		promotion.push_back(inventory.at(index));
		indices.push_back(index);

		std::cout << "La doua produse cumparate de tipul " << inventory.at(index)->getName() << " primiti unul la jumatate de pret\n";
	}

}
double Store::getOrderPrice(std::vector<Product*> order) {
	double price = 0;
	std::cout << "Comanda dumneavoastra este:\n";
	for (auto& product : order) {
		double currentPrice = product->getPrice() * product->getQuantity();
		int quantity = product->getQuantity();
		for (auto& promotedProduct : promotion)
		{
			if (product->getName() == promotedProduct->getName())
			{
				while (quantity > 2) {
					currentPrice -= product->getPrice() / 2;
					quantity -= 3;
				}
			}
		}
		std::cout << product->getName() << " " << product->getQuantity() << " " << currentPrice << "\n";
		std::cout << "============================\n";
		price += currentPrice;
	}
	std::cout << "Pretul total este: " << price << "\n";
	return price;
}
void Store::printWarnings() {
	for (auto& product : inventory) {
		if (product->getQuantity() == 0) {
			std::cout << "ATENTIE!!! Produsul " << product->getName() << " nu mai este in stoc\n";
		}
		else {
			std::vector<int> currentDate = getCurrentDate();//date[0] = day, date[1] = month, date[2] = year
			for (int i = 0; i < inventory.size(); i++) {
				if (instanceof<PerishableProduct>(inventory.at(i))) {
					std::string expiryDate = dynamic_cast<PerishableProduct*>(inventory.at(i))->getExpiryDate();
					std::vector<int> date;
					std::vector<std::string> tokens;
					boost::split(tokens, expiryDate, boost::is_any_of("/"));
					for (auto& token : tokens)
					{
						boost::trim(token);
						date.push_back(std::stoi(token));
					}
					if (date[2] < currentDate[2]) {
						std::cout << "ATENTIE!!! Produsul " << inventory.at(i)->getName() << " a expirat\n";
					}
					else if (date[2] == currentDate[2]) {
						if (date[1] < currentDate[1]) {
							std::cout << "ATENTIE!!! Produsul " << inventory.at(i)->getName() << " a expirat\n";
						}
						else if (date[1] == currentDate[1]) {
							if (date[0] < currentDate[0]) {
								std::cout << "ATENTIE!!! Produsul " << inventory.at(i)->getName() << " a expirat\n";
							}
						}
					}
				}
			}

		}
	}
}
void Store::removeUnavailableProducts() {
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory.at(i)->getQuantity() == 0) {
			inventory.erase(inventory.begin() + i);
		}
	}
}
bool Store::removeProduct(std::string name) {
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory.at(i)->getName() == name) {
			inventory.erase(inventory.begin() + i);
			return true;
		}
	}
	std::cout << "Produsul nu exista in inventar\n";
	return false;
}