//
// Created by OwDemShad on 04/12/2018.
//

#ifndef PROJETLASER_INTERGERZ_H
#define PROJETLASER_INTERGERZ_H


class Intergerz
{
public:
    /**
     * Construit un Intergerz
     * @param valeur [in] - entier representant un Intergerz
     */
    Intergerz(int valeur);

    /**
     * Change la valeur d_valeur par valeur
     * @param valeur [in] - nouvelle valeur
     */
    void changerValeur(int valeur);

    /**
     * Retourne l'attribut d_valeur
     * @return int [in] - d_valeur
     */
    int valeur() const;
private:
    int d_valeur;
};


#endif //PROJETLASER_INTERGERZ_H
