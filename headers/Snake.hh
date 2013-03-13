#ifndef		__SNAKE_HH__
#define		__SNAKE_HH__

#include	"ISnake.hh"

class		Snake : public ISnake
{
private:
  ISnakeType		_type;
public: 
  Snake();
  virtual ~Snake();
  virtual std::list<ISnake *>		addElem(std::list<ISnake *> list, ISnake *member);
  virtual ISnakeType				getType() const;
  virtual void					setType(ISnakeType type);
};

#endif
