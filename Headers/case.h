//
//  case.h
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef case_h
#define case_h


class Case
{
public:
    Case();
    Case(bool murHaut, bool murDroit, bool murBas, bool murGauche, int val);
    Case(int valeur);
     void changerValeur(int valeur) ;

      int valeur() const ;
     bool estMurHaut() const ;
     bool estMurDroit() const ;
     bool estMurBas() const ;
     bool estMurGauche() const ;

private:
    bool d_murHaut, d_murDroit, d_murBas, d_murGauche;
    int d_valeur;
};

#endif /* case_h */
