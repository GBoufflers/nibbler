#include		"../headers/Snake.hh"

Snake::Snake()
{

}

Snake::~Snake()
{

}

ISnakeType			Snake::getType() const
{
  return (this->_type);
}

void				Snake::setType(ISnakeType type)
{
  this->_type = type;
}

std::list<ISnake *>		Snake::addElem(std::list<ISnake *> list, ISnake *member)
{
  list.push_front(member);
  return (list);
}
