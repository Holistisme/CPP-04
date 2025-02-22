/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-04/ex00/Dog/Dog.cpp                      *
*                    Creation Date: January 30, 2025 06:02 PM                    *
*                    Last Updated: February 1, 2025 11:11 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                                 Dog's language                                 *
*********************************************************************************/

#include "./Dog.hpp"
#include "./../output.hpp"

/********************************************************************************/

Dog::Dog(void) : Animal() {
	this->type = "Dog";
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< " A new dog has been born! It wags its tail excitedly!" << std::endl;
}

Dog::Dog(const Dog &source) : Animal(source) {
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< BG_GREEN << '[' << &source << ']' << RESET
		<< " A dog clones itself! The new dog looks just like a " << source.type << '.' << std::endl;
}

Dog &Dog::operator=(const Dog &source) {
	if (this != &source) {
		Animal::operator=(source);
		std::cout << BG_BLUE << '[' << this << ']' << RESET
			<< BG_GREEN << '[' << &source << ']' << RESET
			<< " This dog learns from another! Now it behaves like a " << source.type << '.' << std::endl;
	} else {
		std::cout << BG_BLUE << '[' << this << ']' << RESET
			<< BG_GREEN << '[' << &source << ']' << RESET
			<< " This dog tries to copy itself... but it's already the same." << std::endl;
	}
	return *this;
}

Dog::~Dog(void) {
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< " A loyal dog leaves this world... Rest well, good boy." << std::endl;
}

/********************************************************************************/

void Dog::makeSound(void) const {
	std::cout << GREEN << type << RESET << ": Woof! Woof!"  << std::endl;
}