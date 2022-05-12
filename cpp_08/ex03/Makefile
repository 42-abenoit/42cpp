CPP_SRC += main.cpp
CPP_SRC += Turing.cpp

CPP_OBJ = $(CPP_SRC:.cpp=.o)

CC = clang++

RM = rm -f

CPP_FLAGS += -Wall
CPP_FLAGS += -Werror
CPP_FLAGS += -Wextra
CPP_FLAGS += -std=c++98
#CPP_FLAGS += -g
#CPP_FLAGS += -fsanitize=address
#CPP_FLAGS += -D BRAINFUCK=0
#CPP_FLAGS += -D NUM_OUT=0

NAME = Mindopen

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

