#ifndef		__DISPLAY_HH__
#define		__DISPLAY_HH__

#include	<list>
#include        <cstdlib>
#include        <unistd.h>
#include        <SFML/Graphics.hpp>
#include	<iostream>
#include	"../../headers/Game.hh"
#include	"Sound.hh"
#include	"../../ILib.hh"

const int	LARGEUR  = 20;
const int	HAUTEUR  = 20;
const int	LWINDOW  = 800;
const int	HWINDOW  = 600;
const int	PIX	 = 32;

class		Display : public ILib
{
private:
  sf::RenderWindow			_app;
  sf::Event				_event;
  bool					_isInit;
  std::list<sf::Sprite>			_SnakeSpriteList;
  std::list<sf::Sprite>			_FoodSpriteList;
  char					_numFunc;
  int					_snakeSize;
  std::list<ISnake *>	       		(Display::*creation[4])(std::list<ISnake *>);
public:
  Display();
  ~Display();
  void	Dinit(std::list<ISnake *> sList, std::list<IFood *> fList);
  virtual bool	Window() const;
  virtual std::list<ISnake *>	Play(std::list<ISnake *> sList, std::list<IFood *> fList, ISnake *s, IFood *f);
  void				setFood(std::list<IFood *> list, IFood *food);
  void				addSnakeSprite(std::list<ISnake *> sList);
  void				ProcessMove(sf::Sprite *newSprite, int *x, int *y);
  void				FinishMove(sf::Sprite newSprite, int x, int y);
  void				addElem(int x, int y, std::string name);
  void				DisplayGame();
  std::list<ISnake *>		Up(std::list<ISnake *> list);
  std::list<ISnake *>		Down(std::list<ISnake *> list);
  std::list<ISnake *>		Left(std::list<ISnake *> list);
  std::list<ISnake *>		Right(std::list<ISnake *> list);
  std::list<ISnake *>		onOriginalList(std::list<ISnake *> list, char func);
  void				manageEvent();
};

  typedef Display *(*maker_Display)();

#endif
