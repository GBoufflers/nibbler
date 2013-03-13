#include	"../headers/FoodFact.hh"
#include	"../headers/IFood.hh"
#include	"../headers/Food.hh"
#include	"../headers/Cake.hh"
#include	"../headers/Poison.hh"
#include	"../headers/Power.hh"

FoodFact::FoodFact()
{
  initTab();
}


FoodFact::~FoodFact()
{

}

void	FoodFact::initTab()
{
  this->creation[0] = &FoodFact::newCake;
  this->creation[1] = &FoodFact::newPoison;
  this->creation[2] = &FoodFact::newPower;
}

IFood	*FoodFact::newCake()
{
  IFood		*member;

  member = new Cake;
  return (member);
}


IFood	*FoodFact::newPoison()
{
  IFood		*member;

  member = new Poison;
  return (member);
}

IFood	*FoodFact::newPower()
{
  IFood		*member;

  member = new Power;
  return (member);
}

IFood	*FoodFact::create(IFoodType type)
{
  if (type >= 0 && type <= 2)
    return ((this->*creation[type])());
  return NULL;
}
