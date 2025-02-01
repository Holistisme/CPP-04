/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                    File Name: /CPP-04/ex01/Brain/Brain.hpp                     *
*                    Creation Date: February 1, 2025 12:52 PM                    *
*                    Last Updated: February 1, 2025 07:06 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                                 Brain neurons                                  *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include <cstdlib>
#include <iostream>

/********************************************************************************/

/**
 * @brief The source of great knowledge.
 * 
 */
class Brain {
	private:
		std::string ideas[100];
	public:
		Brain(void);
		Brain(const Brain &source);
		Brain &operator=(const Brain &source);
		~Brain(void);

		void setIdea(const int index, const std::string &idea);

		std::string getIdea(const int index) const;
};