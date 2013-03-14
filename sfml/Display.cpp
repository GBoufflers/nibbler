#include	"Display.hh"

Display::Display() : _app(sf::VideoMode(800, 600, 32), "nibbler")
{

}

Display::~Display()
{

}

void			Display::Dinit()
{
  
}

bool			Display::Window()
{
  return (this->_app.IsOpened());
}

extern "C"
{
  Display		*make_display()
  {
    return new	Display();
  }
}
