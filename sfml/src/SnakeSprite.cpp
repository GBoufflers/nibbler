#include	"../headers/SnakeSprite.hh"

Snake::Snake()
{

}
 
Snake::~Snake()
{

}

void		Snake::setImage(sf::Image image)
{
  this->_image = image;
}

void		Snake::setSprite(sf::Sprite sprite)
{
  this->_sprite = sprite;
}

void		Snake::setY(int y)
{
  this->_y = y;
}

void		Snake::setX(int x)
{
  this->_x = x;
}

/*************/

int		Snake::getY() const
{
  return (this->_y);
}

int		Snake::getX() const
{
  return (this->_x);
}
