#include		"../headers/Game.hh"

Hole::Hole()
{

}

Hole::~Hole()
{

}

int	Hole::getX() const
{
  return (this->_x);
}

int	Hole::getY() const
{
  return (this->_y);
}

void	Hole::setX(int x)
{
  this->_x = x;
}

void	Hole::setY(int y)
{
  this->_y = y;
}
