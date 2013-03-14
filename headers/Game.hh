#ifndef		__GAME_HH__
#define		__GAME_HH__

#include	<iostream>
#include	<list>
#include	"Snake.hh"
#include	"Food.hh"
#include	"Strategie.hh"
#include	"StratFact.hh"

class		Game
{
private:
  std::list<ISnake *>		_sList;
  std::list<IFood *>		_fList;
  ISnake			*_snake;
  IFood				*_food;
  StratFact			*_stratFact;
  IStrategie			*_strategie;
  int				_len;
  int				_width;
  char				_isWorking;
public:
  Game(int len, int width);
  ~Game();
  void				Init(int len, int width);
  int				getSpeed() const;
  int				getLen() const;
  int				getWidth() const;
  char				getIsWorking() const;
  void				setLen(int len);
  void				setWidth(int width);
};

#endif
