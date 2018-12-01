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
    Case(bool murHaut, bool murDroit, bool murBas, bool murGauche);
private:
    bool d_murHaut, d_murDroit, d_murBas, d_murGauche;
};

#endif /* case_h */
