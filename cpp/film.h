#ifndef FILM_H
#define FILM_H
#include "video.h"

class Film : public Video
{   friend class Dbmanager;
    unsigned int* chapitres;
    int n=0;

    /**
     * @brief Film: le constructeur de cette classe peut  être appelé seulement par la classe
     * friend DBmanager, aufin que seulement cette classe puisse contrôler les instantiations
     * des autres objets.
     */
    Film();
    Film(string _name, string _pathname, int* _chapitres, int _n);
    /**
     * @brief Film: Copy constructor, cela permet de gérer correctement la copie de l'objet
     * film (et en particulier du tableau des chapitres), en définissant une copie profonde.
     * Cette méthode est utilisée pour initialiser un nuoveau objet avec un objet déjà existant.
     * @param f
     */
    Film(const Film &f);
    /**
     * @brief operator =: cela permet de gérer correctement la copie de l'objet
     * film (et en particulier du tableau des chapitres), en définissant une copie profonde.
     * Cette méthode est utilisée pour affecter un objet film déjà existant avec un autre.
     * @param f
     * @return
     */
    Film& operator=(const Film& f);


public:
    void setChapitres(int* _chapitres, int _n);
    unsigned int* getChapitres(int* _n);
    int getNChapitres();
    void printDurees();
     ~Film();

};

#endif // FILM_H
