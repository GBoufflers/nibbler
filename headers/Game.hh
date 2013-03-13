#ifndef		__GAME_HH__
#define		__GAME_HH__

#include	<iostream>
#include	<list>
#include	"ISnake.hh"
#include	"IFood.hh"
#include	"FoodFact.hh"
#include	"SnakeFact.hh"

class		Game
{
private:
  std::list<ISnake *>		_sList;
  std::list<IFood *>		_fList;
  FoodFact			*_foodFact;
  SnakeFact			*_snakeFact;
public:
  Game();
  ~Game();
  void				Init();
};


#endif
