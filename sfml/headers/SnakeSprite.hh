#ifndef		__SNAKESPRITE_HH__
#define		__SNAKESPRITE_HH__

#include	

class			SnakeSprite
{
private:
  sf::Image             _image;
  sf::Sprite            _sprite;
  int			_x;
  int			_y;
public:
  Snake();
  virtual ~Snake();
  virtual void		setImage(sf::Image image);
  virtual void		setSprite(sf::Sprite sprite);
  virtual void		setY(int y);
  virtual void		setX(int x);
  /************/
  virtual int		getY() const;
  virtual int		getX() const;
#endif
