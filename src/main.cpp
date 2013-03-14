#include	"../sfml/Display.hh"
#include	"../headers/Game.hh"

int	main(int ac, char **av)
{
  if (ac == 3)
    {
      Game		*game = new Game(atoi(av[1]), atoi(av[2]));
      make_graph	pMaker;
      void		*hndl;
      void		*mkr;

      hndl = dlopen("./lib_nibbler_sfml.so", RTLD_LAZY);
      mkr = dlsym(hndl, "make_graph");
      pMaker = (make_graph)mkr;
      Display *my_graph = pMaker();
      my_graph->Dinit();
      while (game->getIsWorking() == 1)
	{

	}
      dlclose(hndl);
    }
  else
    std::cout << "Usage : ./nibbler LEN WIDTH LIB" << std::endl;
  return (0);
}
