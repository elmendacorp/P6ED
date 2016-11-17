//
// Created by Fran on 25/10/2016.
//

#include "Gitcode.h"
#include <fstream>
#include <iostream>




Commit Gitcode::getCommit(std::string &commi) {
    std::list<Commit>::iterator ite = commits.begin();
    while (ite != commits.end()) {
        Commit tm = *ite;
        if (tm.getCodigo() == commi) {
            return *ite;
        }
        ++ite;

    }

}

vector<Commit*> Gitcode::getCommitFechas(const Fecha &inicio, const Fecha &fin) {
    vector<Commit*> tempo;
    std::list<Commit>::iterator ite = commits.begin();
    while (ite != commits.end()) {
        if (ite->getMarcaDeTiempo() < fin && ite->getMarcaDeTiempo() > inicio) {
            tempo.push_back(&*ite);
        }
        ++ite;
    }

    return tempo;
}

/*vector<Commit*> Gitcode::getCommitFichero(std::string fichero) {
    vector<Commit*> temporal;
    std::list<Commit>::iterator tempo = commits.begin();
    while (tempo != commits.end()) {
        Fichero *t = ;
        if (t->getTamaBytes() != 0) {
            temporal.push_back(&*tempo);
        }
        ++tempo;
    }

    return temporal;
}*/

Gitcode::Gitcode(const std::string &fich, const std::string &commi) {
    std::string lineaActual;
    try {
        std::ifstream inputStream;
        inputStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        inputStream.open(fich);

        inputStream >> lineaActual;

        while (!inputStream.eof()) {
            Fichero *f;
            std::getline(inputStream >> ws, lineaActual);

            auto pos = lineaActual.find(';');
            auto ruta = lineaActual.substr(0, pos);
            auto tama = lineaActual.substr(pos + 1, ruta.length() - 1);

            pos = ruta.find_last_of('/');
            auto ubicacion = ruta.substr(0, pos + 1);
            auto nombre = ruta.substr(pos + 1, ruta.length());
            auto tamaBytes = std::stoi(tama);
            f =new Fichero(nombre, ubicacion, tamaBytes);
            ficheros.push_back(f);



        }
        inputStream.close();
    } catch (exception &e) {
        std::cerr << "Excepcion leyendo el fichero: " << e.what() << std::endl;
    }

    int ref;
    try {
        std::ifstream inputStream;

        inputStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        inputStream.open(commi);
        Commit *MiCommit;
        inputStream >> lineaActual;

        while (!inputStream.eof()) {
            std::getline(inputStream >> ws, lineaActual);

            auto pos = lineaActual.find_last_of(';');
            auto indice = lineaActual.substr(pos + 1, lineaActual.size()-2);
            auto substr1 = lineaActual.substr(0, pos);
            pos = substr1.find_last_of(';');
            auto mensaje = substr1.substr(pos + 1, substr1.size());
            substr1 = substr1.substr(0, pos);
            pos = substr1.find_last_of(';');
            auto marcaTiempo = substr1.substr(pos + 1, substr1.size());
            Fecha fch= Fecha(1,1,1,1,1);
            fch.anadirAnios(std::stoi(marcaTiempo.substr(0, 4))-1);
            fch.anadirMeses(std::stoi(marcaTiempo.substr(4, 6))-1);
            fch.anadirDias(std::stoi(marcaTiempo.substr(6, 8))-1);
            fch.anadirHoras(std::stoi(marcaTiempo.substr(8, 10))-1);
            fch.anadirMin(std::stoi(marcaTiempo.substr(10, 12))-1);

            auto codigo = substr1.substr(0, pos);
            Commit inserta = Commit(codigo, fch, mensaje);

            pos = 0;
            indice = indice.substr(0, (indice.size() - 1));
            while (pos != indice.find_first_of(',')) {
                pos = indice.find_last_of(',');
                ref = std::stoi(indice.substr(pos + 1, substr1.size()));
                inserta.anadeFichero(ficheros[ref]);
                indice = indice.substr(0, pos);
            }

            commits.push_back(inserta);
            std::list<Commit>::iterator it=commits.end();
            --it;
            std::pair<std::string,std::list<Commit>::iterator> ins;
            ins.first=inserta.getCodigo();
            ins.second=it;
            ABBbuscar.emplace(ins);




        }
        inputStream.close();
    } catch (exception &e) {
        std::cerr << "Excepcion leyendo el fichero: " << e.what() << std::endl;
    }
}

void Gitcode::eliminaFichero(std::string &fichero) {
    std::list<Commit>::iterator miIt = commits.begin();
    while (miIt != commits.end()) {
        miIt->borraFichero(fichero);
        ++miIt;
    }
}


/*void Gitcode::nuevoCommit(Commit &orig) {

    if(!ABBbuscar.buscar(b)){
        commits.insertar(b.itc,orig);
        ABBbuscar.insertar(b);
    }

}*/

/*bool Gitcode::borraCommit(const std::string &codigo) {
    refCommit b=refCommit(codigo,commits.iteradorInicio());
    if(ABBbuscar.buscar(b)){
    }

}*/

/*std::string Gitcode::getStatus() {
    std::string mistr;
    mistr+= (char)ABBbuscar.;
    mistr+= (char)ABBbuscar.size();
    mistr+= (char)ABBbuscar.;
    return mistr;
}*/

