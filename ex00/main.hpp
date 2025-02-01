/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-04/ex00/main.hpp                        *
*                    Creation Date: January 30, 2025 11:14 AM                    *
*                    Last Updated: January 30, 2025 11:14 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                        Sources to properly test animals                        *
*********************************************************************************/

#pragma once

#include "./Animal/Animal.hpp"
#include "./WrongAnimal/WrongAnimal.hpp"
#include "./Dog/Dog.hpp"
#include "./Cat/Cat.hpp"
#include "./WrongCat/WrongCat.hpp"

#include "./output.hpp"

#include <cstdlib>

#define SIGNAL  '\033'
#define forever	true

std::string getInputLine(void);
bool sameString(const std::string &first, const std::string &second);
void trimSpaces(std::string &string);

int main(void);