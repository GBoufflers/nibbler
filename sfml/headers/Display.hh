#ifndef		__DISPLAY_HH__
#define		__DISPLAY_HH__

#include	<list>
#include        <cstdlib>
#include        <unistd.h>
#include        <SFML/Graphics.hpp>
#include	<iostream>
#include	"../../headers/Game.hh"
#include	"Sound.hh"

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
  int					_snakeSize;
  void					(Display::*creation[4])(std::list<ISnake *>);
public:
  Display();
  ~Display();
  virtual void	Dinit(std::list<ISnake *> sList, std::list<IFood *> fList);
  virtual bool	Window() const;
  virtual std::list<ISnake *>	Play(std::list<ISnake *> sList, std::list<IFood *> fList, ISnake *s, IFood *f);
  void		setFood(std::list<IFood *> list, IFood *food);
  void		addSnakeSprite(std::list<ISnake *> sList);
  void		ProcessMove(sf::Sprite *newSprite, int *x, int *y);
  void		FinishMove(sf::Sprite newSprite, int x, int y);
  void		addElem(int x, int y, std::string name);
  void		DisplayGame();
  void		Up(std::list<ISnake *> list);
  void		Down(std::list<ISnake *> list);
  void		Left(std::list<ISnake *> list);
  void		Right(std::list<ISnake *> list);
  void		manageEvent();
};

  typedef Display *(*maker_Display)();

#endif
