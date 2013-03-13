#ifndef		__FOODFACT_HH__
#define		__FOODFACT_HH__

#include	"IFood.hh"

class		FoodFact
{
private:

public:
  FoodFact();
  ~FoodFact();
  IFood		*create(std::string &name);
  IFood		*newFood();
  IFood		*newPoison();
  IFood		*newPower();
};

#endif
