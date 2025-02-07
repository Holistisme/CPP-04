/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                 File Name: /CPP-04/ex03/AMateria/AMateria.hpp                  *
*                    Creation Date: February 1, 2025 07:36 PM                    *
*                    Last Updated: February 3, 2025 10:53 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                   The abstract parent of all kinds of spells                   *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include <iostream>

/********************************************************************************/

class ICharacter;

/********************************************************************************/

class AMateria {
	protected:
		std::string _type;
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(const AMateria &source);

		AMateria &operator=(const AMateria &source);

		virtual ~AMateria(void);

		std::string const &getType(void) const;

		virtual void		use(ICharacter &target);
		virtual AMateria	*clone(void) const = 0;
};