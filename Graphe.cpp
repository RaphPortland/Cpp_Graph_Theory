//
//  Graphe.cpp
//  tp3
//
//  Created by Partouche on 29/03/2018.
//  Copyright © 2018 Partouche. All rights reserved.
//

#include "Graphe.hpp"


Graphe::Graphe()
{
    std::string fic_name = "/Users/partoucheraph/Documents/Inge2/Info/Theorie des graphes/TP3/tp3/tp3/matrice_adjacence.txt";
    std::string nomFichier_vecteurdarrete = "/Users/partoucheraph/Documents/Inge2/Info/Theorie des graphes/TP3/tp3/tp3/tableaudarrete.txt";
    
    recup_fichier(fic_name);
    remplirVecArete(nomFichier_vecteurdarrete);
    
    for(int i =0; i<ordre;i++)
    {
        Sommet s(i);
        Vector_sommet.push_back(s);
    }
    
}

void Graphe::display_matricedadjacence()
{
    for (int i=0;i<ordre;i++) // Affichage de la matrice d'adjacence
    {
        for (int j=0;j<ordre;j++)
        {
            std::cout << matrice_d_adjacence[i][j]<< " ";
        }
        std::cout << " " << std::endl;
    }
}


void Graphe::recup_fichier(std::string nom_du_fichier)
{
    
    std::ifstream fichier(nom_du_fichier, std::ios::in);
    
    if(fichier)  // si l'ouverture a fonctionné
    {
        int ordre_fic=0;
        fichier >> ordre_fic;
        ordre=ordre_fic;
        
        matrice_d_adjacence.resize(ordre);
        for (int i=0 ; i < ordre ; i++)
        {
            matrice_d_adjacence[i].resize(ordre);
        }
        
        // On initialise toute les valeurs de la matrice a zero
        for (int i=0 ; i < ordre ; i++)
        {
            for (int j=0 ; j < ordre ; j++)
            {
                matrice_d_adjacence[i][j]= 0;
            }
        }
        
        int valeur=0;
        for (int i=0;i<ordre;i++)
        {
            for (int j=0;j<ordre;j++)
            {
                fichier >> valeur;
                matrice_d_adjacence[i][j]= valeur;
            }
        }
        
        fichier.close();
    }
    else
    {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    }
    
}

void Graphe::set_marquage_vector(bool trueorfalse)
{
    for(int i =0; i<ordre; i++)
    {
        Vector_sommet[i].set_marquage(trueorfalse);
    }
}

int Graphe::minDistance(std::vector<int> dist)
{
   // Initialisation valeur min
    int min_index = 0;
    int min=10000;
  
    for (int v = 0; v < ordre; v++)
    {
      if (Vector_sommet[v].get_marquage() == false && dist[v] <= min)
      {
         min = dist[v];
         min_index = v;
      }
    }
  
    return min_index;
}

void Graphe::printSolution(std::vector<int> dist)
{
   printf("Sommet   Distance de la Source\n");
   for (int i = 0; i < ordre; i++)
   {
      std::cout << i << " " << dist[i] << std::endl;

   }
}

void Graphe::Dijkstra()
{
    int max_value=10000;

    std::vector <int> dist;
    
    for (int i=0; i<ordre;i++)
    {
        dist.push_back(max_value); // On met des nombres tres tres grand dans tout le tableau de distance (Infini)
    }
    set_marquage_vector(false); // On set tous les sommets du graphe comme non marqué
    dist[depart]=0; // Le sommet de depart est a une distance 0 de lui meme

     for (int i = 0; i < ordre-1; i++)
     {
        // On prend la plus petite valeur du tableau de distance
        // u toujours egal au sommet de depart a la premiere iteration
        int u = minDistance(dist);
        
       // Marqué le sommet ayant la plus petite distance choisi
        Vector_sommet[u].set_marquage(true);
         
       // On met a jour les distances en fonction du sommet ayant la plus courte distance choisi (u)
       for (int v = 0; v < ordre; v++)
       {
         // Mise a jour de dist[v] seulement si Vector_sommet[v].get_marquage() == false , et le poid total du chemin de depart to v a en passant par u est plus petit que la valeur actuel de dist[v]
         
         if (Vector_sommet[v].get_marquage() == false && matrice_d_adjacence[u][v] > 0)
         {
             if (dist[u] != max_value && dist[u] + matrice_d_adjacence[u][v] < dist[v])
             {
                 dist[v] = dist[u] + matrice_d_adjacence[u][v];
                 Vector_sommet[v].pred = u;
             }
         }
       }
     }

     // Affichage matrice de distance entre le sommet source et les autres sommets
    printSolution(dist);
    std::stack <int> parent;

    
    std::cout << "------- CHEMIN -------" <<std::endl;
    
    std::cout << "Depart de " << depart << std::endl;
    
    for (int arriver=0; arriver<ordre-1;arriver++)
    {
        int current;
        
        if (arriver!=depart)
        {
            std::cout << "Arriver en : " << arriver << "  ";
            parent.push(arriver);
            current = Vector_sommet[arriver].pred;
            parent.push(current);
            
            
            while(current != depart)
            {
                current = Vector_sommet[current].pred;
                parent.push(current);
            }
            
            while(!(parent.empty()))
            {
                std::cout << parent.top();
                parent.pop();
                if (!(parent.empty()))
                {
                    std::cout << " -> ";
                }
            }
            std::cout << " " << std::endl;
        }
    }
    
}


