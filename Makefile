NAME=	nibbler

CXX=	g++ -g -Wall -Wextra -W

CC=	$(CXX)

OBJ=	src/main.o\
	src/Head.o\
	src/Body.o\
	src/Tail.o\
	src/Snake.o\
	src/Power.o\
	src/Poison.o\
	src/Cake.o\
	src/Food.o\
	src/Collision.o\
	src/SnakeFact.o


all:	$(NAME)

$(NAME): $(OBJ)
	 $(CXX) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all