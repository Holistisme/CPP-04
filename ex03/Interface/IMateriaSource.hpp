/*********************************************************************************
*                              Author: Alexy Heitz                               *
*              File Name: /CPP-04/ex03/Interface/IMateriaSource.hpp              *
*                    Creation Date: February 3, 2025 09:57 AM                    *
*                    Last Updated: February 3, 2025 10:56 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                      The interface of the source of magic                      *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include <iostream>

/********************************************************************************/

class AMateria;

/********************************************************************************/

class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}

		virtual void		learnMateria(AMateria *materia)			= 0;
		virtual AMateria	*createMateria(std::string const &type)	= 0;
};