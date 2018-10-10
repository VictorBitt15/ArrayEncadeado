//
//  Node.hpp
//
//  Created by Eiji Adachi Medeiros Barbosa 
//

#ifndef Node_hpp
#define Node_hpp

#include <string>

/**
 Just a class to encapsulate a given value.
 In this particular case, the value is a string.
 */
class Node
{
private:
    std::string value;
public:
    Node();
    
    Node( std::string val );
    
    std::string getValue();
    
    void setValue(std::string val);
};
#endif /* Node_hpp */
