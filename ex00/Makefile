##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: CPP-04/ex00/Makefile                         #
#                   Creation Date: January 30, 2025 11:12 AM                     #
#                    Last Updated: January 30, 2025 11:18 AM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= Polymorphism

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98

SOURCE		= main.cpp					\
			Animal/Animal.cpp			\
			Cat/Cat.cpp					\
			Dog/Dog.cpp					\
			WrongAnimal/WrongAnimal.cpp	\
			WrongCat/WrongCat.cpp		\
			utilities/getInputLine.cpp	\
			utilities/sameString.cpp	\
			utilities/trimSpaces.cpp	\

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