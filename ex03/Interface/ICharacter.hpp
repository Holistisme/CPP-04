/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                File Name: /CPP-04/ex03/Interface/ICharacter.hpp                *
*                    Creation Date: February 3, 2025 10:39 AM                    *
*                    Last Updated: February 3, 2025 10:55 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                          The interface of a character                          *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include <iostream>

/********************************************************************************/

class AMateria;

/********************************************************************************/

class ICharacter {
	public:
		virtual ~ICharacter() {}

		virtual std::string const	&getName() const					= 0;
		virtual void				equip(AMateria *m)					= 0;
		virtual void				unequip(int idx)					= 0;
		virtual void				use(int idx, ICharacter &target)	= 0;
};