#include	"../sfml/headers/Display.hh"

int	main(int ac, char **av)
{
  if (ac == 4)
    {
      Game			*game = new Game(atoi(av[1]), atoi(av[2]));
      maker_Display		pMaker;
      void			*hndl;
      void			*mkr;

      hndl = dlopen(av[3], RTLD_LAZY);
      mkr = dlsym(hndl, "make_display");
      pMaker = (maker_Display)mkr;
      Display *my_graph = pMaker();
      while (my_graph->Window() == true)
	{
	  game->setSList(my_graph->Play(game->getSList(), game->getFList(), game->getSnakeI(), game->getFoodI()));
	  //game->checkCollision(game->getSList(), game->getFList());
	  usleep(game->getSpeed());
	}
      dlclose(hndl);
    }
  else
    std::cout << "Usage : ./nibbler LEN WIDTH LIB" << std::endl ;
  return (0);
}
