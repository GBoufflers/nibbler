#include	"../headers/SnakeFact.hh"
#include	"../headers/Head.hh"
#include	"../headers/Body.hh"
#include	"../headers/Tail.hh"

SnakeFact::SnakeFact()
{
  initTab();
}

SnakeFact::~SnakeFact()
{

}

void	SnakeFact::initTab()
{
  this->creation[0] = &SnakeFact::newHead;
  this->creation[1] = &SnakeFact::newBody;
  this->creation[2] = &SnakeFact::newTail;
}

ISnake	*SnakeFact::newHead()
{
  ISnake	*member;

  member = new Head();
  return (member);
}

ISnake	*SnakeFact::newBody()
{
  ISnake	*member;

  member = new Body();
  return (member);
}

ISnake	*SnakeFact::newTail()
{
  ISnake	*member;

  member = new Body();
  return (member);
}

ISnake	*SnakeFact::create(ISnakeType type)
{
  if (type >= 0 && type <= 2)
    return ((this->*creation[type])());
  return NULL;
}