void Graphe::display_VecArete()
{
    for(int i=0; i<m_nbAretes; i++) //Pour remplir le tableau de Sommets (nom des individus) avec le fichier
    {
        
        std::cout<<m_vecArete[i].m_s1.getnumerodesommet()<<"    "<<m_vecArete[i].m_s2.getnumerodesommet()<<"   "<<m_vecArete[i].m_poids<<std::endl;
        
    }
}

void Graphe::remplirVecArete(std::string nomFichier)
{
    
    std::ifstream fichier(nomFichier, std::ios::in);
    
    if(fichier)
    {
        
        fichier >> ordre; //on récupère l'ordre de la matrice
        fichier >> m_nbAretes; //on récupère le nombre d'arpete du graphe
        
        int temp1;
        int temp2;
        int temp3;
        
        for(int i=0; i<m_nbAretes; i++) //Pour remplir le tableau de Sommets (nom des individus) avec le fichier
        {
            fichier >> temp1;
            fichier >> temp2;
            fichier >> temp3;
            
            m_vecArete.push_back(Arete(temp1, temp2, temp3));
            
        }
        
        std::cout<<std::endl;
        
        
        Arete areteTemp;
        for(int i=0; i<m_nbAretes; i++) 
        {
            for(int j=0; j<m_nbAretes; j++)
            {
                if(m_vecArete[i].m_poids < m_vecArete[j].m_poids)
                {
                    areteTemp=m_vecArete[i];
                    m_vecArete[i]=m_vecArete[j];
                    m_vecArete[j]=areteTemp;
                }
            }
        }
        fichier.close();
    }
    
}

void Graphe::prim()
{
    std::vector <Sommet> newgraphe_marquage;
    set_marquage_vector(false);
    
    newgraphe_marquage.push_back(Vector_sommet[depart]);
    Vector_sommet[depart].set_marquage(true);
    
    while (newgraphe_marquage.size() != Vector_sommet.size()) {
        
        std::map <int, int> map_de_poid;
        int indice=-1;

        
        for (int i =0; i<newgraphe_marquage.size(); i++) {
            
            for (int j=0; j<m_vecArete.size(); j++)
            {
                if (m_vecArete[j].m_s1.getnumerodesommet() == newgraphe_marquage[i].getnumerodesommet() || m_vecArete[j].m_s2.getnumerodesommet() == newgraphe_marquage[i].getnumerodesommet())
                {
                    if (Vector_sommet[m_vecArete[j].m_s2.getnumerodesommet()].get_marquage() == false || Vector_sommet[m_vecArete[j].m_s1.getnumerodesommet()].get_marquage() == false)
                    {
                        map_de_poid[j] = m_vecArete[j].m_poids;
                    }

                }
            }

        }
        
        indice = trouverlepoidmin(map_de_poid);

        
        if (Vector_sommet[m_vecArete[indice].m_s1.getnumerodesommet()].get_marquage() == false)
        {
            Vector_sommet[m_vecArete[indice].m_s1.getnumerodesommet()].set_marquage(true);
            newgraphe_marquage.push_back(m_vecArete[indice].m_s1);
        }
        
        if (Vector_sommet[m_vecArete[indice].m_s2.getnumerodesommet()].get_marquage() == false)
        {
            Vector_sommet[m_vecArete[indice].m_s2.getnumerodesommet()].set_marquage(true);
            newgraphe_marquage.push_back(m_vecArete[indice].m_s2);
        }

   }
    
    
    std::cout << "Chemin final :  " << std::endl << std::endl;
    for (auto elem : newgraphe_marquage)
    {
        std::cout <<" -> "  << elem.get_numero_de_sommet();
    }
    std::cout << "    " << std::endl<< std::endl;
}
int Graphe::trouverlepoidmin(std::map <int, int> vector_de_poid)
{
    int min =4000;
    int indice=-1;
    for (auto elem : vector_de_poid)
    {
        if (elem.second<min)
        {
            min = elem.second;
            indice = elem.first;
        }
        
    }
    return indice;
}
