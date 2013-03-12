#ifndef		__SNAKEFACT_H__
#define		__SNAKEFACT_H__

#include	"ISnake.hh"

class		SnakeFact
{
private:

public:
  SnakeFact();
  ~SnakeFact();
  ISnake	*create(std::string &name);
  ISnake	*newHead();
  ISnake	*newBody();
  ISnake	*newTail();
};

#endif
