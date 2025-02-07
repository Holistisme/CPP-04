/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                     File Name: /CPP-04/ex03/Cure/Cure.cpp                      *
*                    Creation Date: February 3, 2025 11:18 AM                    *
*                    Last Updated: February 3, 2025 11:23 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                                 Magic to heal                                  *
*********************************************************************************/

#include "./Cure.hpp"
#include "./../Interface/ICharacter.hpp"

/********************************************************************************/

Cure::Cure()							: AMateria("cure")	{}
Cure::Cure(const Cure &source)			: AMateria(source)	{}

Cure &Cure::operator=(const Cure &source) {
	if (this != &source)
		AMateria::operator=(source);
	return *this;
}

Cure::~Cure(void) {}

/********************************************************************************/

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria *Cure::clone(void) const	{ return new Cure(*this); }