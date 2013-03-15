#include	"../headers/StratFact.hh"

StratFact::StratFact()

{  initTab();
}

StratFact::~StratFact()
{

}

void	StratFact::initTab()
{
  this->creation[0] = &StratFact::newEasy;
  this->creation[1] = &StratFact::newMedium;
  this->creation[2] = &StratFact::newHard;
}

IStrategie	*StratFact::newEasy()
{
  return (new Strategie::Easy());
}

IStrategie	*StratFact::newMedium()
{
  return (new  Strategie::Medium);
}

IStrategie	*StratFact::newHard()
{
  return (new  Strategie::Hard);
}

IStrategie	*StratFact::create(IStrategieType type)
{
  if (type >= 0 && type <= 2)
    return ((this->*creation[type])());
  return NULL;
}
