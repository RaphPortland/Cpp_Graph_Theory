//
//  Arete.cpp
//  tp3
//
//  Created by Partouche on 29/03/2018.
//  Copyright © 2018 Partouche. All rights reserved.
//

#include "Arete.hpp"

Arete::Arete(Sommet s1, Sommet s2, int poids) : m_s1(s1), m_s2(s2), m_poids(poids)
{
    
}

Arete::Arete() : m_s1(), m_s2(), m_poids(0)
{
    
}

void Arete::affichageattributarete()
{
    std::cout << "Sommet_depart : " << m_s1.get_numero_de_sommet() << " Sommet_arriver : " << m_s2.get_numero_de_sommet() << " Poid de l'arete : " << m_poids << std::endl;
}
