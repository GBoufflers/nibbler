#include		"../headers/Snake.hh"

Snake::Snake()
{

}

Snake::~Snake()
{

}

/**********************************************/

void				Snake::setX(int x)
{
  this->_x = x;
}

void				Snake::setY(int y)
{
  this->_y = y;
}

void				Snake::setOldX(int x)
{
  this->_oldX = x;
}

void				Snake::setOldY(int y)
{
  this->_oldY = y;
}

void				Snake::setType(ISnakeType type)
{
  this->_type = type;
}

/**********************************************/

ISnakeType			Snake::getType() const
{
  return (this->_type);
}

int				Snake::getX() const
{
  return (this->_x);
}

int				Snake::getY() const
{
  return (this->_y);
}

int				Snake::getOldX() const
{
  return (this->_oldX);
}

int				Snake::getOldY() const
{
  return (this->_oldY);
}

/**********************************************/

std::list<ISnake *>		Snake::addElem(std::list<ISnake *> list, ISnakeType type)
{
  ISnake	*member;

  member = new Snake;
  member->setType(type);
  list.push_front(member);
  return (list);
}
