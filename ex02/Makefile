##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: CPP-04/ex02/Makefile                         #
#                   Creation Date: January 30, 2025 11:12 AM                     #
#                    Last Updated: February 1, 2025 07:28 PM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= Abstract_class

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98

SOURCE		= main.cpp					\
			Animal/Animal.cpp			\
			Brain/Brain.cpp				\
			Cat/Cat.cpp					\
			Dog/Dog.cpp					\
			WrongAnimal/WrongAnimal.cpp	\
			WrongCat/WrongCat.cpp		\
			utilities/confirmAction.cpp	\
			utilities/getInputLine.cpp	\
			utilities/handleSigInt.cpp	\
			utilities/sameString.cpp	\

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