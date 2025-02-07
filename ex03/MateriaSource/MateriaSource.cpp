/*********************************************************************************
*                              Author: Alexy Heitz                               *
*            File Name: /CPP-04/ex03/MateriaSource/MateriaSource.cpp             *
*                    Creation Date: February 3, 2025 02:46 PM                    *
*                    Last Updated: February 5, 2025 10:53 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                 To draw the maximum of the power of the spells                 *
*********************************************************************************/

#include "./../output.hpp"
#include "./MateriaSource.hpp"
#include "./../AMateria/AMateria.hpp"

/********************************************************************************/

MateriaSource::MateriaSource(void)							{ setMateriasTab(NULL, true);																	}
MateriaSource::MateriaSource(const MateriaSource &source)	{ setMateriasTab(NULL, true), setMateriasTab((const AMateria* const*)source._materia, false);	}

MateriaSource &MateriaSource::operator=(const MateriaSource &source) {
	if (this != &source) {
		setMateriasTab(NULL, false);
		setMateriasTab((const AMateria* const*)source._materia, false);
	}
	return *this;
}

MateriaSource::~MateriaSource(void) { setMateriasTab(NULL, false); }

/********************************************************************************/

void MateriaSource::setMateriasTab(const AMateria* const context[4], const bool first) {
	for (int i = 0; i < 4 ; i++) {
		if (first) {
			_materia[i] = NULL;
			continue;
		}
		else if (_materia[i])
			delete _materia[i];
		_materia[i] = (context and context[i]) ? context[i]->clone() : NULL;
	}
}

/********************************************************************************/

void MateriaSource::learnMateria(AMateria* materia) {
	if (materia)
		for (int i = 0; i < 4 ; i++)
			if (!_materia[i]) {
				_materia[i] = materia->clone();
				std::cout << "The new spell " << GREEN << materia->getType() << RESET << " was well add in the slot " << BLUE << i << RESET << "!\n" << std::endl;
				return;
			}
	std::cout << RED << "The source is full, impossible to save a new spell!" << RESET << '\n' << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 3 ; i >= 0 ; i--)
		if (_materia[i] and _materia[i]->getType() == type) {
			std::cout << "The spell " << GREEN << type << RESET << " has been created from the source " << BLUE << i << RESET << "!" << std::endl;
			return _materia[i]->clone();
		}
	std::cout << RED << "The type of spell was not found in the source!" << RESET << '\n' << std::endl;
	return 0;
}