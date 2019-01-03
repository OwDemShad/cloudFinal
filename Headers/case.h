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

    /**
     * Fonction qui change la valeur de la case
     * @param [in] valeur - valeur à placer
     */
     void changerValeur(int valeur) ;

     /**
      * Retourne la valeur de la case
      * @return int - valeur de la case
      */
     int valeur() const ;

     /**
      * Verifie si le cote du haut est un mur
      * @return bool - vrai si il y a un mur sur le cote haut
      */
     bool estMurHaut() const ;

    /**
     * Verifie si le cote droit est un mur
     * @return bool - vrai si il y a un mur sur le cote droit
     */
     bool estMurDroit() const ;

    /**
     * Verifie si le cote du bas est un mur
     * @return bool - vrai si il y a un mur sur le cote bas
     */
     bool estMurBas() const ;

    /**
     * Verifie si le cote gauche est un mur
     * @return bool - vrai si il y a un mur sur le cote gauche
     */
     bool estMurGauche() const ;

private:
    bool d_murHaut, d_murDroit, d_murBas, d_murGauche;
    int d_valeur;
};

#endif /* case_h */
