#ifndef		__DISPLAY_HH__
#define		__DISPLAY_H__

#include	<list>
#include        <cstdlib>
#include        <unistd.h>
#include	<SDL/SDL.h>
#include	<GL/gl.h>
#include	<GL/glu.h>
#include	<iostream>
#include	"../../headers/Game.hh"
#include	"../../ILib.hh"

class		Display : public ILib
{
  GLfloat	_angle;
public:
  Display();
  ~Display();
  virtual bool	Window() const;
  virtual void	Play(std::list<ISnake *> &sList, std::list<IFood *> &fList);
  std::list<ISnake*>	event(std::list<ISnake *> &sList);
  void			makeCarre(double x, double y, int r, int v, int b) const;
  void			see(std::list<ISnake *> &sList, std::list<IFood *> &fList);
  void			makeSnake(std::list<ISnake *> &sList) const;
  void			makeCoord(std::list<ISnake *> &sList);
  void			makeFood(std::list<IFood *> &fList);
};

typedef Display	*(*maker_Display)();

#endif
