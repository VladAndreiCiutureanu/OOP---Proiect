#include "sausage.h"
Sausage::Sausage() :
	Meat()
{
	this->setExpiryDate("none");
	this->setName("Carnati");
	this->setPrice(10.99);
}