//
//  main.cpp
//  PLaser
//
//  Created by Thibaud B. on 28/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#include <iostream>
#include "terrain.h"
#include "case.h"
#include "position.h"


#include <ctime>
#include <cstdlib>


int main(int argc, const char * argv[]) {
    
    //srand(time(NULL));
    //Terrain t {5,3};
    
    Position p{4,2};
    Case c {p};
    
}

/*
Faire un constructeur de terrain avec choix de la version.
Si V1 -> murs épais, pas de monstres
Si V2 -> murs fins, monstres


Héritage sur murs 
Mur virtuel pur 
    MurPlein avec info si oui/non estMur
    MurFin avec info si murHaut/Bas/G/D estMur


Case doit savoir en fonction de la version si le mur est épais ou pas pour pouvoir avoir les infos de si la case est un mur ou pas ou si bords de la case sont des murs ou pas

 Mur hérite de Element
 
 Ajouter position dans classe mur
*/
