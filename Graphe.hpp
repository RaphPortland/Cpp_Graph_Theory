//
//  Graphe.hpp
//  tp3
//
//  Created by Partouche on 29/03/2018.
//  Copyright © 2018 Partouche. All rights reserved.
//

#ifndef Graphe_hpp
#define Graphe_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include "Sommet.hpp"
#include "Arete.hpp"
#include <map>

class Graphe
{
    public :
    
    std::vector <std::vector<int>> matrice_d_adjacence;
    std::vector<Sommet> Vector_sommet;
    std::vector<Arete> m_vecArete;
    
    int ordre;
    int m_nbAretes;
    int depart;
    
    Graphe();
    void recup_fichier(std::string nom_du_fichier);
    void display_matricedadjacence();
    void set_marquage_vector(bool trueorfalse);
    
    void remplirVecArete(std::string fichier);
    void display_VecArete();
    
    void Dijkstra();
    void printSolution(std::vector<int> dist);
    int minDistance(std::vector<int> dist);
    
    
    void prim();
    int trouverlepoidmin(std::map <int, int> vector_de_poid);
    
};



#endif /* Graphe_hpp */
