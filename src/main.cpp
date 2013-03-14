#include	"../headers/Game.hh"

int	main(int ac, char **av)
{
  if (ac == 3)
    {
      Game		*game = new Game(atoi(av[1]), atoi(av[2]));
      while (game->getIsWorking() == 1)
	{

	}
    }
  else
    std::cout << "Usage : ./nibbler LEN WIDTH LIB" << std::endl;
  return (0);
}
