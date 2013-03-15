#include	"../headers/Display.hh"

Display::Display() : _app(sf::VideoMode(LWINDOW, HWINDOW, PIX), "nibbler")
{
  this->_isInit = false;
  this->_numFunc = 3;
  this->creation[0] = &Display::Up;
  this->creation[1] = &Display::Down;
  this->creation[2] = &Display::Left;
  this->creation[3] = &Display::Right;
}

Display::~Display()
{
  
}

void			Display::Up()
{
  sf::Sprite		newSprite;
  int			x;
  int			y;

  newSprite = this->_SnakeSpriteList.back();
  this->_SnakeSpriteList.pop_back();
  x = newSprite.GetPosition().x;
  y = newSprite.GetPosition().y;
  y -= 20;
  newSprite.SetPosition(x, y);
  this->_SnakeSpriteList.push_front(newSprite);
  // a finir
}

void			Display::Down()
{
  sf::Sprite		newSprite;
  int			x;
  int			y;

  newSprite = this->_SnakeSpriteList.back();
  this->_SnakeSpriteList.pop_back();
  x = newSprite.GetPosition().x;
  y = newSprite.GetPosition().y;
  y += 20;
  newSprite.SetPosition(x, y);
  this->_SnakeSpriteList.push_front(newSprite);
  // a finir
}

void			Display::Left()
{
  sf::Sprite		newSprite;
  int			x;
  int			y;

  newSprite = this->_SnakeSpriteList.back();
  this->_SnakeSpriteList.pop_back();
  x = newSprite.GetPosition().x;
  y = newSprite.GetPosition().y;
  x -= 20;
  newSprite.SetPosition(x, y);
  this->_SnakeSpriteList.push_front(newSprite);
  // a finir
}

void			Display::Right()
{
  sf::Sprite		newSprite;
  int			x;
  int			y;

  newSprite = this->_SnakeSpriteList.back();
  this->_SnakeSpriteList.pop_back();
  x = newSprite.GetPosition().x;
  y = newSprite.GetPosition().y;
  x += 20;
  newSprite.SetPosition(x, y);
  this->_SnakeSpriteList.push_front(newSprite);
  // a finir
}

void			Display::addElem(int x, int y, std::string name)
{
  std::string		SpriteLocation;
  sf::Sprite		sprite;
  sf::Image		image;

  SpriteLocation = "/home/guillaume/Git/nibbler/sprite/";
  SpriteLocation += name;
  if (!image.LoadFromFile(SpriteLocation))
    std::cout<<"Erreur durant le chargement de l'image"<< std::endl;
  sprite.SetImage(image);
  sprite.Resize(LARGEUR, HAUTEUR);
  sprite.SetPosition(x, y);
  this->_SnakeSpriteList.push_back(sprite);
}

void			Display::DisplayGame()
{
  for (std::list<sf::Sprite>::const_iterator it = this->_SnakeSpriteList.begin(); it != this->_SnakeSpriteList.end(); ++it)
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

void			Display::Play(std::list<ISnake *> sList, std::list<IFood *> fList)
{
  if (this->_isInit == false)
    this->Dinit(sList, fList);
  this->manageEvent();
  (this->*creation[this->_numFunc])();
  this->_app.Clear();
  this->DisplayGame();
}

extern "C"
{
  Display		*make_display()
  {
    return new	Display();
  }
}
