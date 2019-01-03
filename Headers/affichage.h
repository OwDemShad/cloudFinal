//
// Created by Dorian on 01/12/2018.
//

#ifndef LASER_AFFICHAGE_H
#define LASER_AFFICHAGE_H


#include "terrain.h"
#include "terrainMursPleins.h"
#include "terrainMursFins.h"
#include "laser.h"

class Affichage
{
public:
    /**
     * Constructeur d'affichage
     *  Crée un Affichage avec les dimensions du terrain
     * @param [in] longueur - longueur du terrain
     * @param [in] hauteur - hauteur du terrain
     */
    Affichage(int longueur, int hauteur);

    /**
     * Trace un carre de cote d_tailleCase a poartir d'une position de depart
     * @param [in] positionDepart - Position de depart du carre
     */
    void traceCarre(const Position& positionDepart) const;

    /**
     * Trace une cible aux coordonnees de la position passee en parametre, avec un rayon egal a d_tailleCase / radiusDivizer
     * Affiche deux cercles (un grand de dimensions de la case et une plus petit)
     * @param {in] pos - Position a laquelle la cible est tracee
     * @param [in] radiusDivizer - entier divisant d_tailleCase (par defaut 50)
     */
    void traceCible(const Position& pos, int radiusDivizer) const ;

    /**
     * Change la couleur du pinceau avec l'entier passe en parametre correspondant a la couleur
     * --> on utilise les constantes donnees par winbgi : GREEN, WHITE, RED, BLUE
     * @param [in] couleur - entier correspondant a la couleur
     */
    void changerCouleurTrait(int couleur) const ;

    /**
     * Change l'epaisseur du trait avec l'entier passe en parametre
     * @param [in] epaisseur - entier representant l'epaisseur en pixels
     */
    void changerEpaisseurTrait(int epaisseur) const ;

    /**
     * Affiche un TerrainMursPleins dans une fenetre graphique
     * @param [in] terrain - terrain a afficher
     */
    void afficherTerrainMursPleins(const Terrain &terrain) const ;

    /**
     * Affiche un TerrainMursFins dans une fenetre graphique
     * @param [in] terrain - terrain a afficher
     */
    void afficherTerrainMursFins(const Terrain &terrain) const ;;

    /**
     * Affiche un miroir en diagonale d'une position de depart a une position d'arrivee
     * @param [in] depart - position de depart
     * @param [in] arrivee - position d'arrivee
     */
    void afficherMiroir(const Position &depart, const Position &arrivee) const ;

    /**
     * Affiche successivement tous les miroirs du terrain en le parcourant et en appelant la methode afficherMiroir(depart, arrivee)
     * @param [in] terrain - terrain dont il faut afficher les miroirs
     */
    void afficherMiroirs(const Terrain &terrain) const ;

    /**
     * Affiche un demi trait de laser, c'est a dire un trait d'une longueur de d_tailleCase / 2
     * @param [in] depart - position de depart
     * @param [in] arrivee - position d'arrivee
     */
    void afficherLaserUnDemiTrait(const Position &depart, const Position &arrivee) const ;

    /**
     * Affiche un demi trait de laser dans le sens Nord (en se deplacant vers le Nord)
     * Appelle la mehotde afficherLaserUnDemiTrati(depart, arrivee)
     * @param [in] depart - position de depart
     * @param [in] arrivee - position d'arrivee
     */
    void afficherLaserUnDemiTraitSensNord(const Position &depart, const Position &arrivee) const ;

    /**
     * Affiche un demi trait de laser dans le sens Est (en se deplacant vers l'Est)
     * Appelle la mehotde afficherLaserUnDemiTrati(depart, arrivee)
     * @param [in] depart - position de depart
     * @param [in] arrivee - position d'arrivee
     */
    void afficherLaserUnDemiTraitSensEst(const Position &depart, const Position &arrivee) const ;

    /**
     * Affiche un demi trait de laser dans le sens Sud (en se deplacant vers le Sud)
     * Appelle la mehotde afficherLaserUnDemiTrati(depart, arrivee)
     * @param [in] depart - position de depart
     * @param [in] arrivee - position d'arrivee
     */
    void afficherLaserUnDemiTraitSensSud(const Position &depart, const Position &arrivee) const ;

    /**
     * Affiche un demi trait de laser dans le sens Ouest (en se deplacant vers l'Ouest)
     * Appelle la mehotde afficherLaserUnDemiTrati(depart, arrivee)
     * @param [in] depart - position de depart
     * @param [in] arrivee - position d'arrivee
     */
    void afficherLaserUnDemiTraitSensOuest(const Position &depart, const Position &arrivee) const ;

    /**
     * Affiche le premier demi trait du laser (le laser s'afficher demi trait par demi trait)
     * @param [in] laser - laser a afficher
     */
    void afficherLaserPremierDemiTrait(const Laser &laser) const ;

    /**
     * Affiche le deuxieme demi trait du laser (le laser s'affiche demi trait par demi trait)
     * @param [in] laser - laser a afficher
     */
    void afficherLaserDeuxiemeDemiTrait(const Laser &laser) const ;

    /**
     * Affiche le premier trait du laser de la grille en position (0,0), depassant legerement du terrain sur la gauche afin d'indiquer d'ou vient le laser
     * Appelle la methode afficherLaserUnDemiTrait(depart,laser)
     * @param [in] laser - laser a afficher
     */
    void afficherLaserPremierTraitGrille(const Laser &laser) const ;

private:
    int d_longueur, d_hauteur;  // tailles du plateau
    const int d_tailleCase = 50;
};


#endif //LASER_AFFICHAGE_H
