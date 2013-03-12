#ifndef		__IFOOD_HH__
#define		__IFOOD_HH__

#include	<list>
#include	<iostream>
#include	<string>

class		IFood
{
public:
  virtual std::list<IFood *>		addElem(std::list<IFood *> list, IFood *member) = 0;
  virtual ~IFood(){}
};

#endif
