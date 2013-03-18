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
  this->_collision = new Collision();
  this->_food = new Food();
  this->_stratFact = new StratFact();
  this->_strategie = this->_stratFact->create(EASY);
  this->_sList = this->_snake->addElem(this->_sList, HEAD, 400, 300);
  this->_sList = this->_snake->addElem(this->_sList, BODY, 380, 300);
  this->_sList = this->_snake->addElem(this->_sList, BODY, 360, 300);
  this->_sList = this->_snake->addElem(this->_sList, TAIL, 340, 300);
  this->_fList = this->_food->addElem(this->_fList);
}

int		Game::getSpeed() const
{
  return (this->_strategie->getSpeed());
}

int		Game::getLen() const
{
  return (this->_len);
}

std::list<ISnake *>		Game::getSList() const
{
  return (this->_sList);
}

std::list<IFood *>		Game::getFList() const
{
  return (this->_fList);
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

ISnake		*Game::getSnakeI() const
{
  return (this->_snake);
}

IFood		*Game::getFoodI() const
{
  return (this->_food);
}

Collision	*Game::getCollision() const
{
  return (this->_collision);
}

bool		Game::checkCollision(std::list<ISnake *> slist, std::list<IFood *> flist) const
{
  if (this->_collision->checkSAndF(slist, flist) == true)
    std::cout << "Ca match !!"<< std::endl;
  return (false);
}


void		Game::setSList(std::list<ISnake *> list)
{
  this->_sList = list;
}
