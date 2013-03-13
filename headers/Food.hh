#ifndef		__FOOD_HH__
#define		__FOOD_HH__

#include	"IFood.hh"

class		Food : public IFood
{
private:
  IFoodType				_type;
public: 
  Food();
  virtual ~Food();
  virtual std::list<IFood *>		addElem(std::list<IFood *> list, IFood *member);
  virtual IFoodType			getType() const;
  virtual void				setType(IFoodType type);
};

#endif
