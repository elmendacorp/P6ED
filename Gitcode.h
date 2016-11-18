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
private:
    std::map<std::string,std::list<Commit *>::iterator> ABBbuscar;
    std::list<Commit *> commits;
    std::vector<Fichero *> ficheros;
    std::map<std::string, Fichero *> ficherosActivos;
public:
    /**
     * Busca un commit por su  V1
     * @param commi
     * @return
     */
    Commit *getCommit(const std::string &commi);

    Gitcode(const std::string &fich, const std::string &commi);

    std::vector<Commit *> getCommitFechas(const Fecha &f1,const Fecha &f2);

};


#endif //CPPAPPLICATION_2_GITCODE_H
