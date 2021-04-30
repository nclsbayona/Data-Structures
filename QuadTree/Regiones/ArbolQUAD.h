#ifndef _ARBOLQUAD_H
#define _ARBOLQUAD_H
#include "NodoQUAD.h"
#include <fstream>
class ArbolQUAD
{
    private:
        std::string size;
        char *file_name;
        char *pbm_name;
        NodoQUAD *head;

    public:
        ArbolQUAD(char *file_name, char *pbm_name);
        ~ArbolQUAD();
        std::string getSize();
        NodoQUAD *insertNode(int data);
        std::string printTree();
        int realSize();
        std::string preOrder(bool string);
        std::list<NodoQUAD *> preOrder(int num=0);
        bool equals();
        int levelOfNode(NodoQUAD* node);
        void convertToPBM();
        void color(std::list<NodoQUAD *> hijos, int startX, int startY, int x, int y, int tam, const char START, char **matrix, const int COMBINED);
};

#endif
