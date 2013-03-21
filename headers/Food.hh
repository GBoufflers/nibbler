#ifndef		__FOOD_HH__
#define		__FOOD_HH__

#include	<cstdio>
#include	<cstdlib>
#include	<ctime>
#include	"IFood.hh"

class		Food : public IFood
{
private:
  IFoodType				_type;
  int					_x;
  int					_y;
public: 
  Food();
  virtual ~Food();
  virtual void				addElem(std::list<IFood *> &list);
  virtual IFoodType			getType() const;
  virtual int				getX() const;
  virtual int				getY() const;
  virtual int				foodSize(std::list<IFood *> list) const;
  virtual void				setType(IFoodType type);
  virtual void				setX(int x);
  virtual void				setY(int y);
};

#endif
