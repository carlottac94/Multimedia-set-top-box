#include <list>
#include <memory>
#include <iostream>
#include <sstream>
#include "groupe.h"
#include "multimedia.h"


using namespace std;

Groupe::Groupe(string _groupname) : list<shared_ptr<Multimedia>>()
{
    groupname=_groupname;
}

string Groupe::getGroupName() const{
    return groupname;
}

/**
 * @brief Groupe::PrintAttributes: ceci c'est un example de gestion uniforme des objets
 * qui héritent de la même super-classe. Grâce au polymorphisme (et au fait que printOnBuffer
 * a étée declarée une méthode virtuelle), toujours la correcte implémentation de la méthode
 * sera appelée.
 * @param strm
 */
void Groupe::PrintAttributes(ostream& strm) const{
    strm << "Group " << groupname << ":" << endl;
    //for (list<Multimedia*>::const_iterator it = this->begin(); it != this->end(); ++it) {
    for (list<shared_ptr<Multimedia>>::const_iterator it = this->begin(); it != this->end(); ++it) {
        (*it)->printOnBuffer(strm);
    }
}
/*void Groupe::deleteList(){
    for (list<Multimedia*>::const_iterator it = this->begin(); it != this->end(); ++it) {
        delete (*it);
    }
}*/


