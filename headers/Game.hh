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
  int				_score;
public:
  Game(int len, int width);
  ~Game();
  void				Init(const int len, const int width);
  ISnake			*getSnakeI() const;
  IFood				*getFoodI() const;
  int				getSpeed() const;
  int				getLen() const;
  int				getWidth() const;
  void				setLen(const int len);
  void				setWidth(const int width);
  void				setScore();
  int				getScore() const;
  std::list<ISnake *>		getSList() const;
  std::list<IFood *>		getFList() const;
  Collision			*getCollision() const;
  int				checkCollision(std::list<ISnake *> &slist, std::list<IFood *> &flist) const;
  void				updateSList(std::list<ISnake *> &list);
  void				setSList(const std::list<ISnake *> &list);
  void				setFList(std::list<IFood *> list);
  void				updateFList(std::list<IFood *> &list);
  void				displayCoord() const;
  void				analyseLevel();
};

#endif
