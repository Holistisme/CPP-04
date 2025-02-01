/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-04/ex00/main.cpp                        *
*                    Creation Date: January 30, 2025 11:13 AM                    *
*                    Last Updated: February 1, 2025 12:31 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*            Test program to verify that animals have all their paws             *
*********************************************************************************/

#include "./main.hpp"

/********************************************************************************/

static Animal	   wakeUpAnimal(void);
static WrongAnimal wakeUpWrongAnimal(void);
static Dog		   adoptDog(void);
static Cat		   adoptCat(void);
static WrongCat	   adoptWrongCat(void);

/********************************************************************************/

/**
 * @brief A test program for the first exercise of this project.
 * 
 * @return int The output code.
 */
int main(void) {
	try {
		Animal animal = wakeUpAnimal();
		WrongAnimal wrongAnimal = wakeUpWrongAnimal();

		Dog veritableDog = adoptDog();
		Cat veritableCat = adoptCat();
		WrongCat veritableWrongCat = adoptWrongCat();

		Animal &animalDog = veritableDog;
		Animal &animalCat = veritableCat;
		WrongAnimal &animalWrongCat = veritableWrongCat;

		std::cout << std::endl << BG_YELLOW << "You can now play with each of them!" << RESET << std::endl << std::endl;

		std::cout << BG_BLUE		   << "      ANIMAL       " << RESET << " - To play the sound of an animal class!"							<< std::endl;
		std::cout << BG_BRIGHT_MAGENTA << "   WRONG ANIMAL    " << RESET << " - To play the sound of a wrong animal class!"						<< std::endl;
		std::cout << BG_CYAN		   << "   VERITABLE DOG   " << RESET << " - To play the sound of a dog class!"								<< std::endl;
		std::cout << BG_GREEN		   << "    ANIMAL DOG     " << RESET << " - To play the sound of an animal class ascendant dog!"			<< std::endl;
		std::cout << BG_MAGENTA		   << "   VERITABLE CAT   " << RESET << " - To play the sound of a cat class!"								<< std::endl;
		std::cout << BG_BRIGHT_BLUE	   << "    ANIMAL CAT     " << RESET << " - To play the sound of an animal class ascendant cat!"			<< std::endl;
		std::cout << BG_BRIGHT_RED	   << "VERITABLE WRONG CAT" << RESET << " - To play the sound of a wrong cat class!"						<< std::endl;
		std::cout << BG_BRIGHT_CYAN	   << " ANIMAL WRONG CAT  " << RESET << " - To play the sound of a wrong animal class ascendant wrong cat!" << std::endl;
		std::cout << BG_RED			   << "       EXIT        " << RESET << " - To play the sound of a program that will stop!\n"				<< std::endl;

		while (forever) {
			std::string input = getInputLine();

			if (sameString(input, "VERITABLE DOG"))
				veritableDog.makeSound();
			else if (sameString(input, "ANIMAL DOG"))
				animalDog.makeSound();
			else if (sameString(input, "VERITABLE CAT"))
				veritableCat.makeSound();
			else if (sameString(input, "ANIMAL CAT"))
				animalCat.makeSound();
			else if (sameString(input, "VERITABLE WRONG CAT"))
				veritableWrongCat.makeSound();
			else if (sameString(input, "ANIMAL WRONG CAT"))
				animalWrongCat.makeSound();
			else if (sameString(input, "ANIMAL"))
				animal.makeSound();
			else if (sameString(input, "WRONG ANIMAL"))
				wrongAnimal.makeSound();
			else if (sameString(input, "EXIT"))
				break;
			else
				std::cout << ERROR << "I wonder who between the dog and you fill the bowl of the other!" << RESET << std::endl;
		}
		std::cout << std::endl << EXIT_MESSAGE << std::endl << std::endl;
	} catch (...) {
		std::cout << ERROR << "Something went wrong. I'll blame std::string!" << RESET << std::endl;
		return EXIT_FAILURE;
	}
    return EXIT_SUCCESS;
}

/**
 * @brief Quick test and return of an Animal.
 * 
 * @return Animal A copy of the test.
 */
static Animal wakeUpAnimal(void) {
	std::cout << std::endl << READABLE_BG_BRIGHT_WHITE << "We should test the Animal class!" << RESET << std::endl << std::endl;

	Animal anAnimal;
	Animal anotherAnimal(anAnimal);

	anAnimal = anotherAnimal;
	anAnimal.makeSound();

	return anAnimal;
}

/**
 * @brief Quick test and return of a WrongAnimal.
 * 
 * @return WrongAnimal A copy of the test.
 */
static WrongAnimal wakeUpWrongAnimal(void) {
	std::cout << std::endl << READABLE_BG_BRIGHT_WHITE << "No doubt a very bad idea, but we should test the Animal class!" << RESET << std::endl << std::endl;

	WrongAnimal aWrongAnimal;
	WrongAnimal anotherWrongAnimal(aWrongAnimal);

	aWrongAnimal = anotherWrongAnimal;
	aWrongAnimal.makeSound();

	return aWrongAnimal;
}

/**
 * @brief Quick test and return of a Dog.
 * 
 * @return Dog A copy of the test.
 */
static Dog adoptDog(void) {
	std::cout << std::endl << READABLE_BG_BRIGHT_WHITE << "We should adopt a dog!" << RESET << std::endl << std::endl;

	Dog aDog;
	Dog anotherDog(aDog);

	aDog = anotherDog;
	aDog.makeSound();

	return aDog;
}

/**
 * @brief Quick test and return of a Cat.
 * 
 * @return Cat A copy of the test.
 */
static Cat adoptCat(void) {
	std::cout << std::endl << READABLE_BG_BRIGHT_WHITE << "We should adopt a cat!" << RESET << std::endl << std::endl;

	Cat aCat;
	Cat anotherCat(aCat);

	aCat = anotherCat;
	aCat.makeSound();

	return aCat;
}

/**
 * @brief Quick test and return of a WrongCat.
 * 
 * @return WrongCat A copy of the test.
 */
static WrongCat adoptWrongCat(void) {
	std::cout << std::endl << READABLE_BG_BRIGHT_WHITE << "We shouldn't adopt a wrong cat, but we're still going to do it!" << RESET << std::endl << std::endl;

	WrongCat aWrongCat;
	WrongCat anotherWrongCat(aWrongCat);

	aWrongCat = anotherWrongCat;
	aWrongCat.makeSound();

	return aWrongCat;
}