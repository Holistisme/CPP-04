/*********************************************************************************
*                              Author: Alexy Heitz                               *
*               File Name: /CPP-04/ex01/utilities/handleSigInt.cpp               *
*                    Creation Date: February 1, 2025 06:03 PM                    *
*                    Last Updated: February 1, 2025 07:04 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                     Utility to manage interruption signals                     *
*********************************************************************************/

#include "./../main.hpp"

/********************************************************************************/

/**
 * @brief Handles the SIGINT signal (CTRL-C) for a clean program shutdown.
 *
 * This function is set as the handler for SIGINT using std::signal.
 * When CTRL-C is pressed, it cleans up resources and exits the program.
 *
 * @param signal The signal received (expected '!SIGINT' for initialization).
 */
void	handleSigInt(int signal) {
	if (signal == SIGINT) {
		std::cout << EOF << RESET << std::endl;
		manageZooMemory(NULL);
		exit(signal);
	}
	std::signal(SIGINT, handleSigInt);
}