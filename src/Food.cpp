#include		"../headers/Game.hh"

Food::Food()
{
  srand(time(NULL));
}

Food::~Food()
{

}

IFoodType			Food::getType() const
{
  return (this->_type);
}

int				Food::getX() const
{
  return (this->_x);
}

int				Food::getY() const
{
  return (this->_y);
}

/****************/

void				Food::setType(IFoodType type)
{
  this->_type = type;
}

void				Food::setX(int x)
{
  this->_x = x;
}

void				Food::setY(int y)
{
  this->_y = y;
}

void				Food::addElem(std::list<IFood *> &list, std::list<ISnake *> &slist)
{
  /*
    IFood		*member;
    bool		isHere;
    int		x;
    int		y;

    isHere = true;
    member = new Food();
    x = rand() % LWINDOW;
    y = rand() % HWINDOW;
    while (isHere == true)
    {
    isHere = false;
    while (x % SIDE != 0)
    x = rand() % LWINDOW;
    while (y % SIDE != 0)
    y = rand() % HWINDOW;      
    for (std::list<ISnake *>::const_iterator it = slist.begin(); it != slist.end(); ++it)
    if ((*it)->getX() == x && (*it)->getY() == y)
    isHere = true;
    }
    member->setX(x);
    member->setY(y);
    list.push_front(member);
  */
  IFood *member;
  int x;
  int y;

  member = new Food();
  x = rand() % LWINDOW;
  while (x % SIDE != 0)
    x = rand() % LWINDOW;
  member->setX(x);
  y = rand() % HWINDOW;
  while (y % SIDE != 0)
    y = rand() % HWINDOW;
  member->setY(y);
  list.push_front(member);
}
