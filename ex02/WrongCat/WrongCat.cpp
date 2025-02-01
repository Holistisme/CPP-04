/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                 File Name: /CPP-04/ex02/WrongCat/WrongCat.cpp                  *
*                    Creation Date: February 1, 2025 10:31 AM                    *
*                    Last Updated: February 1, 2025 12:19 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                        The unusual functioning of a cat                        *
*********************************************************************************/

#include "./WrongCat.hpp"
#include "./../output.hpp"

/********************************************************************************/

WrongCat::WrongCat(void) : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< " A WrongCat appears, but it doesn't feel quite right..." << std::endl;
}

WrongCat::WrongCat(const WrongCat &source) : WrongAnimal(source) {
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< BG_GREEN << '[' << &source << ']' << RESET
		<< " Another WrongCat emerges from " << source.type << ", but something is off!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &source) {
	if (this != &source) {
		WrongAnimal::operator=(source);
		std::cout << BG_BLUE << '[' << this << ']' << RESET
			<< BG_GREEN << '[' << &source << ']' << RESET
			<< " This WrongCat copies another " << source.type << "! But does it sound any different?" << std::endl;
	} else {
		std::cout << BG_BLUE << '[' << this << ']' << RESET
			<< BG_GREEN << '[' << &source << ']' << RESET
			<< " The WrongCat attempts to copy itself... but was already imperfect!" << std::endl;
	}
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< " The WrongCat vanishes into the void... leaving behind only confusion." << std::endl;
}

/********************************************************************************/

void WrongCat::makeSound(void) const {
	std::cout << GREEN << type << RESET << ": Meow?"  << std::endl;
}