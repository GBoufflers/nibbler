#include	"../sfml/Display.hh"
#include	"../headers/Game.hh"

int	main(int ac, char **av)
{
  if (ac == 4)
    {
      Game		*game = new Game(atoi(av[1]), atoi(av[2]));
      maker_Display	pMaker;
      void		*hndl;
      void		*mkr;

      hndl = dlopen("./lib_nibbler_sfml.so", RTLD_LAZY);
      mkr = dlsym(hndl, "make_display");
      pMaker = (maker_Display)mkr;
      Display *my_graph = pMaker();
      my_graph->Dinit();
      while (my_graph->Window() == true)
	{

	}
      dlclose(hndl);
    }
  else
    std::cout << "Usage : ./nibbler LEN WIDTH LIB" << std::endl;
  return (0);
}
