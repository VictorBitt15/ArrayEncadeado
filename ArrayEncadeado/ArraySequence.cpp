//
//  ArraySequence.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "Sequence.h"
#include "Node.h"
#include <iostream>

Sequence::Sequence()
{
    content = new Node*[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        content[i] = nullptr;
    }
    this->quantity = 0;
    this->init = 0;
    this->end = 0;
}

Sequence::~Sequence()
{
    delete [] content;
}

/**
 Returns the i-th element in this sequence.
 */
Node* Sequence::get(int i)
{
    // Cuidado aqui! Se eu quero acessar o 1o elemento, preciso acessar a posição 0.
    // Ou seja, para acessar o i-ésimo elemento da sequência, preciso acessar a posição i-1 do array
    return content[i-1];
}

/**
 Inserts the element in this sequence.
 After inserting, the element must be in the i-th position.
 */
void Sequence::insert(int i, Node* element)
{
    int fim=this->end;
    for(int j=fim;j<i-1;--j)
    {
      content[j]=content[j-1];
    }
    content[i-1]=element;
    this->end++;
    this->quantity++;
}

/**
 Inserts the element in the begin of this sequence.
 After inserting, the element will be the first in the sequence.
 */
void Sequence::insertBegin(Node* element)
{
    int inicio=this->init;
    int fim=this->end;
    for(int i=fim;i>inicio;--i)
    {
      content[i]=content[i-1];
    }
    content[inicio]=element;
    this->end++;
    this->quantity++;
}

/**
 Inserts the element in the end position of this sequence.
 After inserting, the element will be the last in the sequence.
 */
void Sequence::insertEnd(Node* element)
{
    int fina=this->end;
    content[fina]= element;
    this->end++;
    this->quantity++;
}

/**
 Removes the element in the i-th position of this sequence.
 Returns the removed element.
 */
Node* Sequence::remove(int i)
{
    if(this->quantity == 1)
    {
      return removeBegin();
    }

    Node *antigo=get(i);
    std::string valor =  antigo->getValue();
    int fina=this->end;
    for(int j=i-1; j>fina-1; ++j)
    {
      content[j]=content[j+1];
    }
    content[fina-1]=nullptr;
    --this->end;
    --this->quantity;
    return antigo;
}

/**
 Removes the first element in this sequence.
 Returns the removed element.
 */
Node* Sequence::removeBegin()
{
    Node * antigo =(content[this->init]);
    int inicio= this->init;
    int fina= this->end;
    for(int i=inicio; i<fina-1; ++i)
    {
      content[i]=content[i+1];
    }
    content[fina-1]=nullptr;
    --this->end;
    --this->quantity;
    return antigo;
}
/**
 Removes the last element in this sequence.
 Returns the removed element.
 */
Node* Sequence::removeEnd()
{
    Node *antigo=(content[this->end-1]);
    int fina=this->end;
    content[fina]=nullptr;
    this->end--;
    this->quantity--;
    return antigo;
}

bool Sequence::isEmpty()
{
    return this->getQuantity()==0;
}

int Sequence::getQuantity()
{
    return this->quantity;
}
