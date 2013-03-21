#include	"../headers/Game.hh"

Collision::Collision()
{

}

Collision::~Collision()
{

}

bool		Collision::checkSAndS(std::list<ISnake *> list)
{
  ISnake	*tmp;

  if (list.size() != 4)
    {
      tmp = list.front();
      for (std::list<ISnake *>::iterator it = list.begin(); it != list.end(); ++it)
	{
	  if (it != list.begin())
	    {
	      if ((tmp->getX() == (*it)->getX()) && (tmp->getY() == (*it)->getY()))
		return (true);
	    }
	}
    }
  return (false);
}

bool		Collision::checkSAndF(std::list<ISnake *> &slist, std::list<IFood *> &flist)
{
  ISnake	*head;

  head = slist.front();
  for (std::list<IFood *>::iterator it = flist.begin(); it != flist.end(); ++it)
    {
      if ((*it)->getX() >= head->getX() && (*it)->getX() <= head->getX())
	if ((*it)->getY() >= head->getY() && (*it)->getY() <= head->getY())
	  {
	    flist.erase(it);
	    return (true);
	  }
    }
  return (false);
}

bool		Collision::checkSAndW(std::list<ISnake *> list)
{
  ISnake	*head;

  head = list.front();
  if ((head->getX() > 0 && head->getX() < LWINDOW) && (head->getY() > 0 && head->getY() < HWINDOW))
    return (false);
  return (true);
}

void		Collision::displayCoord(std::list<ISnake *> list)
{
  for (std::list<ISnake *>::iterator it = list.begin(); it != list.end(); ++it)
    std::cout << (*it)->getX() << "\t" << (*it)->getY() << std::endl;
}
