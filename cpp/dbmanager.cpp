#include <map>
#include <iostream>
#include <list>
#include "dbmanager.h"

using namespace std;

Dbmanager::Dbmanager(){}

shared_ptr<Photo> Dbmanager::newPhoto(string _name, string _pathname, float lat, float longt){
    shared_ptr<Photo> p(new Photo(_name, _pathname, lat, longt));
    multimediaObjs[_name]=p;
    return p;
}

shared_ptr<Video> Dbmanager::newVideo(string _name, string _pathname, unsigned int duration){
    shared_ptr<Video> v(new Video(_name, _pathname, duration));
    multimediaObjs[_name]=v;
    return v;
}

shared_ptr<Film> Dbmanager::newFilm(string _name, string _pathname, int* _chapitres, int _n){
    shared_ptr<Film> f(new Film(_name, _pathname, _chapitres,_n));
    multimediaObjs[_name]=f;
    return f;
}

shared_ptr<Groupe> Dbmanager::newGroupe(string _groupname){
    shared_ptr<Groupe> g(new Groupe(_groupname));
    groups[_groupname]=g;
    return g;
}

void Dbmanager::printObjetMult(string _name,ostream& strm){
    auto it=multimediaObjs.find(_name);
    if(it==multimediaObjs.end()){
        cout<<"Alert: no multimedia object found with this name"<<endl;
    }
    else (it->second)->printOnBuffer(strm);

}

void Dbmanager::printGroup(string _groupname,ostream& strm){
    auto it=groups.find(_groupname);
    if(it==groups.end()){
        cout<<"Alert: no group found with this name"<<endl;
    }
    else (it->second)->PrintAttributes(strm);
}

void Dbmanager::playObj(string _name){

    auto it=multimediaObjs.find(_name);
    if(it==multimediaObjs.end()){
        cout<<"Alert: no multimedia object found with this name"<<endl;
    }
    else (it->second)->play();
}

