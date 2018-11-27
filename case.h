//
//  case.hpp
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef case_h
#define case_h

class Element;

class Case
{
    friend class Terrain;
    
public:
    Case();
    int element() const;
    
private:
    Element* d_element;
};

#endif /* case_h */
