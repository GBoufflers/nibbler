#ifndef		__Collision_HH__
#define		__Collision_HH__

#include	"../headers/ISnake.hh"
#include	"../headers/IFood.hh"

class		Collision
{
public:
  Collision();
  ~Collision();
  bool		checkSAndS(std::list<ISnake *>);
  bool		checkSAndF(std::list<ISnake *>, std::list<IFood *>);
  bool		checkSAndW(std::list<ISnake *>);
  void		displayCoord(std::list<ISnake *> list);
};

#endif
