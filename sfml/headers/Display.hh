#ifndef		__DISPLAY_HH__
#define		__DISPLAY_HH__

#include	<list>
#include        <cstdlib>
#include        <unistd.h>
#include        <SFML/Graphics.hpp>
#include	<iostream>
#include	"../../headers/Game.hh"

const int	LARGEUR  = 20;
const int	HAUTEUR  = 20;
const int	LWINDOW  = 800;
const int	HWINDOW  = 600;
const int	PIX	 = 32;

class		Display
{
private:
  sf::RenderWindow			_app;
  sf::Event				_event;
  bool					_isInit;
  std::list<sf::Sprite>			_SnakeSpriteList;
  std::list<sf::Sprite>			_FoodSpriteList;
  char					_numFunc;
  void					(Display::*creation[4])();
public:
  Display();
  ~Display();
  virtual void	Dinit(std::list<ISnake *> sList, std::list<IFood *> fList);
  virtual bool	Window() const;
  virtual void	Play(std::list<ISnake *> sList, std::list<IFood *> fList);
  void		addElem(int x, int y, std::string name);
  void		DisplayGame();
  void		Up();
  void		Down();
  void		Left();
  void		Right();
  void		manageEvent();
};

typedef Display *(*maker_Display)();

#endif
