/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                    File Name: /CPP-04/ex00/Animal/Animal.hpp                   *
*                    Creation Date: January 30, 2025 11:16 AM                    *
*                    Last Updated: January 30, 2025 06:04 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                        Genes of the whole animal genre                         *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include <iostream>

/********************************************************************************/

/**
 * @brief The animal genus, parent of more specific species.
 * 
 */
class Animal {
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(const Animal &source);
		Animal &operator=(const Animal &source);
		virtual ~Animal(void);

		virtual void makeSound(void);
};