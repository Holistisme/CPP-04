/*********************************************************************************
*                              Author: Alexy Heitz                               *
*              File Name: /CPP-04/ex00/WrongAnimal/WrongAnimal.hpp               *
*                    Creation Date: February 1, 2025 10:09 AM                    *
*                    Last Updated: February 1, 2025 11:11 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                        Is it really an animal finally?                         *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include <iostream>

/********************************************************************************/

/**
 * @brief The WrongAnimal genus, parent of more wrong specific species.
 * 
 */
class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &source);
		WrongAnimal &operator=(const WrongAnimal &source);
		~WrongAnimal(void);

		void makeSound(void) const;
};