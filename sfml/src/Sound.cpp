#include	"../headers/Sound.hh"

MSound::MSound()
{

}

MSound::~MSound()
{

}

void		MSound::InitSound(std::string nameOfTrack)
{
  std::string	final;

  std::cout << "bonjoour" << std::endl;
  final = "/home/guillaume/Git/nibbler/sounds/" + nameOfTrack;
  if (!this->_music.OpenFromFile(final))
    std::cout << "Impossible de loader le fichier" << std::endl;
  else
    {
      this->_music.SetLoop(true);
      this->_music.Play();
    }
}
