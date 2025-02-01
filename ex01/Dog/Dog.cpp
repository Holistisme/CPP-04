/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-04/ex01/Dog/Dog.cpp                      *
*                    Creation Date: January 30, 2025 06:02 PM                    *
*                    Last Updated: February 1, 2025 07:06 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                                 Dog's language                                 *
*********************************************************************************/

#include "./Dog.hpp"
#include "./../output.hpp"

/********************************************************************************/

Dog::Dog(void) : Animal() {
	brain = new Brain();
	this->type = "Dog";
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< " A new dog has been born! It wags its tail excitedly!" << std::endl;
}

Dog::Dog(const Dog &source) : Animal(source) {
	brain = source.brain ? new Brain (*source.brain) : NULL;

	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< BG_GREEN << '[' << &source << ']' << RESET
		<< " A dog clones itself! The new dog looks just like a " << source.type << '.' << std::endl;
}

Dog &Dog::operator=(const Dog &source) {
	if (this != &source) {
		Animal::operator=(source);
		delete brain;
		brain = source.brain ? new Brain (*source.brain) : NULL;

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
	delete brain;
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< " A loyal dog leaves this world... Rest well, good boy." << std::endl;
}

/********************************************************************************/

void Dog::makeSound(void) const {
	std::cout << GREEN << type << RESET << ": Woof! Woof!"  << std::endl;
}

void Dog::changeIdea(const int i, const std::string &idea) { brain->setIdea(i, idea); };
void Dog::setIndex(const int i)							   { index = i; }

Brain		*Dog::getBrain(void) const		{ return brain; }
std::string Dog::getIdea(const int i) const { return brain->getIdea(i); }
int			Dog::getIndex(void)		  const { return index; }