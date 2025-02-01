/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-04/ex02/main.cpp                        *
*                    Creation Date: January 30, 2025 11:13 AM                    *
*                    Last Updated: February 1, 2025 07:28 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*            Test program to verify that animals have all their paws             *
*********************************************************************************/

#include "./main.hpp"

/********************************************************************************/

static index askIndex(void);

/********************************************************************************/

/**
 * @brief A test program for the second exercise of this project.
 * 
 * @return int The output code.
 */
int main(void) {
	try {
		handleSigInt(!SIGINT);
		std::srand(std::time(NULL));

		Animal	*zoo[ZOO_SIZE];
		size_t	catCount = 0, dogCount = 0;
		for (size_t index = 0 ; index < ZOO_SIZE ; index++) {
			if ((std::rand() % 2 and catCount < ZOO_SIZE / 2) or dogCount >= ZOO_SIZE / 2)
				dynamic_cast<Cat*>(zoo[index] = new Cat())->setIndex(catCount++);
			else if (dogCount < ZOO_SIZE / 2 or catCount >= ZOO_SIZE / 2)
				dynamic_cast<Dog*>(zoo[index] = new Dog)->setIndex(dogCount++);
		}
		manageZooMemory(zoo);

		std::cout << std::endl << BG_YELLOW << "You can now play with all the zoo!" << RESET << std::endl << std::endl;
		while (forever) {
			std::cout << GREEN << "Animal index in the zoo:" << RESET << std::endl;
			index animalIndex = askIndex();
			if (animalIndex < 0 or animalIndex > ZOO_SIZE - 1) {
				std::cout << ERROR << "Index " << animalIndex << " is out of the zoo's door!" << RESET << std::endl;
				continue;
			}

			std::cout << GREEN << "Animal's idea index:" << RESET << std::endl;
			index ideaIndex	  = askIndex();
			if (ideaIndex < 0 or ideaIndex > 99) {
				std::cout << ERROR << "Idea " << ideaIndex << " is out of the user's comprehension scope!" << RESET << std::endl;
				continue;
			}

			Dog* dog = dynamic_cast<Dog*>(zoo[animalIndex]);
			Cat* cat = dynamic_cast<Cat*>(zoo[animalIndex]);

			zoo[animalIndex]->makeSound();
			if (dog)
				std::cout << "Dog #" << YELLOW << dog->getIndex() << RESET << ": " << dog->getIdea(ideaIndex) << std::endl;
			else if (cat)
				std::cout << "Cat #" << YELLOW << cat->getIndex() << RESET << ": " << cat->getIdea(ideaIndex) << std::endl;
			std::cout << std::endl;

			std::cout << RED << "Do you want to exit?" << RESET << std::endl;
			if (confirmAction())
				break;

			std::cout << std::endl;
		}
		std::cout << std::endl;

		manageZooMemory(NULL);

		std::cout << std::endl << EXIT_MESSAGE << std::endl << std::endl;
	} catch (...) {
		std::cout << ERROR << "Something went wrong. I'll blame std::string!" << RESET << std::endl;
		return EXIT_FAILURE;
	}
    return EXIT_SUCCESS;
}

/**
 * @brief Asks the user to enter an index.
 * 
 * @return index The valid index.
 */
static index askIndex() {
	index number = 0;

	do {
		std::cin >> number;

		if (std::cin.eof()) {
			std::cout << EOF << std::endl;
			manageZooMemory(NULL);
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

/**
 * @brief Allows to record the memory of the Animals table in case of signals.
 * 
 * @param zoo If indicated, saves the address, otherwise deletes it.
 */
void manageZooMemory(Animal **zoo) {
	static Animal **memory = NULL;

	for (size_t index = 0 ; memory and index < ZOO_SIZE ; index++)
		delete memory[index];
	memory = zoo;
}