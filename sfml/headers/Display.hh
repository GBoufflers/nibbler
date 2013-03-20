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

class		Display :	public ILib
{
private:
  sf::RenderWindow		_app;
  sf::Event			_event;
  bool				_isInit;
  std::list<sf::Sprite *>	_SnakeSpriteList;
  std::list<sf::Sprite>		_FoodSpriteList;
  int				_numFunc;
  int				_snakeSize;
  void				(Display::*creation[4])(std::list<ISnake *> &);
public:
  Display();
  ~Display();
  virtual bool			Window() const;
  virtual std::list<ISnake *>	Play(std::list<ISnake *> sList, std::list<IFood *> fList, ISnake *s, IFood *f);
  void				Dinit(std::list<ISnake *> sList, std::list<IFood *> fList);
  void				setFood(std::list<IFood *> list, IFood *food);
  void				addSnakeSprite(std::list<ISnake *> sList);
  void				addElem(int x, int y, std::string name);
  void				DisplayGame();
  void				Up(std::list<ISnake *> &list);
  void				Down(std::list<ISnake *> &list);
  void				Left(std::list<ISnake *> &list);
  void				Right(std::list<ISnake *> &list);
  void				onOriginalList(std::list<ISnake *> &list, char func);
  void				manageEvent();
  void				setNewCoord(std::list<ISnake *> &list);
};

  typedef Display *(*maker_Display)();

#endif
