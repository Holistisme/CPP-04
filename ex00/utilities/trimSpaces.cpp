/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                File Name: /CPP-04/ex00/utilities/trimSpaces.cpp                *
*                    Creation Date: February 1, 2025 11:43 AM                    *
*                    Last Updated: February 1, 2025 11:45 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                Utility for removing extra spaces from a string                 *
*********************************************************************************/

#include "./../main.hpp"

/********************************************************************************/

/**
 * @brief Removes leading and trailing spaces from a string.
 * 
 * @param string The string to process.
 */
void trimSpaces(std::string &string) {
	size_t start = 0;
	size_t end	 = string.length();

	while (start < string.length() && std::isspace(string[start]))
		++start;
	while (end > start && std::isspace(string[end - 1]))
		--end;

	string = string.substr(start, end - start);
}