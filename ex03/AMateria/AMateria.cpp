/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                 File Name: /CPP-04/ex03/AMateria/AMateria.cpp                  *
*                    Creation Date: February 1, 2025 07:36 PM                    *
*                    Last Updated: February 3, 2025 10:53 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                               Magic behind spell                               *
*********************************************************************************/

#include "./AMateria.hpp"
#include "./../Interface/ICharacter.hpp"

/********************************************************************************/

AMateria::AMateria(void)					: _type("")				{}
AMateria::AMateria(std::string const &type)	: _type(type)			{}
AMateria::AMateria(const AMateria &source)	: _type(source._type)	{}

AMateria &AMateria::operator=(const AMateria &source) {
	if (this != &source)
		_type = source._type;
	return *this;
}

AMateria::~AMateria(void) {}

/********************************************************************************/

void	AMateria::use(ICharacter &target) {
	std::cout << "* uses an undefined materia on " << target.getName() << " *" << std::endl;
}

std::string const &AMateria::getType(void) const	{ return _type; }