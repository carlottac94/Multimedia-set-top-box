//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "tcpserver.h"
#include "dbmanager.h"
#include "cppsocket.h"
using namespace std;
using namespace cppu;

const int PORT = 3331;

class MyBase {
    /**
     * @brief dbm: j'ai besoins d'un pointeur à un objet Dbmanager, pour appeler
     * toutes les méthodes nécessaires pour créer, afficher et jouer les objets et les groupes.
     */
    Dbmanager* dbm=nullptr;

public:

    MyBase(Dbmanager &_dbm){
        if(dbm==nullptr)
            dbm=new Dbmanager(_dbm);

        else
            delete dbm;
        dbm=nullptr;

        dbm=new Dbmanager(_dbm);
    }

    /**
     * @brief processRequest: Cette méthode est appelée chaque fois qu'il y a une requête à traiter.
   *
   * Arguments:
   * - 'request' contient la requête
   * - 'response' sert à indiquer la réponse qui sera renvoyée au client
   * - si la fonction renvoie false la connexion est close.

     */

    /**
    protocol:
    the client can send 3 types of requests:
    1-"print multimedia name" => to search an objet name and print its attributes
    2-"print group groupname" => to search a group groupname and print its attributes
    3-"play name" => to play a multimedia object
    */

    bool processRequest(TCPConnection& cnx, const string& request, string& response)
    {
        cerr << "\nRequest: '" << request << "'" << endl;
        stringstream strm;
        char split_char = ' ';
        istringstream split(request);
        vector<string> tokens;
        for (string each; getline(split, each, split_char); tokens.push_back(each));
        strm.str(std::string());

        if(tokens[0]=="print"){
            if(tokens[1]=="multimedia")
                dbm->printObjetMult(tokens[2],strm);

            else{
                if(tokens[1]=="group")
                    dbm->printGroup(tokens[2],strm);
                else{
                    strm<<"The request is not in the correct format"<<endl;

                }
            }
        }

        else{
            if(tokens[0]=="play"){
                dbm->printObjetMult(tokens[1],strm);
                if (strm.rdbuf()->in_avail() == 0)
                    strm<<"The file is not found"<<endl;
                else
                    dbm->playObj(tokens[1]);
            }
            else{
                strm<<"The request is not in the correct format"<<endl;

            }

        }
        if (strm.rdbuf()->in_avail() == 0)
            strm<<"The file is not found"<<endl;

        response=strm.str();
        response = response.substr(0, response.size()-1);
        replace(response.begin(), response.end(), '\n', ';');
        cerr << "response: " << response << endl;
        // renvoyer false si on veut clore la connexion avec le client
        return true;

    }
};





int main(int argc, char* argv[])
{
    // cree le TCPServer
    shared_ptr<TCPServer> server(new TCPServer());
    Dbmanager* d=new Dbmanager();

    shared_ptr<Photo> p=d->newPhoto("photo1", "./photo1.jpg",0,0);
    shared_ptr<Video> v=d->newVideo("video1", "./video1.mp4",120);

    // cree l'objet qui gère les données

    int chaps[]= {1200,1300};

    shared_ptr<Film> f1= d->newFilm("film1","./film1.mp4",chaps,2);

    shared_ptr<Groupe> g=d->newGroupe("group1");
    g->push_back(p);
    g->push_back(v);
    g->push_back(f1);
    shared_ptr<MyBase> base(new MyBase(*d));

    // le serveur appelera cette méthode chaque fois qu'il y a une requête
    server->setCallback(*base, &MyBase::processRequest);

    // lance la boucle infinie du serveur
    cout << "Starting Server on port " << PORT << endl;
    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        cerr << "Could not start Server on port " << PORT << endl;
        return 1;
    }

    return 0;
}
