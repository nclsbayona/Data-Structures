#include "NodoQUAD.h"
#include <math.h>
#include <iostream>

int NodoQUAD::getData()
{
    return this->data;
}

NodoQUAD::NodoQUAD(int data)
{
    this->data = data;
}

NodoQUAD::~NodoQUAD()
{
    if (this->upLeft)
        delete this->upLeft;
    if (this->upRight)
        delete this->upRight;
    if (this->downLeft)
        delete this->downLeft;
    if (this->downRight)
        delete this->downRight;
}

std::string NodoQUAD::preOrder(bool string)
{
    std::string ret = "";
    ret += this->toString(true);
    if (this->upLeft != NULL)
        ret += this->upLeft->preOrder(true);
    if (this->upRight != NULL)
        ret += this->upRight->preOrder(true);
    if (this->downRight != NULL)
        ret += this->downRight->preOrder(true);
    if (this->downLeft != NULL)
        ret += this->downLeft->preOrder(true);
    return ret;
}

std::list<NodoQUAD *> NodoQUAD::preOrder(int num)
{
    typedef std::list<NodoQUAD *> lista;
    lista ret;
    lista ret2;
    ret.push_back(this);
    //Misc
    if (num == -100)
    {
        if (this->upLeft != NULL)
        {
            ret.push_back(this->upLeft);
        }
        if (this->upRight != NULL)
        {
            ret.push_back(this->upRight);
        }
        if (this->downLeft != NULL)
        {
            ret.push_back(this->downLeft);
        }
        if (this->downRight != NULL)
        {
            ret.push_back(this->downRight);
        }
    }
     //End misc
    else if (num==-1)
    {
        if (this->upLeft != NULL)
        {
            ret2 = this->upLeft->preOrder(-1);
            for (lista::iterator it = ret2.begin(); it != ret2.end(); ++it)
                ret.push_back((*it));
        }
        if (this->upRight != NULL)
        {
            ret2 = this->upRight->preOrder(-1);
            for (lista::iterator it = ret2.begin(); it != ret2.end(); ++it)
                ret.push_back((*it));
        }

        if (this->downLeft != NULL)
        {
            ret2 = this->downLeft->preOrder(-1);
            for (lista::iterator it = ret2.begin(); it != ret2.end(); ++it)
                ret.push_back((*it));
        }
        if (this->downRight != NULL)
        {
            ret2 = this->downRight->preOrder(-1);
            for (lista::iterator it = ret2.begin(); it != ret2.end(); ++it)
                ret.push_back((*it));
        }
    }
    else
    {
        if (this->upLeft != NULL)
        {
            ret2 = this->upLeft->preOrder(10);
            for (lista::iterator it = ret2.begin(); it != ret2.end(); ++it)
                ret.push_back((*it));
        }
        if (this->upRight != NULL)
        {
            ret2 = this->upRight->preOrder(10);
            for (lista::iterator it = ret2.begin(); it != ret2.end(); ++it)
                ret.push_back((*it));
        }
        if (this->downRight != NULL)
        {
            ret2 = this->downRight->preOrder(10);
            for (lista::iterator it = ret2.begin(); it != ret2.end(); ++it)
                ret.push_back((*it));
        }
        if (this->downLeft != NULL)
        {
            ret2 = this->downLeft->preOrder(10);
            for (lista::iterator it = ret2.begin(); it != ret2.end(); ++it)
                ret.push_back((*it));
        }
    }
    return ret;
}

NodoQUAD *NodoQUAD::getUpLeft()
{
    return this->upLeft;
}

NodoQUAD *NodoQUAD::getUpRight()
{
    return this->upRight;
}

NodoQUAD *NodoQUAD::getDownLeft()
{
    return this->downLeft;
}

NodoQUAD *NodoQUAD::getDownRight()
{
    return this->downRight;
}

void NodoQUAD::setData(int data)
{
    this->data = data;
}

void NodoQUAD::setUpLeft(NodoQUAD *upLeft)
{
    this->upLeft = upLeft;
}

void NodoQUAD::setUpRight(NodoQUAD *upRight)
{
    this->upRight = upRight;
}

void NodoQUAD::setDownLeft(NodoQUAD *downLeft)
{
    this->downLeft = downLeft;
}

void NodoQUAD::setDownRight(NodoQUAD *downRight)
{
    this->downRight = downRight;
}

std::string NodoQUAD::toString(bool unique)
{
    std::string ret = "- ";
    ret += std::to_string(this->data);
    ret += " ";
    return ret;
}

bool NodoQUAD::availableSpace()
{
    const int COMBINED = 2;
    if (this->data < COMBINED)
        return false;
    if (!(this->upLeft && this->upRight && this->downRight && this->downLeft))
        return true;
    else
    {
        bool c = false;
        if (!c && this->upLeft->data > 1)
            c = this->upLeft->availableSpace();
        if (!c && this->upRight->data > 1)
            c = this->upRight->availableSpace();
        if (!c && this->downRight->data > 1)
            c = this->downRight->availableSpace();
        if (!c && this->downLeft->data > 1)
            c = this->downLeft->availableSpace();
        return c;
    }
    return false;
}

std::string NodoQUAD::toString(int level, std::string car)
{
    std::string ret = "";
    for (int i = 0; i < level; i++)
        ret += "\t\t";
    ret += car;
    ret += this->toString(true);
    ret += "\n";
    if (this->upLeft != NULL)
        ret += this->upLeft->toString(level + 1, "UpLeft: ");
    if (this->upRight != NULL)
        ret += this->upRight->toString(level + 1, "UpRight: ");
    if (this->downRight != NULL)
        ret += this->downRight->toString(level + 1, "DownRight: ");
    if (this->downLeft != NULL)
        ret += this->downLeft->toString(level + 1, "DownLeft: ");
    ret += '\n';
    return ret;
}

int NodoQUAD::realSize(int level, int total_dimension)
{
    const int COMBINED = 2;
    int dim = pow(COMBINED, (log10(total_dimension) / log10(2)) - level);
    int dim2 = 0;

    /*
    std::cout<<"This "<<this->data<<" tiene ";
    std::cout<<this->upLeft<<'\n';
    std::cout<<this->upRight<<'\n';
    std::cout<<this->downLeft<<'\n';
    std::cout<<this->downRight<<'\n';

    if (!(this->upLeft||this->upRight||this->downRight||this->downLeft)){
        if (this->upLeft)
            dim2+=this->upLeft->realSize(level+1, total_dimension);
        if (this->upRight)
            dim2+=this->upRight->realSize(level+1, total_dimension);
        if (this->downRight)
            dim2+=this->downRight->realSize(level+1, total_dimension);
        if (this->downLeft)
            dim2+=this->downLeft->realSize(level+1, total_dimension);
        return ((dim-dim2)==0)?dim:-1;
    }

    */
    return dim;
}

int NodoQUAD::levelOfNode(NodoQUAD *node, int level)
{
    if (node == this)
        return level;
    if (!(this->upLeft || this->upRight || this->downRight || this->downLeft))
        return -1;
    int act = -1;
    if (act < 0 && this->upLeft)
        act = this->upLeft->levelOfNode(node, level + 1);
    if (act < 0 && this->upRight)
        act = this->upRight->levelOfNode(node, level + 1);
    if (act < 0 && this->downRight)
        act = this->downRight->levelOfNode(node, level + 1);
    if (act < 0 && this->downLeft)
        act = this->downLeft->levelOfNode(node, level + 1);
    return act;
}