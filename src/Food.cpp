#include		"../headers/Food.hh"

Food::Food()
{

}

Food::~Food()
{

}

std::list<IFood *>		Food::addElem(std::list<IFood *> list, IFood *member)
{
  list.push_front(member);
  return (list);
}
