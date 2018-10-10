//
//  Node.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "Node.h"

Node::Node()
{
}

Node::Node( std::string val )
{
    this->setValue(val);
}

std::string Node::getValue()
{
    return this->value;
}

void Node::setValue(std::string val)
{
    this->value = val;
}
