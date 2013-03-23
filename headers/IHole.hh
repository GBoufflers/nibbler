#ifndef		__IHOLE_HH__
#define		__IHOLE_HH__

class		IHole
{
public:
  virtual ~IHole(){}
  virtual int	getX() const = 0;
  virtual int	getY() const = 0;
  //
  virtual void	setX(int x) = 0;
  virtual void	setY(int y) = 0;
};

#endif
