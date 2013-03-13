#ifndef		__ISNAKE_HH__
#define		__ISNAKE_HH__

#include	<list>
#include	<iostream>
#include	<string>

enum		ISnakeType
  {
    HEAD,
    BODY,
    TAIL
  };

class		ISnake
{
public:
  virtual std::list<ISnake *>		addElem(std::list<ISnake *> list, ISnake *member) = 0;
  virtual ISnakeType				getType() const = 0;
  virtual void					setType(ISnakeType type) = 0;
  virtual ~ISnake(){}
};

#endif
