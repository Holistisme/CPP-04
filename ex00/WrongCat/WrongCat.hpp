/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                 File Name: /CPP-04/ex00/WrongCat/WrongCat.hpp                  *
*                    Creation Date: February 1, 2025 10:31 AM                    *
*                    Last Updated: February 1, 2025 11:12 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                            A Strange Percant Regard                            *
*********************************************************************************/


#pragma once

/********************************************************************************/

#include "./../WrongAnimal/WrongAnimal.hpp"

/********************************************************************************/

/**
 * @brief A cat that strangely makes "meow".
 * 
 */
class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat &source);
		WrongCat &operator=(const WrongCat &source);
		~WrongCat(void);

		void makeSound(void) const;
};