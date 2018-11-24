//
//  element.hpp
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef element_hpp
#define element_hpp

class Element
{
public:
    Element();
    virtual ~Element();
    
    virtual int valeur() const;
    
private:
    //rien = 0, mur = 1, miroir = 2, cible = 3
};

#endif /* element_hpp */
