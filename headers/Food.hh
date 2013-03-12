#ifndef		__FOOD_HH__
#define		__FOOD_HH__

#include	"IFood.hh"

class		Food : public IFood
{
public: 
  Food();
  virtual ~Food();
  virtual std::list<IFood *>		addElem(std::list<IFood *> list, IFood *member);
};

#endif
