#include	"../headers/Display.hh"
#include	"../../headers/Game.hh"

Display::Display() :	_app(sf::VideoMode(LWINDOW, HWINDOW, PIX), "nibbler")
{
  this->_isInit = false;
  this->_numFunc = 3;
  this->_snakeSize = 4;
  this->creation[0] = &Display::Up;
  this->creation[1] = &Display::Down;
  this->creation[2] = &Display::Left;
  this->creation[3] = &Display::Right;
}

Display::~Display()
{
  
}

void			Display::onOriginalList(std::list<ISnake *> &list, char func)
{
  ISnake	*tmp;
  int		x;
  int		y;
  
  tmp = list.back();
  list.pop_back();
  x = list.front()->getX();
  y = list.front()->getY();
  if (func == 1)
    y -= 20;
  else if (func == 2)
    y += 20;
  else if (func == 3)
    x -= 20;
  else if (func == 4)
    x += 20;
  tmp->setX(x);
  tmp->setY(y);
  list.push_front(tmp);
}

void	Display::Up(std::list<ISnake *> &list)
{
  sf::Sprite		*newSprite;
  int			x;
  int			y;

  newSprite = this->_SnakeSpriteList.back();
  this->_SnakeSpriteList.pop_back();
  x = this->_SnakeSpriteList.front()->GetPosition().x;
  y = this->_SnakeSpriteList.front()->GetPosition().y;
  y -= 20;
  newSprite->SetPosition(x, y);
  this->_SnakeSpriteList.push_front(newSprite);
  this->onOriginalList(list, 1);
}

void	Display::Down(std::list<ISnake *> &list)
{
  sf::Sprite		*newSprite;
  int			x;
  int			y;

  newSprite = this->_SnakeSpriteList.back();
  this->_SnakeSpriteList.pop_back();
  x = this->_SnakeSpriteList.front()->GetPosition().x;
  y = this->_SnakeSpriteList.front()->GetPosition().y;
  y += 20;
  newSprite->SetPosition(x, y);
  this->_SnakeSpriteList.push_front(newSprite);
  this->onOriginalList(list, 2);
}

void	Display::Left(std::list<ISnake *> &list)
{
  sf::Sprite		*newSprite;
  int			x;
  int			y;

  newSprite = this->_SnakeSpriteList.back();
  this->_SnakeSpriteList.pop_back();
  x = this->_SnakeSpriteList.front()->GetPosition().x;
  y = this->_SnakeSpriteList.front()->GetPosition().y;
  x -= 20;
  newSprite->SetPosition(x, y);
  this->_SnakeSpriteList.push_front(newSprite);
  this->onOriginalList(list, 3);
}

void	Display::Right(std::list<ISnake *> &list)
{
  sf::Sprite		*newSprite;
  int			x;
  int			y;

  newSprite = this->_SnakeSpriteList.back();
  this->_SnakeSpriteList.pop_back();
  x = this->_SnakeSpriteList.front()->GetPosition().x;
  y = this->_SnakeSpriteList.front()->GetPosition().y;
  x += 20;
  newSprite->SetPosition(x, y);
  this->_SnakeSpriteList.push_front(newSprite);
  this->onOriginalList(list, 4);
}

void			Display::addElem(int x, int y, std::string name)
{
  std::string		SpriteLocation;
  sf::Sprite		*sprite;
  sf::Image		*image;

  sprite = new sf::Sprite();
  image = new sf::Image();
  SpriteLocation = "/home/guillaume/Git/nibbler/sprite/boule.png";
  if (!image->LoadFromFile(SpriteLocation))
    std::cout<<"Erreur durant le chargement de l'image"<< std::endl;
  sprite->SetImage(*image);
  sprite->Resize(SIDE, SIDE);
  sprite->SetPosition(x, y);
  this->_SnakeSpriteList.push_back(sprite);
}

void	       	Display::Play(std::list<ISnake *> &sList, std::list<IFood *> fList, ISnake *s, IFood *f)
{
  if (this->_isInit == false)
    this->Dinit(sList, fList);
  if (sList.size() != this->_snakeSize)
    {
      this->addSnakeSprite(sList);
      this->setFood(fList, f);
    }
  this->manageEvent();
  (this->*creation[this->_numFunc])(sList);
  this->setNewCoord(sList);
  this->setFood(fList, f);
  this->DisplayGame();
  this->_app.Clear();
  //  return (sList);
}

void			Display::DisplayGame()
{
  for (std::list<sf::Sprite *>::const_iterator it = this->_SnakeSpriteList.begin(); it != this->_SnakeSpriteList.end(); ++it)
    this->_app.Draw(**it);
  for (std::list<sf::Sprite>::const_iterator it = this->_FoodSpriteList.begin(); it != this->_FoodSpriteList.end(); ++it)
    this->_app.Draw(*it);
  this->_app.Display();
}

void			Display::Dinit(std::list<ISnake *> sList, std::list<IFood *> fList)
{
  this->_isInit = true;
  for (std::list<ISnake *>::const_iterator it = sList.begin(); it != sList.end(); ++it)
    this->addElem((*it)->getX(), (*it)->getY(), "boule.png");
}

bool			Display::Window() const
{
  return (this->_app.IsOpened());
}

void			Display::manageEvent()
{
  while (this->_app.GetEvent(this->_event))
    {
      if (this->_event.Type == sf::Event::Closed)
	this->_app.Close();
      if (this->_event.Type == sf::Event::KeyPressed)
	{
	  if (this->_event.Key.Code == sf::Key::Escape)
	    this->_app.Close();
	  else if (this->_event.Key.Code == sf::Key::Up)
	    this->_numFunc = 0;
	  else if (this->_event.Key.Code == sf::Key::Down)
	    this->_numFunc = 1;
	  else if (this->_event.Key.Code == sf::Key::Left)
	    this->_numFunc = 2;
	  else if (this->_event.Key.Code == sf::Key::Right)
	    this->_numFunc = 3;
	}
    }
}

void			Display::addSnakeSprite(std::list<ISnake *> sList)
{
  ISnake	*back;
  back = sList.back();
  this->addElem(back->getX(), back->getY(), "boule.png");
  this->_snakeSize += 1;
}

void			Display::setFood(std::list<IFood *> list, IFood *food)
{
  std::string		SpriteLocation;
  sf::Sprite		sprite;
  sf::Image		image;

  if (this->_FoodSpriteList.size() != 0)
    {
      food = list.front();
      sprite = this->_FoodSpriteList.front();
      this->_FoodSpriteList.pop_front();
    }
  else
    {
      SpriteLocation = "/home/guillaume/Git/nibbler/sprite/boule.png";
      if (!image.LoadFromFile(SpriteLocation))
	std::cout<<"Erreur durant le chargement de l'image"<< std::endl;
      sprite.SetImage(image);
      sprite.Resize(SIDE, SIDE);
      food = list.front();
    }
  sprite.SetPosition(food->getX(), food->getY());
  this->_FoodSpriteList.push_back(sprite);
}

void			Display::setNewCoord(std::list<ISnake *> &list)
{
  std::list<ISnake *>::iterator it2 = list.begin();
  for (std::list<sf::Sprite *>::iterator it = this->_SnakeSpriteList.begin(); it != this->_SnakeSpriteList.end(); ++it, ++it2)
    (*it)->SetPosition((*it2)->getX(), (*it2)->getY());
}

extern "C"
{
  Display		*make_display()
  {
    return new	Display();
  }
}
