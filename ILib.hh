#ifndef		__ILIB_HH__
#define		__ILIB_HH__

#include	"./headers/Game.hh"

class		ILib
{
public:
  virtual bool	Window() const = 0;
  virtual void	Play(std::list<ISnake *> &sList, std::list<IFood *> &fList) = 0;
  virtual bool	Init() = 0;
  virtual ~ILib(){};
};

#endif
