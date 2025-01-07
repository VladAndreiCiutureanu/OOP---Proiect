#include "menu.h"
void Menu::welcome()
{
	userOrAdmin();
	if (user.isAdminUser())
	{
		adminMenu();
	}
	else
	{
		userMenu();
	}
}
void Menu::userOrAdmin()
{
	std::string password;
	std::ifstream fin("parola.txt");
	fin >> password;
	fin.close();
	std::cout << "Introduceti parola:(daca sunteti utilizator, introduceti user)\n";
	std::string attempt;
	std::cin >> attempt;
	if (attempt == password)
	{
		user.setAdmin(true);
	}
}
void Menu::adminMenu() {
	std::cout << "Bine ati venit, domnule Admin!\n\n\n";
	std::cout << "============================================================================================================================================================\n";
	std::cout << "Iata inventarul magazinului:\n";
	store.displayInventory();
	std::cout << "============================================================================================================================================================\n";
	store.printWarnings();
	std::cout << "============================================================================================================================================================\n";
	std::cout << "Doriti sa eliminati produsele care nu mai exista in stock? (da/nu)\n";
	std::string answer;
	std::cin >> answer;
	if (answer == "da")
	{
		store.removeUnavailableProducts();
	}
	std::cout << "============================================================================================================================================================\n";
	std::cout << "Doriti sa eliminati produsele care au expirat? (da/nu)\n";
	std::cin >> answer;
	if (answer == "da")
	{
		store.removeExpiredProducts();
	}
	std::cout << "============================================================================================================================================================\n";
	while (true) {
		std::cout << "Doriti sa adaugati un produs in inventar? (da/nu)\n";
		std::cin >> answer;
		if (answer == "da")
		{
			std::cout << "Produsul pe care doriti sa il adaugati este perisabil? (da/nu)\n";
			std::cin >> answer;
			std::cin.ignore();
			if (answer == "da")
			{
				Product* pp = new PerishableProduct();
				std::string line;
				std::getline(std::cin, line);
				std::stringstream ss(line);
				ss >> *pp;
				store.addProduct(pp);
			}
			else {
				Product* p = new Product();
				std::cin >> *p;
				store.addProduct(p);
			}
		}
		else {
			break;
		}
	}
	while (true) {
		std::cout << "Doriti sa stergeti un produs din inventar? (da/nu)\n";
		std::cin >> answer;
		if (answer == "da")
		{
			std::cout << "Introduceti numele produsului pe care doriti sa il stergeti:\n";
			std::cin.ignore();
			std::string name;
			std::getline(std::cin, name);
			store.removeProduct(name);
		}
		else {
			break;
		}
	}
}
void Menu::userMenu() {
	std::cout << "Bine ati venit la magazinul nostru!\n\n\n";
	std::cout << "============================================================================================================================================================\n";
	std::cout << "Iata ce produse avem:\n";
	store.displayInventory();
	std::cout << "============================================================================================================================================================\n";
	std::cout << "Iata ce oferte avem astazi:\n";
	store.generateOffer();
	std::cout << "============================================================================================================================================================\n";
	std::cout << "Iata ce promotii avem astazi:\n";
	store.generatePromotion();
	std::cout << "============================================================================================================================================================\n";
	std::cout << "Acestea sunt cele mai populare 5 produse de la magazinul nostru:\n";
	showStats();
	std::cout << "============================================================================================================================================================\n";
	user.getOrder(store.getInventory());
	store.getOrderPrice(user.getOrderList());
}
void Menu::showStats() {
	std::ifstream fin("statistici.txt");
	std::string line;
	for (int i = 0; i < 5; i++)
	{
		std::getline(fin, line);
		std::cout << i + 1<< ". " << line << std::endl;
	}
	fin.close();
}
void Menu::readStats() {
	std::string name;
	int quantitySold;
	std::ifstream fin("statistici.txt");
	std::string line;
	while (std::getline(fin, line))
	{
		std::vector<std::string> tokens;
		boost::split(tokens, line, boost::is_any_of(","));
		boost::trim(tokens[0]);
		name = tokens[0];
		quantitySold = std::stoi(tokens[1]);
		stats.push_back(std::make_pair(quantitySold, name));
	}
	sort(stats.begin(), stats.end());
	fin.close();
}
void Menu::updateStats() {
	readStats();
	std::vector<Product*> order = user.getOrderList();
	std::string name;
	int quantitySold;
	for (auto& product : order)
	{
		name = product->getName();
		quantitySold = product->getQuantity();
		bool found = false;
		for (auto& stat : stats)
		{
			if (stat.second == name)
			{
				stat.first += quantitySold;
				found = true;
				break;
			}
		}
		if (!found)
		{
			stats.push_back(std::make_pair(quantitySold, name));
		}
	}
	sort(stats.begin(), stats.end());
}
void Menu::writeStats() {
	std::ofstream fout("statistici.txt");
	fout.clear();
	int count = 0;
	int index = stats.size() - 1;
	while (count < 5 && index >=0) {
		fout << stats[index].second << "," << stats[index].first << std::endl;
		count++;
		index--;
	}
	fout.close();
}
Menu::~Menu() {
	updateStats();
	writeStats();
}