//
//  Sommet.cpp
//  tp3
//
//  Created by Partouche on 29/03/2018.
//  Copyright © 2018 Partouche. All rights reserved.
//

#include "Sommet.hpp"


Sommet::Sommet() : numero_de_sommet(0), m_marque(false), pred(-1)
{
    
}

Sommet::Sommet(int num) : numero_de_sommet(num), m_marque(false), pred(-1)
{

}

void Sommet::set_marquage(bool marquage)
{
    m_marque=marquage;
}
bool Sommet::get_marquage(){
    return m_marque;
}


int Sommet::get_numero_de_sommet()
{
    return numero_de_sommet;
}
void Sommet::set_numero_de_sommet(int num)
{
    numero_de_sommet=num;
}
