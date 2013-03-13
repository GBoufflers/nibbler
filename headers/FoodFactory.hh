#ifndef		__FOODFACTORY_HH__
#define		__FOODFACTORY_HH__

#include	"IFood.hh"

class		FoodFact
{
private:

public:
  FoodFact();
  ~FoodFact();
  IFood		*create();
};

#endif
