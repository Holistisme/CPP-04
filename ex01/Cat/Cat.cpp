/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                      File Name: /CPP-04/ex01/Cat/Cat.cpp                       *
*                    Creation Date: February 1, 2025 09:53 AM                    *
*                    Last Updated: February 1, 2025 07:06 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                     How they are going to make their eyes                      *
*********************************************************************************/

#include "./Cat.hpp"
#include "./../output.hpp"

/********************************************************************************/

Cat::Cat(void) : Animal() {
	brain = new Brain();
	this->type = "Cat";
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< " A mysterious cat appears, staring at you with deep, judgmental eyes..." << std::endl;
}

Cat::Cat(const Cat &source) : Animal(source) {
	brain = source.brain ? new Brain (*source.brain) : NULL;

	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< BG_GREEN << '[' << &source << ']' << RESET
		<< " Another cat emerges! It looks exactly like " << source.type << ", but does it have the same attitude?" << std::endl;
}

Cat &Cat::operator=(const Cat &source) {
	if (this != &source) {
		Animal::operator=(source);
		delete brain;
		brain = source.brain ? new Brain (*source.brain) : NULL;

		std::cout << BG_BLUE << '[' << this << ']' << RESET
			<< BG_GREEN << '[' << &source << ']' << RESET
			<< " This cat adopts the manners of another! Now it behaves just like a " << source.type << '.' << std::endl;
	} else {
		std::cout << BG_BLUE << '[' << this << ']' << RESET
			<< BG_GREEN << '[' << &source << ']' << RESET
			<< " The cat tries to copy itself... but decides it's already perfect!" << std::endl;
	}
	return *this;
}

Cat::~Cat(void) {
	delete brain;
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< " A silent cat vanishes into the shadows... Perhaps it never truly existed." << std::endl;
}

/********************************************************************************/

void Cat::makeSound(void) const {
	std::cout << GREEN << type << RESET << ": Meow!"  << std::endl;
}

void Cat::changeIdea(const int i, const std::string &idea) { brain->setIdea(i, idea); };
void Cat::setIndex(const int i)							   { index = i; }

Brain		*Cat::getBrain(void) const		{ return brain; }
std::string Cat::getIdea(const int i) const { return brain->getIdea(i); }
int			Cat::getIndex(void)		  const { return index; }