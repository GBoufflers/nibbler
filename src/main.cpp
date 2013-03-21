//#include	"../sfml/headers/Display.hh"
#include	"../opengl/headers/Display.hh"

int	main(int ac, char **av)
{
  if (ac == 4)
    {
      Game			*game = new Game(atoi(av[1]), atoi(av[2]));
      int			ret;
      maker_Display		pMaker;
      void			*hndl;
      void			*mkr;

      hndl = dlopen(av[3], RTLD_LAZY);
      mkr = dlsym(hndl, "make_display");
      pMaker = (maker_Display)mkr;
      Display *my_graph = pMaker();
      ret = 0;
      while (my_graph->Window() == true && ret != -1)
	{
	  game->setSList(my_graph->Play(game->getSList(), game->getFList(), game->getSnakeI(), game->getFoodI()));
	  ret = game->checkCollision(game->getSList(), game->getFList());
	  if (ret == 1)
	    {
	      game->setSList(game->updateSList(game->getSList()));
	      game->setFList(game->updateFList(game->getFList()));
	    }
	  game->analyseLevel();
	  usleep(game->getSpeed());
	}
      dlclose(hndl);
    }
  else
    std::cout << "Usage : ./nibbler LEN WIDTH LIB" << std::endl;
  return (0);
}
