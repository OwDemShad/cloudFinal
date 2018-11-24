//
//  miroir.hpp
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef miroir_hpp
#define miroir_hpp

#include "element.hpp"

class Miroir : public Element
{
public:
    Miroir();
    virtual int valeur() const override;
    
private:
    bool d_orientationMiroir; // \0  /1
};

#endif /* miroir_hpp */
