/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-04/ex03/main.cpp                        *
*                    Creation Date: February 1, 2025 07:35 PM                    *
*                    Last Updated: February 7, 2025 11:51 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                        A program to bewitch his friends                        *
*********************************************************************************/

#include "./main.hpp"

/********************************************************************************/

static index	askIndex(void);
static void		createSource(programMemory *memory);
static void		equipCharacter(ICharacter *character, IMateriaSource *source);
static void		unequipCharacter(ICharacter *character);
static void		useMagic(ICharacter *you, ICharacter *bro);

/********************************************************************************/

/**
 * @brief The main test function.
 * 
 * @return int The exit code.
 */
int main(void) {
	try {
		std::cout << "\nWelcome in " << PROGRAM <<  "!\n" << std::endl;

		programMemory *memory = new programMemory;
		memory->bro = NULL;
		memory->you = NULL;
		memory->source = new MateriaSource();
		memory->cure = new Cure();
		memory->ice = new Ice();
		manageMemory(memory);
		
		handleSigInt(!SIGINT);
		createSource(memory);

		std::cout << '\n' << BG_BLUE << "It's time to create your character, give me your name:" << RESET << std::endl;
		std::string input = getInputLine();
		memory->you = new Character(input);

		std::cout << BG_GREEN << "It's time to create a bro, give me its name:" << RESET << std::endl;
		input = getInputLine();
		memory->bro = new Character(input);
		std::cout << std::endl;

		equipCharacter(memory->you, memory->source);
		equipCharacter(memory->bro, memory->source);

		unequipCharacter(memory->you);
		unequipCharacter(memory->bro);

		useMagic(memory->you, memory->bro);

		manageMemory(NULL);
		std::cout << '\n' << EXIT_MESSAGE << std::endl;
		return EXIT_SUCCESS;
	} catch (...) {
		std::cout << ERROR << "Perhaps I should have avoided all the allocations..." << std::endl;
		return EXIT_FAILURE;
	}
}

/**
 * @brief The loop to create the magic source.
 * 
 * @param memory The structure of the program.
 */
static void createSource(programMemory *memory) {
	while (forever) {
		std::cout << READABLE_BG_BRIGHT_WHITE << "Creation of a magical source:" << RESET << std::endl;
		std::cout << "🫀  - CURE" << std::endl;
		std::cout << "🧊 - ICE" << std::endl;
		std::cout << "🚪 - END" << std::endl;

		std::string input = getInputLine();
		if (sameString(input, "CURE"))
			memory->source->learnMateria(memory->cure);
		else if (sameString(input, "ICE"))
			memory->source->learnMateria(memory->ice);
		else if (sameString(input, "END"))
			break;
		else
			std::cout << ERROR << "You should think about thinking before sending an entrance!" << RESET << '\n' << std::endl;
	}
}

/**
 * @brief The loop to equip a character.
 * 
 * @param character The target character.
 * @param source The magic source.
 */
static void	equipCharacter(ICharacter *character, IMateriaSource *source) {
	while (forever) {
		AMateria *newEquipment = NULL;

		std::cout << READABLE_BG_BRIGHT_WHITE << "Let's equip " << character->getName() << RESET << std::endl;
		std::cout << "🫀  - CURE" << std::endl;
		std::cout << "🧊 - ICE" << std::endl;
		std::cout << "🚪 - END" << std::endl;

		std::string input = getInputLine();
		if (sameString(input, "CURE"))
			newEquipment = source->createMateria("cure");
		else if (sameString(input, "ICE"))
			newEquipment = source->createMateria("ice");
		else if (sameString(input, "END"))
			break;
		else
			std::cout << ERROR << "You should think about thinking before sending an entrance!" << RESET << '\n' << std::endl;
		
		if (newEquipment) {
			character->equip(newEquipment);
			delete newEquipment;
		}
	}
	std::cout << std::endl;
}

/**
 * @brief The loop to remove spells from a character.
 * 
 * @param character The target character.
 */
static void	unequipCharacter(ICharacter *character) {
	while (forever) {
		std::cout << READABLE_BG_BRIGHT_WHITE << "Maybe " << character->getName() << " have too much equipment " << RESET << std::endl;
		std::cout << "Enter the index to be deleted (between 0 and 3) or the " << RED << "-1" << RESET << " to go out!" << std::endl;

		index input = askIndex();
		if (input == -1)
			break;

		AMateria *unequipedSlot = NULL;
		Character* realCharacter = dynamic_cast<Character*>(character);
		if (realCharacter)
			unequipedSlot = realCharacter->getSlot(input);
		character->unequip(input);
		if (unequipedSlot)
			delete unequipedSlot;
	}
	std::cout << std::endl;
}

/**
 * @brief The main test function to throw spells from one character to another.
 * 
 * @param you The protagonist.
 * @param bro The antagonist.
 */
static void useMagic(ICharacter *you, ICharacter *bro) {
	std::cout << BG_YELLOW << "It's time to play with magic!" << RESET << std::endl;
	while (forever) {
		std::string	input;
		ICharacter	*trigger	= NULL;
		ICharacter	*target		= NULL;
		index		slot		= 0;

		std::cout << '\n' << BG_BLUE << "What character will be the cause of spell:" << RESET << std::endl;
		std::cout << "★  - YOU" << std::endl;
		std::cout << "☆  - BRO" << std::endl;
		std::cout << "🚪 - END" << std::endl;
		input = getInputLine();
		if (sameString(input, "YOU"))
			trigger = you;
		else if (sameString(input, "BRO"))
			trigger = bro;
		else if (sameString(input, "END"))
			break;
		else {
			std::cout << ERROR << "You should think about thinking before sending an entrance!" << RESET << '\n' << std::endl;
			continue;
		}

		std::cout << '\n' << BG_RED << "What character will be the target of spell:" << RESET << std::endl;
		std::cout << "★ - YOU" << std::endl;
		std::cout << "☆ - BRO" << std::endl;
		input = getInputLine();
		if (sameString(input, "YOU"))
			target = you;
		else if (sameString(input, "BRO"))
			target = bro;
		else {
			std::cout << ERROR << "You should think about thinking before sending an entrance!" << RESET << '\n' << std::endl;
			continue;
		}

		std::cout << '\n' << BG_GREEN << "What slot to use:" << RESET << std::endl;
		slot = askIndex();

		trigger->use(slot, *target);
	}
}

/**
 * @brief Asks the user to enter an index.
 * 
 * @return index The valid index.
 */
static index askIndex(void) {
	index number = 0;

	do {
		std::cin >> number;

		if (std::cin.eof()) {
			std::cout << EOF << std::endl;
			manageMemory(NULL);
			exit(EXIT_SUCCESS);
		}
		else if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << ERROR << "Invalid input. Enter an integer value!" << RESET << std::endl;
		}
		else
			break;
	} while (forever);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return number;
}

/********************************************************************************/

/**
 * @brief Saves the program allocations to leave properly in all circumstances.
 * 
 * @param memory The structure containing the allocations, or NULL to call to the deletes.
 */
void manageMemory(programMemory *memory) {
	static programMemory *save = NULL;

	if (!memory and save) {
		delete save->bro;	delete save->source;
		delete save->you;	delete save->ice;
		delete save->cure;	delete save;
	}
	save = memory;
}