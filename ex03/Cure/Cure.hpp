/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                     File Name: /CPP-04/ex03/Cure/Cure.hpp                      *
*                    Creation Date: February 3, 2025 11:18 AM                    *
*                    Last Updated: February 3, 2025 11:23 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                            Medicine to settle well                             *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include <iostream>

/********************************************************************************/

#include "./../AMateria/AMateria.hpp"

/********************************************************************************/

class Cure : public AMateria {
	public:
		Cure(void);
		Cure(const Cure &source);

		Cure &operator=(const Cure &source);

		virtual ~Cure(void);

		void		use(ICharacter &target);
		AMateria	*clone(void) const;
};