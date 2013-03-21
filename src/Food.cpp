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
int				Food::foodSize(std::list<IFood *> list) const
{
  return (list.size());
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

std::list<IFood *>		Food::DeleteElem(std::list<IFood *> food)
{
  food.pop_back();
  return (food);
}

std::list<IFood *>		Food::addElem(std::list<IFood *> list)
{
  IFood		*member;
  int		x;
  int		y;

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
  return (list);
}
