#ifndef		__HOLE_HH__
#define		__HOLE_HH__

#include	"IHole.hh"

class	Hole : public IHole
{
private:
  int		_x;
  int		_y;
public
:  Hole();
  ~Hole();
  //
  int	getX() const;
  int	getY() const;
  //
  void	setX(int x);
  void	setY(int y);
};

#endif
