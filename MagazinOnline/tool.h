#ifndef TOOL_H
#define TOOL_H
#include "product.h"

class Tool :
	public Product
{
public:
	Tool(std::string name = "none", std::string description = "none", std::string category = "Unelte", double price = 0.0, int quantity = 0);
};


#endif