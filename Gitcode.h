//
// Created by Fran on 25/10/2016.
//

#ifndef CPPAPPLICATION_2_GITCODE_H
#define CPPAPPLICATION_2_GITCODE_H

#include "Fichero.h"
#include "Commit.h"
#include "fecha.h"
#include <vector>
#include <map>
#include <list>
#include <set>

class Gitcode {
public:
class refCommit{
public:
    std::pair<std::string,std::list<Commit>::iterator> nodo;
    refCommit();
};
private:
    map<std::pair<std::string,std::list<Commit>::iterator>,less<ref>> ABBbuscar;
    std::list<Commit> commits;
    vector<Fichero *> ficheros;
    std::map<Fichero *,std::less<Fichero>> ficherosActivos;
public:
    /**
     * Busca un commit por su  V1
     * @param commi
     * @return
     */
    Commit getCommit(std::string &commi);


    vector<Commit*> getCommitFechas(const Fecha &inicio, const Fecha &fin);

    vector<Commit*> getCommitFichero(std::string fichero);

    Gitcode(const std::string &fich, const std::string &commi);

    void eliminaFichero(std::string &fichero);

    //void nuevoCommit(Commit &orig);

    bool borraCommit(const std::string &codigo);

    std::string getStatus();

};


#endif //CPPAPPLICATION_2_GITCODE_H
