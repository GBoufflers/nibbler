#ifndef			__STRATEGIE_HH__
#define			__STRATEGIE_HH__

#include		"IStrategie.hh"

namespace		Strategie
{
  class			Easy : public IStrategie
  {
  private:
    IStrategieType	_type;
    int			_speed;
    int			_nbFood;
  public:
    virtual IStrategieType		getType() const;
    virtual int		getSpeed() const;
    virtual void	setSpeed(int speed);
    Easy();
    virtual ~Easy();
  };

  class			Medium : public IStrategie
  {
  private:
    IStrategieType	_type;
    int			_speed;
    int			_nbFood;
  public:
    virtual IStrategieType		getType() const;
    virtual int		getSpeed() const;
    virtual void	setSpeed(int speed);
    Medium();
    virtual ~Medium();
  };

  class			Hard : public IStrategie
  {
  private:
    IStrategieType	_type;
    int			_speed;
    int			_nbFood;
  public:
    virtual IStrategieType		getType() const;
    virtual int		getSpeed() const;
    virtual void	setSpeed(int speed);
    Hard();
    virtual ~Hard();
  };
}

#endif
