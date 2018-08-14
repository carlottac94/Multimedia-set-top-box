//
//  main.cpp
//

#ifdef VERSIONMAIN
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <vector>
#include "dbmanager.h"
#include "photo.h"
#include "video.h"
#include "multimedia.h"
#include "film.h"
#include "groupe.h"
#include "tcpserver.h"

using namespace std;
using namespace cppu;
const int PORT = 3331;

/** la 'version_one' du main c'est la version utilisée pour vérifier le correct fonctionnement
 * des étapes 1-9.
 * la 'version_two' c'est la version utilisée pour vérifier le correct fonctionnement
 * de l' étape 10.
 * */

#define VERSION_TWO


        int main(int argc, char* argv[]) {
#ifdef VERSION_ONE
            Photo* p=new Photo("photo1", "./photo1.jpg");
            Video* v=new Video("video1", "./inf224");
            Multimedia** files= new Multimedia* [3];

            unsigned int i=0;

            p->play();

            files[i++]=p;
            files[i++]=v;
            files[i++]=new Photo("photo2", "./photo2.jpg");

            for(i=0;i<3;i++){
                files[i]->printOnBuffer(cout);
            }

            //testing point 6
            int chaps[]= {1200,1300};

            Film *f1= new Film("film1","./inf224",chaps,2);
            f1->printDurees();

            chaps[0]=230;
            f1->printDurees();
            Film *f2= new Film(*f1);
            f2->printDurees();

            //testing point 8-9
            Groupe* g=new Groupe("group1");
            Groupe* g2=new Groupe("group2");
            shared_ptr<Photo> p1(new Photo("photoShared", "./photo1.jpg"));
            shared_ptr <Video> v1(new Video("videoShared", "./inf224"));
            shared_ptr <Video> v2(new Video("video2", "./inf224"));
            shared_ptr<Photo> p2(new Photo("photo2", "./photo2.jpg"));

            cout << "Name of the group: " << g->getGroupName() << endl;
            g->push_back(p1);
            g->push_back(v1);
            g->push_back(p2);
            g->PrintAttributes(cout);



            g2->push_back(v1);
            g2->push_back(v2);

            v1.reset();
            g->erase(g->begin());
            g->erase(g->begin());
            g->PrintAttributes(cout);
            g2->PrintAttributes(cout);

            g2->erase(g2->begin());

            delete p;
            p=nullptr;
            delete v;
            v=nullptr;

            delete f1;
            f1=nullptr;
            delete [] files;
#endif

#ifdef VERSION_TWO
            //tester point 10
            Dbmanager* dbm=new Dbmanager();
            shared_ptr<Photo> p=dbm->newPhoto("photo1", "./photo1.jpg",0,0);
            shared_ptr<Video> v=dbm->newVideo("video1", "./inf224",120);

            p->printOnBuffer(cout);
            v->printOnBuffer(cout);

            int chaps[]= {1200,1300};

            shared_ptr<Film> f1= dbm->newFilm("film1","./inf224",chaps,2);
            f1->printDurees();

            shared_ptr<Groupe> g=dbm->newGroupe("group1");
            g->push_back(p);
            g->push_back(v);
            g->push_back(f1);

            g->PrintAttributes(cout);
            dbm->printGroup("groupn");
            dbm->printGroup("group1");
            dbm->printObjetMult("photo1");
            dbm->printObjetMult("video1");
            dbm->printObjetMult("film1");
            dbm->playObj("photo1");
#endif

            exit(0);
        }
#endif
