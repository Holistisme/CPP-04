/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                      File Name: /CPP-04/ex03/Ice/Ice.hpp                       *
*                    Creation Date: February 3, 2025 10:42 AM                    *
*                    Last Updated: February 3, 2025 11:14 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                         The molecules defining the ice                         *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include <iostream>

/********************************************************************************/

#include "./../AMateria/AMateria.hpp"

/********************************************************************************/

class Ice : public AMateria {
	public:
		Ice(void);
		Ice(const Ice &source);

		Ice &operator=(const Ice &source);

		virtual ~Ice(void);

		void		use(ICharacter &target);
		AMateria	*clone(void) const;
};