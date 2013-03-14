#include		"../headers/Game.hh"

Game::Game()
{
  this->Init();
}

Game::~Game()
{

}

void		Game::Init()
{
  this->_snake = new Snake();
  this->_food = new Food();
  this->_stratFact = new StratFact();
  this->_strategie = this->_stratFact->create(EASY);  
}

int		Game::getSpeed() const
{
  return (this->_strategie->getSpeed());
}

int		Game::getLen() const
{
  return (this->_len);
}

int		Game::getWidth() const
{
  return (this->_width);
}

void		Game::setLen(int len)
{
  this->_len = len;
}

void		Game::setWidth(int width)
{
  this->_width = width;
}
