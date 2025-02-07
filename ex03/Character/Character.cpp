/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                File Name: /CPP-04/ex03/Character/Character.cpp                 *
*                    Creation Date: February 3, 2025 03:28 PM                    *
*                    Last Updated: February 7, 2025 02:51 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                           The functioning of a human                           *
*********************************************************************************/

#include "./Character.hpp"
#include "./../AMateria/AMateria.hpp"
#include "./../output.hpp"

/********************************************************************************/

#include <cstdlib>

/********************************************************************************/

bool	sameString(const std::string &first, const std::string &second);

/********************************************************************************/

Character::Character(void)						: _name("")				{ setSlot();			}
Character::Character(const std::string &name)	: _name(name)			{ setSlot();			}
Character::Character(const Character &source)	: _name(source._name)	{ copySlot(&source);	}

Character &Character::operator=(const Character &source) {
	if (this != &source) {
		_name = source._name;
		copySlot(&source);
	}
	return *this;
}

Character::~Character(void) {
	if ((sameString(getName(), "RICK ASTLEY"))) {
		#ifdef __linux__
			system("xdg-open https://www.youtube.com/watch?v=dQw4w9WgXcQ > /dev/null 2>&1");
		#elif _WIN32
			system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ > nul 2>&1");
		#elif __APPLE__
			system("open https://www.youtube.com/watch?v=dQw4w9WgXcQ > /dev/null 2>&1");
		#endif
	}
	copySlot(NULL);
}

/********************************************************************************/

void Character::copySlot(const Character *source) {
	for (int i = 0 ; i < 4 ; i++) {
		if (_slot[i])
			delete _slot[i];
		source ? _slot[i] = (*source).getSlot(i) : NULL;
	}
}

void Character::setSlot(void) {
	for (int i = 0; i < 4 ; i++)
		_slot[i] = NULL;
}

/********************************************************************************/

std::string const	&Character::getName() const	{ return _name;		}
void				Character::unequip(int idx) {
	if ((idx >= 0 and idx < 4) and _slot[idx]) {
		std::cout << getName() << " well removed " << getSlot(idx)->getType() << " from " << idx << " slot.\n" << std::endl;
		_slot[idx] = NULL;
	}
	else
		std::cout << RED << _name << " is not equipped with the slot " << idx << RESET << ".\n" << std::endl;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 or idx > 4)
		std::cout << RED << _name << " does not have the place necessary in its pockets to have a slot " << idx << "!" << std::endl;
	else if (_slot[idx])
		_slot[idx]->use(target);
	else
		std::cout << RED << _name << " does not have hidden spell in the slot " << idx << "!" << std::endl;
}


void Character::equip(AMateria *m) {
	for (int i = 0 ; m and i < 4 ; i++)
		if (!_slot[i]) {
			_slot[i] = m->clone();
			std::cout << _name << " has well equipped the " << GREEN << m->getType() << RESET << " in slot " << BLUE << i << RESET << "!\n" << std::endl;
			return;
		}
	std::cout << RED << _name << " has not found the place in its inventory to add the spell!" << RESET << '\n' << std::endl;
}

AMateria *Character::getSlot(const int i) const	{
	if (i >= 0 and i < 4)
		return _slot[i];
	return NULL;
}