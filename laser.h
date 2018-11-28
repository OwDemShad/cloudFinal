//
//  laser.h
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef laser_h
#define laser_h

#include "case.h"

class Laser
{
public:
    //Construit le laser avec sa position initiale en param
    Laser(Case* caseDepart);
    
    //Fait avancer le laser vers la case suivante
    void avance();
    
    //Calcule la trajectoire suivante en fonction de l'élément dans la case
    void calculeTrajectoire();
    
private:
    Case* d_caseActuelle;
    int d_direction; //0 haut, 1 droite, 2 bas, 3 gauche
};

#endif /* laser_h */
