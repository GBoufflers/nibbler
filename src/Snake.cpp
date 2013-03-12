#include		"../headers/Snake.hh"

Snake::Snake()
{

}

Snake::~Snake()
{

}

std::list<ISnake *>		Snake::addElem(std::list<ISnake *> list, ISnake *member)
{
  list.push_front(member);
  return (list);
}
