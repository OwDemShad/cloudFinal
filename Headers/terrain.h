//
//  terrain.h
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef terrain_h
#define terrain_h

#include <iostream>
#include <vector>
#include "position.h"
#include "case.h"


const int LIBRE = 0;

const int MUR = 1;

const int MIROIR1 = 2;  // '\'

const int MIROIR2 = 3;  // '/'

const int CIBLE = 6;

const int SEMIMIROIR1 = 4;  // '\'

const int SEMIMIROIR2 = 5;  // '/'


class Terrain
{
public:

    Terrain();

    /**
     * Constructeur de terrain : cree un terrain vide (classe abstraite)
     * @param [in] longueur - longueur du terrain
     * @param [in] hauteur - hauteur du terrain
     * @param [in] nbMiroirs - nombre de miroirs sur le terrain
     * @param [in] nbSemiMiroirs - nombre de semi miroirs sur le terrain
     * @param [in] nbCibles - nombre de cibles sur le terrain
     */
    Terrain(int longueur, int hauteur, int nbMiroirs, int nbSemiMiroirs, int nbCibles);

    /**
     * Destructeur virtuel
     */
    virtual ~Terrain();

    /**
     * Initialise un terrain depuis un fichier ou est enregistre la configuration du terrain
     * @param [in] ifst - fichier à charger
     */
    //virtual void charger(const std::string &nomFichier);

    /**
     * Retourne par reference la donnee privee d_terrain
     * @return std::vector<std::vector<Case>>& - le terrain
     */
    std::vector<std::vector<Case>>& terrain();

    /**
     * Retourne par reference la donnee privee d_terrain
     * @return std::vector<std::vector<Case>>& - le terrain
     */
    const std::vector<std::vector<Case>>& terrain() const;   // les const sont necessaires pour l'acces (dans la classe Affichage par exemple)

    /**
     * Indique si la case suivante est libre selon une position et une direction
     * La case est libre s'il n'y a pas de mur
     * @param [in] pos - la position a verifier
     * @param [in] direction - sens de deplacement du laser
     * @return boolean - vrai si la case est libre, faux sinon
     */
    virtual bool caseSuivanteEstLibre(const Position &pos, int direction) const = 0;

    /**
     * Positionne un element sur le terrain a une position
     * @param [in] element - element a placer --> 0 : rien, 1 : mur, 2 : \, 3 : /, 4 : cible
     * @param [in] pos - position de l'element sur le terrain
     */
    virtual void placeElement(int element, const Position &pos);


    /**
     * Verifie si une cible se trouve a une certaine position
     * @param [in] pos - position a laquelle on veut verifier s'il y a une cible
     * @return bool - vrai si il y a une cible
     */
    bool estCible(const Position &pos) const;

    /**
     * Indique le type de miroir a la position donnee
     * @param [in] pos - position a tester
     * @return int - 0 : pas de miroir; 2: \; 3 : /; 4 : \ (semi-miroir); 5 : / (semi-miroir)
     */
    int typeMiroir(const Position &pos) const ;

    /**
     * Indique si le jeu est termine
     * Le jeu est termine si le laser ne peut plus avancer, ou s'il a touche toutes les cibles
     * @return boolean - vrai si le jeu est termine
     */
    virtual bool fin() const = 0;

    /**
     * Decremente le nombre de cibles du terrain
     */
    void decrementeNombreDeCibles();


    /**
     * Detruit une cible
     * @param [in] pos - position dans le terrain
     */
    void detruitCible(Position &pos);


    /**
     * Fonction permettant de charger un terrain sauvegarde
     * @param [in] nomFichier - fichier a charger
     */
    virtual void charger(const std::string& nomFichier) = 0;

    // -------------------- Verification de la position --------------------

    /**
     * Verifie si la position dans le terrain est Libre
     * @param [in] pos - position dans le terrain
     * @return bool - vrai si la position est libre
     */
    bool positionLibre(Position &pos) const;


    /**
     * Verifie si la position est valide, ne sort pas du terrai
     * @param [in] pos - position a tester
     * @return bool - vrai si les positions ne sont pas hors du terrain
     */
    bool positionValide(Position &pos) const;



    // -------------------- Saisie des miroirs --------------------

    /**
     * Permet au joueur de saisir la position d'un miroir
     * @return pos - la position a laquelle il faut placer le miroir
     */
    Position saisirPositionMiroir();

    /**
     * Permet au joueur de saisir le type de miroir qu'il souhaite
     * @param [in] miroirSimple - permet de savoir s'il sagit de saisir des miroirs simple ou semi miroir
     * @return int - le miroir souhaite
     */
    int saisieTypeMiroir(bool miroirSimple);

    /**
     * methode qui permet au joueur de placer les miroirs
     */
    void placerMiroirs() ;


    // -------------------- Methodes de rappel --------------------
    /**
     * Fonction qui renvoie la longueur du terrain
     * @return int - la longueur
     */
    int longueur() const;

    /**
     * Fonction qui renvoie la hauteur du terrain
     * @return int - la hauteur
     */
    int hauteur() const;

    /**
     * Fonction qui renvoie le nombre de miroir
     * @return int - le nombre de miroir
     */
    int nbMiroirs() const;

    /**
    * Fonction qui renvoie le nombre de semi miroir
    * @return int - le nombre de semi miroir
    */
    int nbSemiMiroirs() const;


    /**
    * Fonction qui renvoie le nombre de cible
    * @return int - le nombre de cible
    */
    int nbCibles() const;

    // ------------------- TESTS --------------------
    void print(std::ostream &ost) const;



    // -------------------- Methodes de changement --------------------

    /**
     * Permet de changer la longueur du terrain
     * @param [in] longueur - longueur
     */
    void longueur(int longueur) ;

    /**
     * Permet de changer la hauteur du terrain
     * @param [in] hauteur - hauteur
     */
    void hauteur(int hauteur) ;

    /**
     * Permet de changer le nombre de miroir dans terrain
     * @param [in] nbMiroirs - nombre de miroir
     */
    void nbMiroirs(int nbMiroirs) ;

    /**
     * Permet de changer le nombre de semi miroir dans terrain
     * @param [in] nbSemiMiroirs - nombre de semi miroir
     */
    void nbSemiMiroirs(int nbSemiMiroirs) ;

    /**
     * Permet de changer le nombre de cible dans terrain
     * @param [in] nbCibles - nombre de cible
     */
    void nbCibles(int nbCibles) ;

protected:
    int d_longueur, d_hauteur;
    int d_nbMiroirs;
    int d_nbSemiMiroirs;
    int d_nbCibles;
    std::vector<std::vector<Case>> d_terrain;
};

#endif /* terrain_h */
