/*********************************************************************************
*                              Author: Alexy Heitz                               *
*            File Name: /CPP-04/ex03/MateriaSource/MateriaSource.hpp             *
*                    Creation Date: February 3, 2025 01:43 PM                    *
*                    Last Updated: February 4, 2025 09:29 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                               A big magic source                               *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include "./../Interface/IMateriaSource.hpp"

/********************************************************************************/

#include <iostream>

/********************************************************************************/

class MateriaSource : public IMateriaSource {
	private:
		AMateria *_materia[4];

		void	setMateriasTab(const AMateria* const context[4], const bool first);
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &source);

		MateriaSource &operator=(const MateriaSource &source);

		virtual ~MateriaSource(void);

		void		learnMateria(AMateria*);
		AMateria	*createMateria(std::string const &type);
};