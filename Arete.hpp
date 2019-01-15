//
//  Arete.hpp
//  tp3
//
//  Created by Partouche on 29/03/2018.
//  Copyright © 2018 Partouche. All rights reserved.
//

#ifndef Arete_hpp
#define Arete_hpp

#include <stdio.h>
#include <iostream>
#include "Sommet.hpp"


class Arete
{
    public :

    
    Sommet m_s1;
    Sommet m_s2;
    int m_poids;
    
    
    Arete();
    Arete(Sommet s1, Sommet s2, int poids);
    void affichageattributarete();
//~Arete();
};


#endif /* Arete_hpp */
