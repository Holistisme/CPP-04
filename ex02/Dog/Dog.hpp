/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-04/ex02/Dog/Dog.hpp                      *
*                    Creation Date: January 30, 2025 06:02 PM                    *
*                    Last Updated: February 1, 2025 07:06 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                     The gens of the best friend of the man                     *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include "./../Animal/Animal.hpp"
#include "./../Brain/Brain.hpp"

/********************************************************************************/

/**
 * @brief A dog that makes "woof".
 * 
 */
class Dog : public Animal {
	private:
		Brain *brain;
		int	  index;
	public:
		Dog(void);
		Dog(const Dog &source);
		Dog &operator=(const Dog &source);
		virtual ~Dog(void);

		void changeIdea(const int i, const std::string &idea);
		void setIndex(const int i);

		Brain		*getBrain(void)		 const;
		std::string getIdea(const int i) const;
		int			getIndex(void)		 const;
		void		makeSound(void)		 const;
};