/*********************************************************************************
*                              Author: Alexy Heitz                               *
*              File Name: /CPP-04/ex00/WrongAnimal/WrongAnimal.cpp               *
*                    Creation Date: February 1, 2025 10:09 AM                    *
*                    Last Updated: February 1, 2025 11:11 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                      The functioning of a strange entity                       *
*********************************************************************************/


#include "./WrongAnimal.hpp"
#include "./../output.hpp"

/********************************************************************************/

WrongAnimal::WrongAnimal(void) : type("Unknown wrong animal") {
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< " A strange, unidentified creature appears... but something feels off!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &source) : type(source.type) {
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< BG_GREEN << '[' << &source << ']' << RESET
		<< " A glitch in nature creates another " << source.type << ". But is it really the same?" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &source) {
	if (this != &source) {
		type = source.type;
		std::cout << BG_BLUE << '[' << this << ']' << RESET
			<< BG_GREEN << '[' << &source << ']' << RESET
			<< " This weird creature copies " << source.type << ", but it still feels... wrong." << std::endl;
	} else {
		std::cout << BG_BLUE << '[' << this << ']' << RESET
			<< BG_GREEN << '[' << &source << ']' << RESET
			<< " It tries to copy itself... but it was already flawed to begin with." << std::endl;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< " The unnatural being fades into nothingness, leaving no trace behind." << std::endl;
}

/********************************************************************************/

void WrongAnimal::makeSound(void) const {
	std::cout << GREEN << type << RESET << ": ALERT: Undefined sound detected!"  << std::endl;
}