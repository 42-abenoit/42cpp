CPP_SRC = main.cpp

CPP_OBJ = $(CPP_SRC:.cpp=.o)

CC = clang++

RM = rm -f

CPP_FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = identify

all:	$(NAME)

$(NAME):	$(CPP_OBJ)
	$(CC) $(CPP_FLAGS) -o $(NAME) $(CPP_OBJ)

%.o: %.cpp
	$(CC) $(CPP_FLAGS) -c $< -o $@

clean:
	$(RM) $(CPP_OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all	

.PHONY:	clean re fclean

