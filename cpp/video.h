#ifndef VIDEO_H
#define VIDEO_H
#include "multimedia.h"

using namespace std;

class Video : public Multimedia
{friend class Dbmanager;
private:
    unsigned int duration;
protected:
    /**
     * @brief Video: le constructeur de cette classe peut  être appelé seulement par la classe
     * friend DBmanager, aufin que seulement cette classe puisse contrôler les instantiations
     * des autres objets, et par la sous-classe film.
     * @param _name
     * @param _pathname
     * @param duration
     */
    Video(string _name, string _pathname, unsigned int duration = 0) : Multimedia(_name,_pathname){}


    public:
    unsigned int getDuration()const{return duration;}
    void setDuration(unsigned int _duration){duration=_duration;}
    /**
     * @brief printOnBuffer: cette méthode héritée par la classe de base est redéfini
     * pour afficher aussi la durée du video.
     * @param stream
     */
    virtual void printOnBuffer(ostream& stream) const override{stream << "object:" << name <<", path of the file:" << pathname << "duration of the video:" << duration << std::endl;}

    /**
     * @brief play: spécification de la méthode abstraite play qui appelle le programme linux mpv
     * pour jouer la photo.
     */
    virtual void play()const{string command= "mpv "+pathname+" &"; system(command.c_str());}

    /**
      *dans le destructeur j'ai ajoutée un affichage pour vérifier (dans l'étape 9) que le
      * vidéo soit détruit seulement quand il n'appartient plus à aucun groupe.
      */
    ~Video(){cout << "le video " << this->getName() << " va être detruit"<< endl;}
};

#endif // VIDEO_H
