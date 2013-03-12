#include	"../headers/SnakeFact.hh"
#include	"../headers/Head.hh"
#include	"../headers/Body.hh"
#include	"../headers/Tail.hh"

SnakeFact::SnakeFact()
{

}

SnakeFact::~SnakeFact()
{

}

ISnake	*SnakeFact::newHead()
{
  return (new Head());
}

ISnake	*SnakeFact::newBody()
{
  return (new Body());
}

ISnake	*SnakeFact::newTail()

{  return (new Tail());
}

ISnake	*SnakeFact::create(std::string &name)
{
  return (new Head());
}
