#include	"../headers/Game.hh"

int	main(int ac, char **av)
{
  Game		*game = new Game();

  std::cout << game->getSpeed() << std::endl;
  return (0);
}
