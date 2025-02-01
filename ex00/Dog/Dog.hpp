/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-04/ex00/Dog/Dog.hpp                      *
*                    Creation Date: January 30, 2025 06:02 PM                    *
*                    Last Updated: February 1, 2025 11:11 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                     The gens of the best friend of the man                     *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include "./../Animal/Animal.hpp"

/********************************************************************************/

/**
 * @brief A dog that makes "woof".
 * 
 */
class Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog &source);
		Dog &operator=(const Dog &source);
		virtual ~Dog(void);

		void makeSound(void) const;
};