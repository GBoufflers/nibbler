#ifndef		__IFOOD_HH__
#define		__IFOOD_HH__

#include	<list>
#include	<iostream>
#include	<string>

enum		IFoodType
  {
    CAKE,
    POISON,
    POWER
  };

class		IFood
{
public:
  virtual std::list<IFood *>		addElem(std::list<IFood *> list, IFood *member) = 0;
  virtual IFoodType			getType() const = 0;
  virtual void				setType(IFoodType type) = 0;
  virtual ~IFood(){}
};

#endif
