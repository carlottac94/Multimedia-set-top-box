#ifndef PHOTO_H
#define PHOTO_H
#include "multimedia.h"

using namespace std;

class Photo : public Multimedia
{friend class Dbmanager;
private:
    float lat, longt;
    /**
     * @brief Photo: le constructeur de cette classe peut être appelé seulement par la classe
     * friend DBmanager, aufin que seulement cette classe puisse contrôler les instantiations
     * des autres objets.
     * @param _name
     * @param _pathname
     * @param lat
     * @param longt
     */
    Photo(string _name, string _pathname, float lat=0, float longt=0) : Multimedia(_name, _pathname){}


public:

    float getLatitude()const{return lat;}
    void setLatitude(float _lat){lat=_lat;}
    float getLongitude()const{return longt;}
    void setLongitude(float _longt){longt=_longt;}
    /**
     * @brief printOnBuffer: cette méthode héritée par la classe de base est redéfini
     * pour afficher aussi la latitude et la longitude de la photo.
     * @param stream
     */
    void printOnBuffer(ostream& stream) const override{stream << "object:" << name <<", path of the file:" << pathname << "latitude:" << lat << ", longitude:" << longt << std::endl;}
    /**
     * @brief play: spécification de la méthode abstraite play qui appelle le programme linux imagej
     * pour jouer la photo.
     */
    virtual void play()const {string command= "imagej "+pathname+" &"; system(command.c_str());}
    /**
      *dans le destructeur j'ai ajoutée un affichage pour vérifier (dans l'étape 9) que la
      * photo soit détruite seulement quand elle n'appartient plus à aucun groupe.
      */
    ~Photo(){cout << "la photo " << this->getName() << " va être detruite"<< endl;}

};

#endif // PHOTO_H
