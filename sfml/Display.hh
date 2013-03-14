#ifndef __DISPLAY_HH__
#define __DISPLAY_HH__

#include        <cstdlib>
#include        <unistd.h>
#include        <SFML/Graphics.hpp>
#include	<iostream>

class Display
{
public:
  virtual void Dinit();
};

typedef Display *(*make_graph)();

#endif
