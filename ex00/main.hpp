/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-04/ex00/main.hpp                        *
*                    Creation Date: January 30, 2025 11:14 AM                    *
*                    Last Updated: February 1, 2025 12:42 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                        Sources to properly test animals                        *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include "./output.hpp"

#include "./Animal/Animal.hpp"
#include "./WrongAnimal/WrongAnimal.hpp"
#include "./Dog/Dog.hpp"
#include "./Cat/Cat.hpp"
#include "./WrongCat/WrongCat.hpp"

/********************************************************************************/

#include <cstdlib>

/********************************************************************************/

#define SIGNAL  '\033'
#define forever	true

/********************************************************************************/

int main(void);

std::string getInputLine(void);
bool		sameString(const std::string &first, const std::string &second);