#ifndef		__ISNAKE_HH__
#define		__ISNAKE_HH__

#include	<list>
#include	<iostream>
#include	<string>

class		ISnake
{
public:
  virtual std::list<ISnake *>		addElem(std::list<ISnake *> list, ISnake *member) = 0;
  virtual ~ISnake(){}
};

#endif
