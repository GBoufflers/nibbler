#ifndef		__SOUND_HH__
#define		__SOUND_HH__

#include	<iostream>
#include	<SFML/Audio.hpp>

class		MSound
{
private:
  sf::Music		_music;
public:
  MSound();
  ~MSound();
  void			InitSound(std::string);
};

#endif
