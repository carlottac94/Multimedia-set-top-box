#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <map>
#include <memory>
#include <list>
#include <iostream>
#include "multimedia.h"
#include "groupe.h"
#include "photo.h"
#include "video.h"
#include "film.h"


using namespace std;
/**
 * @brief The Dbmanager class: c'est la classe qui sert à fabriquer et manipuler tous les
 * objets de manière cohérente.
 */

class Dbmanager
{map<string,shared_ptr<Multimedia>> multimediaObjs;
 map<string,shared_ptr<Groupe>> groups;
public:
    Dbmanager();
    /**
     * newPhoto, newVideo, newFilm et newGroupe permettent de créér des instantiations
     * des objets photo, video, film et groupe et de les ajouter dans le conteneur approprié,
     * en assurant une gestion cohérente des données.
     */
    shared_ptr<Photo> newPhoto(string _name, string _pathname, float lat, float longt);
    shared_ptr<Video> newVideo(string _name, string _pathname, unsigned int duration);
    shared_ptr<Film> newFilm(string _name, string _pathname, int* _chapitres, int _n);
    shared_ptr<Groupe> newGroupe(string _groupname);
    /**
     * @brief printObjetMult: cette méthode trouve l'objet souhaité à partir du nom dans
     * la table associative des objets multimedia et appelle la méthode d'affichage printOnBuffer (qui a été
     * redéfinie pour chaque sous-classe).
     * @param _name
     * @param strm
     */
    void printObjetMult(string _name, ostream& strm);

    /**
     * @brief printGroup: cette méthode trouve le groupe souhaité à partir du nom dans
     * la table associative des groupes et appelle la méthode d'affichage pour les groupes
     * printAttributes.
     * @param _groupname
     * @param strm
     */
    void printGroup(string _groupname, ostream& strm);
    /**
     * @brief playObj: permet de jouer l'objet multimedia. Grâce au polymorphisme (et au fait que play
     * a étée declarée une méthode abstraite), toujours la correcte implémentation de la méthode
     * sera appelée.
     * @param _name
     */
    void playObj(string _name);

};

#endif // DBMANAGER_H
