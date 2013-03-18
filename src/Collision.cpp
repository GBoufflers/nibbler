#include	"../headers/Game.hh"

Collision::Collision()
{

}

Collision::~Collision()
{

}

bool		Collision::checkSAndS()
{
  return (false);
}

bool		Collision::checkSAndF(std::list<ISnake *> slist, std::list<IFood *> flist) const
{
  ISnake	*head;
  IFood		*food;

  head = slist.front();
  food = flist.front();
  /*
    std::cout << food->getX()<< std::endl;
    std::cout << food->getY() << std::endl << std::endl;
  */
  std::cout << head->getX()<< std::endl;
  std::cout << head->getY() << std::endl << std::endl;
  if (food->getX() >= head->getX() && food->getX() <= head->getX())
    return (true);
  return (false);
}

bool		Collision::checkSAndM()
{
  return (false);
}
