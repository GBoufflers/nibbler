#ifndef		__ISNAKE_HH__
#define		__ISNAKE_HH__

#include	<list>
#include	<iostream>
#include	<string>

enum		ISnakeType
  {
    HEAD,
    BODY,
    TAIL
  };

class		ISnake
{
public:
  virtual std::list<ISnake *>				addElem(std::list<ISnake *> list, ISnakeType type) = 0;
  /****************/
  virtual ISnakeType					getType() const = 0;
  virtual int						getX() const = 0;
  virtual int						getY() const = 0;
  virtual int						getOldX() const = 0;
  virtual int						getOldY() const = 0;
  /***************/
  virtual void						setType(ISnakeType type) = 0;
  virtual void						setX(int x) = 0;
  virtual void						setY(int y) = 0;
  virtual void						setOldX(int x) = 0;
  virtual void						setOldY(int y) = 0;
  virtual ~ISnake(){}
};

#endif
