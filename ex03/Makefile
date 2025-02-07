##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: CPP-04/ex03/Makefile                         #
#                   Creation Date: January 30, 2025 11:12 AM                     #
#                    Last Updated: February 5, 2025 11:59 AM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= Interface_and_recap

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98

SOURCE		= main.cpp						\
			AMateria/AMateria.cpp			\
			Character/Character.cpp			\
			Cure/Cure.cpp					\
			Ice/Ice.cpp						\
			MateriaSource/MateriaSource.cpp	\
			utilities/getInputLine.cpp		\
			utilities/handleSigInt.cpp		\
			utilities/sameString.cpp		\

OBJECTS		= $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re