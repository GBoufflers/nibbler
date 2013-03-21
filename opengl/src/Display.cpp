//
// Display.cpp for display in /home/dell-a_f//projets/nib/opengl/src
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Tue Mar 19 16:48:46 2013 florian dell-aiera
// Last update Thu Mar 21 11:40:39 2013 florian dell-aiera
//

#include	"../headers/Display.hh"
#include	"../../headers/Game.hh"

Display::Display()
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("SDL GL Application", NULL);
  SDL_SetVideoMode(810, 600, 32, SDL_OPENGL);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 800,0,600);
}

Display::~Display()
{

}

bool	Display::Window() const
{
  return (true);
}

void	Display::makeCoord(std::list<ISnake *>sList)
{
  int	cpt = sList.size();
  std::list<ISnake *>::reverse_iterator it = sList.rbegin();
  std::list<ISnake *>::reverse_iterator it2;

  while (cpt > 1)
    {
      it2 = it;
      it2++;
      (*it)->setX((*it2)->getX());
      (*it)->setY((*it2)->getY());
      it++;
      cpt--;
    }
}

std::list<ISnake *>	Display::event(std::list<ISnake *>sList)
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
    { 
      switch(event.type)
  	{
  	case SDL_QUIT:
  	  exit(0);
  	  break;
  	case SDL_KEYDOWN:
  	  switch (event.key.keysym.sym)
  	    {
  	    case SDLK_LEFT:
  	      this->_angle -= 90;
  	      if (this->_angle == (-360))
  		this->_angle = 0;
	      break;
  	    case SDLK_RIGHT:
  	      this->_angle += 90;
  	      if (this->_angle == 360)
  		this->_angle = 0;
  	      break;
  	    }
  	}
    }
  if (this->_angle == 0)
    {
      this->makeCoord(sList);
      sList.front()->setX((sList.front()->getX()) - 20);
      return (sList);
    }
  if (this->_angle == (-90))
    {
      this->makeCoord(sList);
      sList.front()->setY((sList.front()->getY()) - 20);
      return (sList);
    }
  if (this->_angle == (-180))
    {
      this->makeCoord(sList);
      sList.front()->setX((sList.front()->getX()) + 20);
      return (sList);
    }
  if (this->_angle == (-270))
    {
      this->makeCoord(sList);
      sList.front()->setY((sList.front()->getY()) + 20);
      return (sList);
    }
  if (this->_angle == (90))
    {
      this->makeCoord(sList);
      sList.front()->setY((sList.front()->getY()) + 20);
      return (sList);
    }
  if (this->_angle == (180))
    {
      this->makeCoord(sList);
      sList.front()->setX((sList.front()->getX()) + 20);
      return (sList);
    }
  if (this->_angle == (270))
    {
      this->makeCoord(sList);
      sList.front()->setY((sList.front()->getY()) - 20);
      return (sList);
    }
}

void			Display::makeCarre(double x, double y, int r, int v, int b)
{
  glColor3ub(r, v, b);
  glVertex2d(-x/2, -y/2);
  glVertex2d(-x/2, y/2);
  glVertex2d(x/2, y/2);
  glVertex2d(x/2, -y/2);
}

void			Display::makeSnake(std::list<ISnake *> sList)
{
  this->_cpt = 0;
  for (std::list<ISnake *>::const_iterator it = sList.begin(); it != sList.end(); it++)
    {
      if (this->_cpt == 0)
  	{
  	  glMatrixMode(GL_MODELVIEW);
  	  glLoadIdentity();
  	  glTranslatef((*it)->getX(), (*it)->getY(), 0);
  	  glBegin(GL_QUADS);
  	  this->makeCarre(20, 20, 255, 0, 0);
  	  glEnd();
  	}
      else
  	{
  	  glMatrixMode(GL_MODELVIEW);
  	  glLoadIdentity();
  	  glTranslatef((*it)->getX(), (*it)->getY(), 0);
  	  glBegin(GL_QUADS);
  	  this->makeCarre(20, 20, 0, 255, 0);
  	  glEnd();
  	}
      this->_cpt++;
    }
}

void			Display::makeFood(std::list<IFood *> fList)
{
  std::list<IFood *>::iterator it = fList.begin();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef((*it)->getX(), (*it)->getY(), 0);
  glBegin(GL_QUADS);
  this->makeCarre(20, 20, 0, 0, 255);
  glEnd();
}

void			Display::see(std::list<ISnake *> sList, std::list<IFood *> fList)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  this->makeSnake(sList);
  this->makeFood(fList);
  glFlush();
  SDL_GL_SwapBuffers();
}

std::list<ISnake *>	Display::Play(std::list<ISnake *> sList, std::list<IFood *> fList, ISnake *s, IFood *f)
{
  this->see(sList, fList);
  sList = this->event(sList);
  this->see(sList, fList);
  return (sList);
}

extern "C"
{
  Display		*make_display()
  {
    return new	Display();
  }
}

