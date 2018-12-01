//
// Created by Dorian on 01/12/2018.
//

#include "../Headers/terrainMursPleins.h"

TerrainMursPleins::TerrainMursPleins(int longueur, int hauteur, int nbMiroirs, int nbSemiMiroirs, int nbCibles) : Terrain{longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles}, d_terrain{}
{

}

void TerrainMursPleins::charger(const std::ifstream &ifst)
{

}

bool TerrainMursPleins::caseSuivanteEstLibre(const Position &pos, int direction) const
{
    switch(direction)
    {
        case 0 :
            if(pos.y() == 0) return false;
            else return estMur(Position{pos.x(), pos.y() - 1});

        case 1 :
            if(pos.x() == d_longueur) return false;
            else return estMur(Position{pos.x() + 1, pos.y()});

        case 2 :
            if(pos.y() == d_hauteur) return false;
            else return estMur(Position{pos.x(), pos.y() + 1});

        case 3 :
            if(pos.x() == 0) return false;
            else return estMur(Position{pos.x() - 1, pos.y()});

        default: break;
    }
}

void TerrainMursPleins::placeElement(int element, const Position &pos)
{
    d_terrain[pos.x()][pos.y()] = element;
}

bool TerrainMursPleins::estMur(const Position &pos) const
{
    return d_terrain[pos.x()][pos.y()] == 1;
}

int TerrainMursPleins::typeMiroir(const Position &pos) const
{
    return d_terrain[pos.x()][pos.y()];
}

bool TerrainMursPleins::fin() const
{

}




