#ifndef		__GAME_HH__
#define		__GAME_HH__

#include	<iostream>
#include	<list>
#include	"Snake.hh"
#include	"Food.hh"
#include	"FoodFact.hh"
#include	"SnakeFact.hh"
#include	"Strategie.hh"

class		Game
{
private:
  std::list<ISnake *>		_sList;
  std::list<IFood *>		_fList;
  FoodFact			*_foodFact;
  SnakeFact			*_snakeFact;
  ISnake			*_snake;
  IFood				*_food;
  IStrategie			*_strategie;
  int				_len;
  int				_width;
public:
  Game();
  ~Game();
  void				Init();
  int				getSpeed() const;
  int				getLen() const;
  int				getWidth() const;
  void				setLen(int len);
  void				setWidth(int width);
};

#endif
