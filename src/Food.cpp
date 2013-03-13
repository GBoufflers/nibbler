#include		"../headers/Food.hh"

Food::Food()
{

}

Food::~Food()
{

}

IFoodType			Food::getType() const
{
  return (this->_type);
}

void				Food::setType(IFoodType type)
{
  this->_type = type;
}

std::list<IFood *>		Food::addElem(std::list<IFood *> list, IFood *member)
{
  list.push_front(member);
  return (list);
}
