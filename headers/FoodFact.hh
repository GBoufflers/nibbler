#ifndef		__FOODFACT_HH__
#define		__FOODFACT_HH__

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
