#include		"../headers/Game.hh"

Game::Game(int len, int width)
{
  this->Init(len, width);
}

Game::~Game()
{

}

void		Game::Init(int len, int width)
{
  this->_len = len;
  this->_width = width;
  this->_snake = new Snake();
  this->_food = new Food();
  this->_stratFact = new StratFact();
  this->_strategie = this->_stratFact->create(EASY);
  this->_sList = this->_snake->addElem(this->_sList, TAIL);
  this->_sList = this->_snake->addElem(this->_sList, BODY);
  this->_sList = this->_snake->addElem(this->_sList, BODY);
  this->_sList = this->_snake->addElem(this->_sList, HEAD);
}

int		Game::snakeSize() const
{
  return (_sList.size());
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
