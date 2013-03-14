NAME=	nibbler

CXX=	g++ -g -Wall -Wextra -W

CC=	$(CXX)

OBJ=	src/main.o\
	src/Snake.o\
	src/Food.o\
	src/Collision.o\
	src/Game.o\
	src/Strategie.o\
	src/StratFact.o\

all:	$(NAME)

$(NAME): $(OBJ)
	 $(CXX) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all