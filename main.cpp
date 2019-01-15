//
//  main.cpp
//  tp3
//
//  Created by Partouche on 29/03/2018.
//  Copyright © 2018 Partouche. All rights reserved.
//

#include <iostream>
#include "Graphe.hpp"
#include "Sommet.hpp"

int main(int argc, const char * argv[]) {
    
    Graphe a;
    a.display_matricedadjacence();
    a.display_VecArete();
    
    a.Dijkstra();
    a.prim();
    return 0;
}
