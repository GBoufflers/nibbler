#include	"Display.hh"

void		Display::Dinit()
{

}


extern "C"
{
  Display	*make()
  {
    return new	Display();
  }
}
