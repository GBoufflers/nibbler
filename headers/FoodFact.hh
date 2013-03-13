#ifndef		__FOODFACT_HH__
#define		__FOODFACT_HH__

#include	"IFood.hh"

class		FoodFact
{
private:
  IFood		*newCake();
  IFood		*newPoison();
  IFood		*newPower();
  IFood		*(FoodFact::*creation[3])();
public:
  FoodFact();
  ~FoodFact();
  IFood		*create(IFoodType type);
  void		initTab();
};

#endif
