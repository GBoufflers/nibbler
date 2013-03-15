#ifndef __DISPLAY_HH__
#define __DISPLAY_HH__

#include	<list>
#include        <cstdlib>
#include        <unistd.h>
#include        <SFML/Graphics.hpp>
#include	<iostream>
#include	"../../headers/Game.hh"

const int LARGEUR = 20;
const int HAUTEUR = 20;
const int LWINDOW = 800;
const int HWINDOW = 600;

class Display
{
private:
  sf::RenderWindow	_app;
  bool			_isInit;
public:
  Display();
  ~Display();
  virtual void Dinit(std::list<ISnake *> sList, std::list<IFood *> fList);
  virtual bool Window() const;
  virtual void Play(std::list<ISnake *> sList, std::list<IFood *> fList);
};

typedef Display *(*maker_Display)();

#endif
