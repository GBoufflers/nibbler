#include	"../headers/Strategie.hh"

Strategie::Easy::Easy()
{
  this->_type = EASY;
  this->_speed = 70000;
  this->_nbFood = 3;
}

Strategie::Easy::~Easy()
{

}

IStrategieType		Strategie::Easy::getType() const
{
  return (_type);
}

int	Strategie::Easy::getSpeed() const
{
  return (_speed);
}

void	Strategie::Easy::setSpeed(int speed)
{
  this->_speed = speed;
}

/******************************/

Strategie::Medium::Medium()
{
  this->_type = MEDIUM;
  this->_speed = 55000;
  this->_nbFood = 2;
}

Strategie::Medium::~Medium()
{

}

IStrategieType		Strategie::Medium::getType() const
{
  return (_type);
}

int	Strategie::Medium::getSpeed() const
{
  return (_speed);
}

void	Strategie::Medium::setSpeed(int speed)
{
  this->_speed = speed;
}

/******************************/

Strategie::Hard::Hard()
{
  this->_type = EASY;
  this->_speed = 45000;
  this->_nbFood = 1;
}

Strategie::Hard::~Hard()
{

}

IStrategieType		Strategie::Hard::getType() const
{
  return (_type);
}

int	Strategie::Hard::getSpeed() const
{
  return (_speed);
}

void	Strategie::Hard::setSpeed(int speed)
{
  this->_speed = speed;
}
