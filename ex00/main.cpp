/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-04/ex00/main.cpp                        *
*                    Creation Date: January 30, 2025 11:13 AM                    *
*                    Last Updated: January 30, 2025 11:15 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*            Test program to verify that animals have all their paws             *
*********************************************************************************/

#include "./main.hpp"

int main(void) {
	Animal test;
	Animal test1(test);
	test = test1;
	test = test;
	test.makeSound();
	test1.makeSound();

	Dog dog1;
	Dog dog2(dog1);
	dog1 = dog2;
	dog2 = dog2;
	dog1.makeSound();
	dog2.makeSound();
	return 0;
}