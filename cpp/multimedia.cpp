#include "multimedia.h"

using namespace std;

Multimedia::Multimedia(string _name, string _pathname){name=_name; pathname=_pathname;}

string Multimedia::getName() const{
    return name;
}

string Multimedia::getPathname() const{
    return pathname;
}

void Multimedia::setName(string _name){
    name=_name;
}

void Multimedia::setPathname(string _pathname){
    pathname=_pathname;
}

void Multimedia::printOnBuffer(ostream& stream) const{
    stream << "object:" << name <<", path of the file:" << pathname << std::endl;
}



