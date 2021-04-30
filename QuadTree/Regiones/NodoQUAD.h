#ifndef _NODOQUAD_H
#define _NODOQUAD_H
#include <string>
#include <list>
class NodoQUAD
{
    private:
        int data;
        NodoQUAD *upLeft;
        NodoQUAD *upRight;
        NodoQUAD *downRight;
        NodoQUAD *downLeft;

    public:
        NodoQUAD(int data);
        ~NodoQUAD();
        int getData();
        NodoQUAD *getUpLeft();
        NodoQUAD *getUpRight();
        NodoQUAD *getDownLeft();
        NodoQUAD *getDownRight();
        void setData(int data);
        void setUpLeft(NodoQUAD *upLeft);
        void setUpRight(NodoQUAD *upRight);
        void setDownLeft(NodoQUAD *downLeft);
        void setDownRight(NodoQUAD *downRight);
        std::string toString(int level=0, std::string car="Head ");
        std::string toString(bool unique);
        bool availableSpace();
        int realSize(int level, int total_dimension);
        std::string preOrder(bool string);
        std::list<NodoQUAD*> preOrder(int num);
        int levelOfNode(NodoQUAD* node, int level=0);
};
#endif
