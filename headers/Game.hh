#ifndef		__GAME_HH__
#define		__GAME_HH__

#include	<iostream>
#include	<list>
#include	<dlfcn.h>
#include	<cstring>
#include	"Snake.hh"
#include	"Food.hh"
#include	"Collision.hh"
#include	"Strategie.hh"
#include	"StratFact.hh"

const int	SIDE     = 20;
const int	LWINDOW  = 800;
const int	HWINDOW  = 600;
const int	PIX	 = 32;

class		Game
{
private:
  std::list<ISnake *>		_sList;
  std::list<IFood *>		_fList;
  ISnake			*_snake;
  IFood				*_food;
  StratFact			*_stratFact;
  IStrategie			*_strategie;
  Collision			*_collision;
  int				_len;
  int				_width;
public:
  Game(int len, int width);
  ~Game();
  void				Init(int len, int width);
  ISnake			*getSnakeI() const;
  IFood				*getFoodI() const;
  int				getSpeed() const;
  int				getLen() const;
  int				getWidth() const;
  void				setLen(int len);
  void				setWidth(int width);
  std::list<ISnake *>		getSList() const;
  std::list<IFood *>		getFList() const;
  Collision			*getCollision() const;
  int				checkCollision(std::list<ISnake *> slist, std::list<IFood *> flist) const;
  std::list<ISnake *>		updateSList(std::list<ISnake *> list);
  void				setSList(std::list<ISnake *> list);
  void				setFList(std::list<IFood *> list);
  std::list<IFood *>		updateFList(std::list<IFood *> list);
  void				displayCoord();
  void				analyseLevel();
};

#endif
