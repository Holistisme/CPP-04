/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                      File Name: /CPP-04/ex03/Ice/Ice.cpp                       *
*                    Creation Date: February 3, 2025 10:41 AM                    *
*                    Last Updated: February 3, 2025 11:16 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                      The physical functioning of the ice                       *
*********************************************************************************/

#include "./Ice.hpp"
#include "./../Interface/ICharacter.hpp"

/********************************************************************************/

Ice::Ice()							: AMateria("ice")	{}
Ice::Ice(const Ice &source)			: AMateria(source)	{}

Ice &Ice::operator=(const Ice &source) {
	if (this != &source)
		AMateria::operator=(source);
	return *this;
}

Ice::~Ice(void) {}

/********************************************************************************/

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone(void) const	{ return new Ice(*this); }