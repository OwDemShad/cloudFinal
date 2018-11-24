//
//  laser.hpp
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef laser_hpp
#define laser_hpp

class Laser
{
public:
    
    void avance();
    void calculeTrajectoire();
private:
    int d_direction; //0 haut, 1 droite, 2 bas, 3 gauche
    int d_x, d_y; //coordonnées du laser
};

#endif /* laser_hpp */
