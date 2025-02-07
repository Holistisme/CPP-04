/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                File Name: /CPP-04/ex03/Character/Character.hpp                  *
*                    Creation Date: February 3, 2025 02:50 PM                    *
*                    Last Updated: February 4, 2025 09:31 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                          The identity of a character                           *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include <iostream>

/********************************************************************************/

#include "./../Interface/ICharacter.hpp"

/********************************************************************************/

class Character : public ICharacter {
	private:
		std::string	_name;
		AMateria	*_slot[4];

		void	setSlot(void);
		void	copySlot(const Character *source);
	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &source);

		Character &operator=(const Character &source);

		virtual ~Character();

		std::string const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

		AMateria *getSlot(const int i) const;
};