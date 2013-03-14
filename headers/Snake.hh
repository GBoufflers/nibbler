#ifndef		__SNAKE_HH__
#define		__SNAKE_HH__

#include	"ISnake.hh"

class		Snake : public ISnake
{
private:
  ISnakeType		_type;
  int			_x;
  int			_y;
  int			_oldX;
  int			_oldY;
public: 
  Snake();
  virtual ~Snake();
  virtual std::list<ISnake *>				addElem(std::list<ISnake *> list, ISnakeType type);
  /******************/
  virtual ISnakeType					getType() const;
  virtual int						getX() const;
  virtual int						getY() const;
  virtual int						getOldX() const;
  virtual int						getOldY() const;
  /******************/
  virtual void						setX(int x);
  virtual void						setY(int y);
  virtual void						setOldX(int x);
  virtual void						setOldY(int y);
  virtual void						setType(ISnakeType type);
};

#endif
