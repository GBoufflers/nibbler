#include	"../headers/Display.hh"
#include	"../../headers/Game.hh"

Display::Display()
{
  this->_maxheight = 33;
  this->_maxwidth = 42;
  //  getmaxyx(stdscr, this->_maxheight, this->_maxwidth);
  this->_partchar = 'x';
  this->_direction = 'l';
}

bool	Display::Init()
{
  /*std::cout << "Please enter your name: " << std::endl;
    std::cin >> this->_userName;*/
  initscr();
  this->_win = initscr();  
  wresize(this->_win, 33, 42);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  noecho();
  curs_set(0);
  return (true);
}

void    Display::drawWall() const
{
  for (int i=0; i < this->_maxwidth; i++)
    {
      move(0, i);
      addch('-');
    }
  for (int i=0; i < this->_maxheight-3; i++)
    {
      move(i, 0);
      addch('|');
    }
  for (int i=0; i < this->_maxwidth; i++)
    {
      move(i, this->_maxwidth-1);
      addch('|');
    }
  for (int i=0; i < this->_maxwidth; i++)
    {
      move(this->_maxheight-3, i);
      addch('-');
    }
  refresh();
}

bool	Display::Window() const
{
  return (true);
}

void   		Display::dispFood(std::list<IFood *> list) const
{
  move(list.front()->getY()/20, list.front()->getX()/20);
  addch('+');
}

void		Display::movesnake(std::list<ISnake *> &sList, std::list<IFood *> &fList)
{
  int   tmp = getch();
  ISnake	*s;
  
  this->drawWall();
  this->dispFood(fList);
  switch (tmp)
    {
    case KEY_LEFT:
      if (this->_direction != 'r')
        this->_direction = 'l';
      break;
    case KEY_UP:
      if (this->_direction != 'd')
        this->_direction = 'u';
      break;
    case KEY_DOWN:
      if (this->_direction != 'u')
        this->_direction = 'd';
      break;
    case KEY_RIGHT:
      if (this->_direction != 'l')
        this->_direction = 'r';
      break;
    case KEY_BACKSPACE:
      this->_direction = 'q';
      break;
    case 27:
      endwin();
      exit(EXIT_SUCCESS);
      break;
    }
  move((sList.back()->getY())/20, (sList.back()->getX())/20);
  addch(' ');
  refresh();
  s = sList.back();
  sList.pop_back();
  if (this->_direction == 'l')
    {
      s->setX((sList.front()->getX())-20);
      s->setY(sList.front()->getY());
      sList.push_front(s);
    }
  else if (this->_direction == 'r')
    {
      s->setX((sList.front()->getX())+20);
      s->setY(sList.front()->getY());
      sList.push_front(s);
    }
  else if (this->_direction == 'u')
    {
      s->setX(sList.front()->getX());
      s->setY((sList.front()->getY())-20);
      sList.push_front(s);
    }
  else if (this->_direction == 'd')
    {
      s->setX(sList.front()->getX());
      s->setY((sList.front()->getY())+20);
      sList.push_front(s);
    }
  move((sList.front()->getY())/20, (sList.front()->getX())/20);
  addch(this->_partchar);
  refresh();
}

void	Display::Play(std::list<ISnake *> &sList, std::list<IFood *> &fList)
{
  this->movesnake(sList, fList);
}

Display::~Display()
{
  curs_set(1);
  nodelay(stdscr, false);
  getch();
  endwin();
}

extern "C"
{
  Display		*make_display()
  {
    return new	Display();
  }
}
