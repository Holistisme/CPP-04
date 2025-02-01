/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-04/ex01/main.hpp                        *
*                    Creation Date: January 30, 2025 11:14 AM                    *
*                    Last Updated: February 1, 2025 07:00 PM                     *
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

#include <limits>
#include <ctime>
#include <csignal>
#include <cstdlib>

/********************************************************************************/

#define ZOO_SIZE	10

#define SIGNAL		'\033'
#define forever		true

/********************************************************************************/

typedef int index;

/********************************************************************************/

int main(void);

bool		confirmAction(void);
std::string getInputLine(void);
void		handleSigInt(int signal);
bool		sameString(const std::string &first, const std::string &second);

void		manageZooMemory(Animal **zoo);