/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                    File Name: /CPP-04/ex01/Brain/Brain.cpp                     *
*                    Creation Date: February 1, 2025 12:52 PM                    *
*                    Last Updated: February 1, 2025 07:06 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                           The functioning of a brain                           *
*********************************************************************************/

#include "./Brain.hpp"
#include "./../output.hpp"

/********************************************************************************/

Brain::Brain(void) {
	static const std::string subjects[] = {
		"I", "My instincts", "My paws", "My nose", "My tail",
		"My hunger", "My curiosity", "My nap", "My dreams", "My energy",
		"My playtime", "My bed", "My toys", "My fur", "My territory",
		"My speed", "My sharp claws", "My strong bite", "My wagging tail", "My powerful jumps"
	};
	static const std::string verbs[] = {
		"want", "need", "dream of", "hope for", "imagine",
		"fear", "chase", "sniff", "guard", "watch",
		"hunt", "play with", "protect", "hide", "find",
		"eat", "enjoy", "destroy", "explore", "conquer"
	};
	static const std::string objects[] = {
		"a delicious bone", "a warm spot to sleep", "a fast squirrel", "a hidden snack", "a fluffy pillow",
		"a long walk", "a playful friend", "a new toy", "a tasty treat", "a mysterious sound",
		"a running rabbit", "a challenging puzzle", "a fun game", "a big adventure", "a good scratch",
		"a tasty fish", "a rolling ball", "a comfy bed", "a soft blanket", "an exciting chase"
	};

	static const size_t subjectCount = sizeof(subjects) / sizeof(std::string);
	static const size_t verbCount	 = sizeof(verbs)	/ sizeof(std::string);
	static const size_t objectCount	 = sizeof(objects)	/ sizeof(std::string);

	for (size_t index = 0 ; index < 100 ; index++)
		ideas[index] = subjects[std::rand() % subjectCount] + " " +
					   verbs[std::rand()	% verbCount]	+ " " +
					   objects[std::rand()	% objectCount]	+ ".";
	
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< " A new mind awakens, filled with fresh thoughts!" << std::endl;
}

Brain::Brain(const Brain &source) {
	for (size_t index = 0 ; index < 100 ; index++)
		ideas[index] = source.ideas[index];
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< BG_GREEN << '[' << &source << ']' << RESET
		<< " A new mind has been cloned! Same thoughts, same memories..." << std::endl;
}

Brain &Brain::operator=(const Brain &source) {
	if (this != &source) {
		for (size_t index = 0 ; index < 100 ; index++)
			ideas[index] = source.ideas[index];
		std::cout << BG_BLUE << '[' << this << ']' << RESET
			<< BG_GREEN << '[' << &source << ']' << RESET
			<< " Thought transfer successful! Now we share the same ideas." << std::endl;
	} else {
		std::cout << BG_BLUE << '[' << this << ']' << RESET
			<< BG_GREEN << '[' << &source << ']' << RESET
			<< " I tried to overwrite my own mind... but nothing changed." << std::endl;
	}
	return *this;
}

Brain::~Brain(void) {
	std::cout << BG_BLUE << '[' << this << ']' << RESET
		<< " The mind fades away, its ideas lost in oblivion..." << std::endl;
}

/********************************************************************************/

void Brain::setIdea(const int index, const std::string &idea) { ideas[index] = idea; }

std::string Brain::getIdea(const int index) const { return ideas[index]; }