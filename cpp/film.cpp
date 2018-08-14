#include "film.h"

Film::Film(string _name, string _pathname, int* _chapitres, int _n) : Video(_name, _pathname){
    n=_n;
    chapitres=new unsigned int[n];
    for(int i=0;i<n;i++)
        chapitres[i]=_chapitres[i];

}

void Film::setChapitres(int* _chapitres, int _n){
    if(chapitres!=nullptr){
        delete [] chapitres;
        chapitres=nullptr;
    }
    n=_n;
    chapitres=new unsigned int[n];
    for(int i=0;i<n;i++)
        chapitres[i]=_chapitres[i];
}

/**
 * @brief Film::getChapitres
 * @param _n
 * @return une copie du tableau des durées du film, pas l'adresse du tableau, pour garantir
 * l'encapsulation de l'objet.
 */
unsigned int* Film::getChapitres(int* _n){
    *_n=n;
    unsigned int* newchapitres=new unsigned int[n];
    for(int i=0;i<n;i++)
        newchapitres[i]=chapitres[i];
    return newchapitres;}

int Film::getNChapitres(){return n;}

void Film::printDurees(){

    for(int i=0; i< n;i++)
        std::cout << "chap" << i << " " << chapitres[i]<< std::endl;
}

Film::Film(const Film& f) : Video(f.getName(),f.getPathname()){
    this->chapitres = f.chapitres;
    this->chapitres = new unsigned int[n];

    for(int i = 0; i<n; ++i )
        this->chapitres[i] = f.chapitres[i];
}

Film& Film::operator=(const Film& f)
{
    this->name = f.name;
    this->pathname = f.pathname;

    delete [] chapitres;

    this->chapitres = f.chapitres;
    this->chapitres = new unsigned int[n];

    for(int i = 0; i<n; ++i )
        this->chapitres[i] = f.chapitres[i];

    return *this;
}

/**
 * @brief Film::~Film: dans cette classe le déstructeur doit gérer la destruction du tableau
 * chapitres, afin qu'il n'y ait pas de fuite mémoire .
 */
Film::~Film(){
    delete [] chapitres;
    chapitres= nullptr;
}
