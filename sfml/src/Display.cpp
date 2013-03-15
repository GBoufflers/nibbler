#include	"../headers/Display.hh"

Display::Display() : _app(sf::VideoMode(LWINDOW, HWINDOW, 32), "nibbler")
{
  this->_isInit = false;
}

Display::~Display()
{
  
}

void			Display::Dinit(std::list<ISnake *> sList, std::list<IFood *> fList)
{
  
}

bool			Display::Window() const
{
  return (this->_app.IsOpened());
}

void			Display::Play(std::list<ISnake *> sList, std::list<IFood *> fList)
{
  if (this->_isInit == false)
    this->Dinit(sList, fList);
}

extern "C"
{
  Display		*make_display()
  {
    return new	Display();
  }
}
