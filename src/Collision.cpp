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
  if (food->getX() >= head->getX() && food->getX() <= head->getX())
    if (food->getY() >= head->getY() && food->getY() <= head->getY())
      return (true);
  return (false);
}

bool		Collision::checkSAndW()
{
  return (false);
}
