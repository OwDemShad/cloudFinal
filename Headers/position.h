//
//  position.h
//  PLaser
//
//  Created by Thibaud B. on 28/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef position_h
#define position_h

//Coordonnées des cases du terrain
class Position
{
public:
    Position (int x, int y);
    Position (const Position& p);
    int x() const;
    int y() const;
    void changerX(int x);
    void changerY(int y);
    
private:
    int d_x, d_y;
};

#endif /* position_h */
