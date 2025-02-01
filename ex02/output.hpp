/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-04/ex02/output.hpp                       *
*                    Creation Date: January 30, 2025 11:32 AM                    *
*                    Last Updated: February 1, 2025 07:28 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                          To make the terminal happy!                           *
*********************************************************************************/

#pragma once

/********************************************************************************/

#define RESET						"\033[0m"

/********************************************************************************/

#define BLACK						"\033[30m"
#define RED							"\033[31m"
#define GREEN						"\033[32m"
#define YELLOW						"\033[33m"
#define BLUE						"\033[34m"
#define WHITE						"\033[37m"

#define BG_RED						"\033[41m"
#define BG_GREEN					"\033[42m"
#define BG_YELLOW					"\033[43m"
#define BG_BLUE						"\033[44m"

#define BG_BRIGHT_WHITE				"\033[107m"

#define READABLE_BG_BRIGHT_WHITE	BG_BRIGHT_WHITE BLACK

/********************************************************************************/

#define	PROGRAM						YELLOW	"Abstract class"
#define	EXIT_MESSAGE				"Thank you for testing "	PROGRAM	RESET	"!"

#define ERROR						BG_RED	"ERROR:"		RESET	RED	" "
#define	EOF							RED		"\nShutdown: "	RESET	EXIT_MESSAGE