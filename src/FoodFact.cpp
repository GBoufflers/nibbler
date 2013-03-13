#include	"../headers/FoodFact.hh"
#include	"../headers/Food.hh"
#include	"../headers/Poison.hh"
#include	"../headers/Power.hh"

FoodFact::FoodFact()
{

}


FoodFact::~FoodFact()
{

}


IFood	*FoodFact::newFood()
{
  return (new Food());
}


IFood	*FoodFact::newPoison()
{
  return (new Poison());
}

IFood	*FoodFact::newPower()
{
  return (new Power());
}
