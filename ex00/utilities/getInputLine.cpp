/*********************************************************************************
*                              Author: Alexy Heitz                               *
*               File Name: /CPP-04/ex00/utilities/getInputLine.cpp               *
*                    Creation Date: February 1, 2025 11:43 AM                    *
*                    Last Updated: February 1, 2025 11:47 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                       Utility to retrieve an input line                        *
*********************************************************************************/

#include "./../main.hpp"

/********************************************************************************/

/**
 * @brief Recovers a line from standard input and handle EOF or errors gracefully.
 * 
 * This function ensures proper handling of EOF (CTRL-D) and returns a clean string input.
 * Also prohibits any form of signal.
 * 
 * @return std::string: The line read.
 */
std::string getInputLine(void) {
	std::string input;
	std::getline(std::cin, input);

	if (std::cin.eof()) {
		std::cout << EOF << std::endl;
		exit(EXIT_SUCCESS);
	}
	else if (std::cin.fail()) {
		std::cout << ERROR << "An error occurred while reading input!" << RESET << std::endl;
		std::cin.clear(), input = "";
	}
	else if (input.find(SIGNAL) != std::string::npos) {
		std::cout << ERROR << PROGRAM << RESET
			<< " refuses to carry signals! The field is therefore initiated into the void!" << RESET << std::endl;
		input = "";
	}
	trimSpaces(input);
	return input;
}