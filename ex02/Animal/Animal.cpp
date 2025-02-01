/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                    File Name: /CPP-04/ex02/Animal/Animal.cpp                   *
*                    Creation Date: January 30, 2025 11:16 AM                    *
*                    Last Updated: February 1, 2025 07:01 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                                Animal functions                                *
*********************************************************************************/

#include "./Animal.hpp"
#include "./../output.hpp"

/********************************************************************************/

Animal::Animal(void) : type("Unknown animal") {
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< " A mysterious being has just appeared ... What kind of animal is it?" << std::endl;
}

Animal::Animal(const Animal &source) : type(source.type) {
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< BG_GREEN << '[' << &source << ']' << RESET
		<< " A new animal takes the form of a " << source.type << '.' << std::endl;
}

Animal &Animal::operator=(const Animal &source) {
	if (this != &source) {
		type = source.type;
		std::cout << BG_BLUE << '[' << this << ']' << RESET
			<< BG_GREEN << '[' << &source << ']' << RESET
			<< " An animal adopts the soul of another! Transformation into a " << source.type << '.' << std::endl;
	} else {
		std::cout << BG_BLUE << '[' << this << ']' << RESET
			<< BG_GREEN << '[' << &source << ']' << RESET
			<< " This animal tries to become itself... nothing changes." << std::endl;
	}
	return *this;
}

Animal::~Animal(void) {
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< " An animal disappears in nature... Goodbye to it." << std::endl;
}

/********************************************************************************/

std::string Animal::getType(void) const { return type; }

void Animal::makeSound(void) const {
	std::cout << GREEN << type << RESET << ": * A strangely noticeable groan *"  << std::endl;
}