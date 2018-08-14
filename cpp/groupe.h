#ifndef GROUPE_H
#define GROUPE_H
#include <list>
#include <memory>
#include <iostream>
#include "multimedia.h"

using namespace std;

//class Groupe : public list<Multimedia*>
/**
 * @brief The Groupe class: cette classe hérite d'une liste
 */
class Groupe : public list<shared_ptr<Multimedia>>
{friend class Dbmanager;
    string groupname;

    /**
     * @brief Groupe: le constructeur de cette classe peut  être appelé seulement par la classe
     * friend DBmanager, aufin que seulement cette classe puisse contrôler les instantiations
     * des autres objets.
     * @param _groupname
     */
    Groupe(string _groupname);

public:
    string getGroupName() const;
    void PrintAttributes(ostream &strm) const;
    //void deleteList();
};

#endif // GROUPE_H
