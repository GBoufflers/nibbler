#ifndef		__SNAKEFACT_H__
#define		__SNAKEFACT_H__

#include	"ISnake.hh"

class		SnakeFact
{
private:
  ISnake	*newHead();
  ISnake	*newBody();
  ISnake	*newTail();
  ISnake	*(SnakeFact::*creation[3])();
public:
  SnakeFact();
  ~SnakeFact();
  ISnake	*create(ISnakeType type);
  void		initTab();

};

#endif
