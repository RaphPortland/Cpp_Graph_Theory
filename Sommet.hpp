//
//  Sommet.hpp
//  tp3
//
//  Created by Partouche on 29/03/2018.
//  Copyright © 2018 Partouche. All rights reserved.
//

#ifndef Sommet_hpp
#define Sommet_hpp

#include <stdio.h>

class Sommet {
    
    private :
    
    int numero_de_sommet;
    bool m_marque;
    
    public :
    
    int pred;
    Sommet();
    Sommet(int num);
    void set_marquage(bool marquage);
    bool get_marquage();
    int getnumerodesommet()
    {
        return numero_de_sommet;
    };
    
    void set_numero_de_sommet(int num);
    int get_numero_de_sommet();
};


#endif /* Sommet_hpp */
