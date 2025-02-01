/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                      File Name: /CPP-04/ex00/Cat/Cat.hpp                       *
*                    Creation Date: February 1, 2025 09:53 AM                    *
*                    Last Updated: February 1, 2025 11:11 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                             The genes of cuteness                              *
*********************************************************************************/


#pragma once

/********************************************************************************/

#include "./../Animal/Animal.hpp"

/********************************************************************************/

/**
 * @brief A cat that makes "meow".
 * 
 */
class Cat : public Animal {
	public:
		Cat(void);
		Cat(const Cat &source);
		Cat &operator=(const Cat &source);
		virtual ~Cat(void);

		void makeSound(void) const;
};