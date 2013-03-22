<<<<<<< HEAD
//#include	"../sfml/headers/Display.hh"
#include	"../opengl/headers/Display.hh"
=======
#include	"../sfml/headers/Display.hh"
#include	"../ncurses/headers/Display.hh"
>>>>>>> e712da655b39f5936d5a90bd7a9ee1d775104f67

int	main(int ac, char **av)
{
  if (ac == 4)
    {
      Game			*game = new Game(atoi(av[1]), atoi(av[2]));
      std::list<ISnake *>	tmp;
      std::list<IFood *>	tmpf;
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
	  tmp = game->getSList();
	  tmpf = game->getFList();
	  my_graph->Play(tmp, tmpf);
	  ret = game->checkCollision(tmp, tmpf);
	  if (ret == 1)
	    {
	      game->updateSList(tmp);
	      game->updateFList(tmpf);
	    }
	  game->setSList(tmp);
	  game->setFList(tmpf);
	  game->analyseLevel();
	  usleep(game->getSpeed());
	}
      dlclose(hndl);
    }
  else
    std::cout << "Usage : ./nibbler LEN WIDTH LIB" << std::endl;
  return (0);
}
