/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                      File Name: /CPP-04/ex02/Cat/Cat.hpp                       *
*                    Creation Date: February 1, 2025 09:53 AM                    *
*                    Last Updated: February 1, 2025 07:06 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                             The genes of cuteness                              *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include "./../Animal/Animal.hpp"
#include "./../Brain/Brain.hpp"

/********************************************************************************/

/**
 * @brief A cat that makes "meow".
 * 
 */
class Cat : public Animal {
	private:
		Brain *brain;
		int	  index;
	public:
		Cat(void);
		Cat(const Cat &source);
		Cat &operator=(const Cat &source);
		virtual ~Cat(void);

		void changeIdea(const int i, const std::string &idea);
		void setIndex(const int i);

		Brain		*getBrain(void)		 const;
		std::string getIdea(const int i) const;
		int			getIndex(void)		 const;
		void		makeSound(void)		 const;
};