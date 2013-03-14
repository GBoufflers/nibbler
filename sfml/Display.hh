#ifndef __DISPLAY_HH__
#define __DISPLAY_HH__

#include        <cstdlib>
#include        <unistd.h>
#include        <SFML/Graphics.hpp>
#include	<iostream>

class Display
{
private:
  sf::RenderWindow	_app;
public:
  Display();
  ~Display();
  virtual void Dinit();
  virtual bool Window();
};

typedef Display *(*maker_Display)();

#endif
