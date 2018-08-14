#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <string>
#include <iostream>

using namespace std;

/**
 * @brief The Multimedia class : classe de base,racine de la hiérarchie, sur la quelle
 * sont construites toutes les spécifications de l'objet multimedia. C'est une classe abstraite
 * parce qu' elle a la méthode abstraite play, donc elle n'est peut pas être instanciée
 * à l'extérieur.
 */
class Multimedia
{friend class Dbmanager;
protected:
    string name, pathname;
    Multimedia(){}
    Multimedia(string _name,string _pathname);


public:
    string getName() const;
    string getPathname() const;
    void setName(string _name);
    void setPathname(string _pathname);
    /**
     * @brief printOnBuffer: ce méthode doit être redéfini par les sous-classes, parce que
     * chaque typologie d'objet multimedia a différentes characteristiques à afficher.
     * @param stream
     */
    virtual void printOnBuffer(ostream& stream) const;
    /**
     * @brief play: ce méthode doit être implementée par les sous-classes, parce que
     * chaque typologie d'objet multimedia a besoins d'un programme linux différent pour
     * être joué. Méthode abstraite: pas d'implementation dans la classe de base.
     */
    virtual void play()const=0;
    virtual ~Multimedia(){}
};

#endif // MULTIMEDIA_H
