#ifndef		__Collision_HH__
#define		__Collision_HH__

#include	"../headers/ISnake.hh"
#include	"../headers/IFood.hh"

class		Collision
{
public:
  Collision();
  ~Collision();
  bool		checkSAndS();
  bool		checkSAndF(std::list<ISnake *> slist, std::list<IFood *> flist) const;
  bool		checkSAndW(std::list<ISnake *>);
};

#endif
