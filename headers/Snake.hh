#ifndef		__SNAKE_HH__
#define		__SNAKE_HH__

#include	"ISnake.hh"

class		Snake : public ISnake
{
public: 
  Snake();
  virtual ~Snake();
  virtual std::list<ISnake *>		addElem(std::list<ISnake *> list, ISnake *member);
};

#endif
