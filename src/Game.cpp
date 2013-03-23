#include <unistd.h>
#include		"../headers/Game.hh"

Game::Game(int len, int width)
{
  this->Init(len, width);
}

Game::~Game()
{

}

void			Game::Init(const int len, const int width)
{
  srand(time(NULL));
  this->_len = len;
  this->_width = width;
  this->_score = 0;
  this->_snake = new Snake();
  this->_collision = new Collision();
  this->_food = new Food();
  this->_stratFact = new StratFact();
  this->_strategie = this->_stratFact->create(EASY);
  this->_snake->addElem(this->_sList, HEAD, 400, 300);
  this->_snake->addElem(this->_sList, BODY, 380, 300);
  this->_snake->addElem(this->_sList, BODY, 360, 300);
  this->_snake->addElem(this->_sList, TAIL, 340, 300);
  this->_food->addElem(this->_fList, this->_sList);
  sleep(1);
  this->_food->addElem(this->_fList, this->_sList);
  sleep(1);
  this->_food->addElem(this->_fList, this->_sList);
}

int			Game::getSpeed() const
{
  return (this->_strategie->getSpeed());
}

int			Game::getLen() const
{
  return (this->_len);
}

std::list<ISnake *>	Game::getSList() const
{
  return (this->_sList);
}

std::list<IFood *>	Game::getFList() const
{
  return (this->_fList);
}

int			Game::getWidth() const
{
  return (this->_width);
}

void			Game::setLen(const int len)
{
  this->_len = len;
}

void			Game::setWidth(const int width)
{
  this->_width = width;
}

ISnake			*Game::getSnakeI() const
{
  return (this->_snake);
}

IFood			*Game::getFoodI() const
{
  return (this->_food);
}

Collision		*Game::getCollision() const
{
  return (this->_collision);
}

int			Game::checkCollision(std::list<ISnake *> &slist, std::list<IFood *> &flist) const
{
  if (this->_collision->checkSAndF(slist, flist) == true)
    return (1);
  if (this->_collision->checkSAndS(slist) == true)
    return (-1);
  if (this->_collision->checkSAndW(slist) == true)
    return (-1);
  return (0);
}


void			Game::setSList(const std::list<ISnake *> &list)
{
  this->_sList = list;
}

void			Game::updateSList(std::list<ISnake *> &list)
{
  ISnake	*back;

  back = new Snake();
  back->setX(list.back()->getX() - SIDE);
  back->setY(list.back()->getY());
  list.push_back(back);
}

void			Game::setFList(std::list<IFood *> &list)
{
  this->_fList = list;
}

void			Game::updateFList(std::list<IFood *> &list)
{
  while (this->_strategie->getNbFood() > list.size())
    this->_food->addElem(list, this->_sList);
}

void			Game::displayCoord() const
{
  for (std::list<ISnake *>::const_iterator it = this->_sList.begin(); it != this->_sList.end(); ++it)
    std::cout << (*it)->getX() << "\t" << (*it)->getY() << std::endl;
}

void			Game::analyseLevel()
{
  if (this->_sList.size() > 10 && this->_sList.size() < 15)
    {
      delete(this->_strategie);
      this->_strategie = this->_stratFact->create(MEDIUM);
    }
  else if (this->_sList.size() >= 15)
    {
      delete(this->_strategie);
      this->_strategie = this->_stratFact->create(HARD);
    }
}

int			Game::getScore() const
{
  return (this->_score);
}

void			Game::setScore()
{
  this->_score += this->_strategie->getPts();
}
