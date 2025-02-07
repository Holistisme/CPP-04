/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-04/ex03/main.hpp                        *
*                    Creation Date: February 4, 2025 10:29 AM                    *
*                    Last Updated: February 7, 2025 11:37 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                         The source of a magical story!                         *
*********************************************************************************/

#include "./Character/Character.hpp"
#include "./Cure/Cure.hpp"
#include "./Ice/Ice.hpp"
#include "./Interface/IMateriaSource.hpp"
#include "./MateriaSource/MateriaSource.hpp"
#include "./output.hpp"

/********************************************************************************/

typedef int index;

/********************************************************************************/

typedef struct programMemory {
	IMateriaSource	*source;
	ICharacter		*you;
	ICharacter		*bro;
	Cure			*cure;
	Ice				*ice;
}	programMemory;

/********************************************************************************/

#define forever true
#define SIGNAL	'\033'

/********************************************************************************/

#include <csignal>
#include <cstdlib>
#include <limits>

/********************************************************************************/

std::string	getInputLine(void);
void		handleSigInt(int signal) ;
bool		sameString(const std::string &first, const std::string &second);

void 		manageMemory(programMemory *memory);