/*********************************************************************************
*                              Author: Alexy Heitz                               *
*               File Name: /CPP-04/ex02/utilities/getInputLine.cpp               *
*                    Creation Date: February 1, 2025 11:43 AM                    *
*                    Last Updated: February 1, 2025 07:05 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                       Utility to retrieve an input line                        *
*********************************************************************************/

#include "./../main.hpp"

/********************************************************************************/

static void trimSpaces(std::string &string);

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
		manageZooMemory(NULL);
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

/**
 * @brief Removes leading and trailing spaces from a string.
 * 
 * @param string The string to process.
 */
static void trimSpaces(std::string &string) {
	size_t start = 0;
	size_t end	 = string.length();

	while (start < string.length() && std::isspace(string[start]))
		++start;
	while (end > start && std::isspace(string[end - 1]))
		--end;

	string = string.substr(start, end - start);
}