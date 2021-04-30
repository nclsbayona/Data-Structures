#include "ArbolQUAD.h"
#include <cmath>
#include <fstream>
#include<iostream>
#include<string>
ArbolQUAD::ArbolQUAD(char *file_name, char *pbm_name)
{
    //Funciona
    const int MAX = 100, ASCII_ZERO = 48;
    this->file_name = file_name;
    this->pbm_name = pbm_name;
    std::ifstream in(file_name);
    getline(in, this->size);
    char c;
    while (in.get(c))
        this->insertNode((int)(c)-ASCII_ZERO);
}

std::string ArbolQUAD::printTree()
{
    //Funciona 10/10
    if (this->head)
        return "Tree\n" + this->head->toString() + "\n";
    else
        return " ";
}

NodoQUAD *ArbolQUAD::insertNode(int data)
{
    if (!this->head)
    {
        //Sirve
        this->head = new NodoQUAD(data);
        return this->head;
    }
    NodoQUAD *to_add = new NodoQUAD(data);
    bool c;
    for (NodoQUAD *node = this->head; node->availableSpace();)
    {
        c = false;
        //Sirve
        if (!node->getUpLeft())
        {
            node->setUpLeft(to_add);
            return to_add;
        }
        else if (node->getUpLeft()->availableSpace())
        {
            node = node->getUpLeft();
            continue;
        }
        else if (!node->getUpRight())
        {
            node->setUpRight(to_add);
            return to_add;
        }
        else if (node->getUpRight()->availableSpace())
        {
            node = node->getUpRight();
            continue;
        }
        else if (!node->getDownRight())
        {
            node->setDownRight(to_add);
            return to_add;
        }
        else if (node->getDownRight()->availableSpace())
        {
            node = node->getDownRight();
            continue;
        }
        else if (!node->getDownLeft())
        {
            node->setDownLeft(to_add);
            return to_add;
        }
        else if (node->getDownLeft()->availableSpace())
        {
            node = node->getDownLeft();
            continue;
        }
    }
    return NULL;
}

ArbolQUAD::~ArbolQUAD()
{
    //Funciona
    delete this->head;
}

std::string ArbolQUAD::getSize()
{
    //funciona
    return this->size;
}

std::string ArbolQUAD::preOrder(bool string)
{
    //Funciona
    return this->head->preOrder(true);
}

std::list<NodoQUAD *> ArbolQUAD::preOrder(int num)
{
    //Funciona
    return this->head->preOrder(num);
}

int ArbolQUAD::realSize()
{
    //Funciona
    int i = 0;
    while (this->size[i] > 47 && this->size[i++] < 58)
        ;
    int dimension = std::stoi(this->size.substr(i));
    return this->head->realSize(0, dimension);
}

int ArbolQUAD::levelOfNode(NodoQUAD *node)
{
    if (!this->head)
        return -1;
    return this->head->levelOfNode(node);
}

bool ArbolQUAD::equals()
{
    typedef std::list<NodoQUAD *> lista;
    typedef std::list<int> lista2;
    lista2 data;
    lista c = this->preOrder(100);
    lista::iterator it = c.begin();
    char ch;
    const int ASCII_ZERO = 48;
    std::ifstream in(this->file_name);
    std::string f;
    getline(in, f);
    while (in.get(ch))
        data.push_back((int)(ch)-ASCII_ZERO);
    lista2::iterator it2 = data.begin();
    while (it != c.end() && it2 != data.end())
    {
        if ((*it)->getData() != (*it2))
            return false;
        it++;
        it2++;
    }
    if (it != c.end() || it2 != data.end())
        return false;
    return true;
}

void ArbolQUAD::convertToPBM()
{
    typedef std::list<NodoQUAD *> lista;
    lista quad_tree = this->preOrder(-100);
    lista::iterator it = quad_tree.begin();
    const int SIZE = this->realSize(), ASCII_ZERO = 48, COMBINED = 2;
    const char START = 'X';
    char car;
    std::string ret = "";
    char **matriz = new char *[SIZE];
    for (int i = 0; i < SIZE; ++i)
    {
        matriz[i] = new char[SIZE];
        for (int j = 0; j < SIZE; ++j)
        {
            matriz[i][j] = START;
        }
    }
    car = (*it)->getData();
    if (car != COMBINED)
    {
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                matriz[i][j] = (car + ASCII_ZERO);
    }
    else
        color(quad_tree, 0, 0, 0, 0, SIZE, START, matriz, COMBINED);

    std::ofstream file;
    file.open(this->pbm_name);
    if (file.is_open())
    {
        file << "P1\n"<<"# Imagen sacada de " << this->file_name << "\n" << (char*)this->size.c_str()<<'\n';
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                file << matriz[i][j] << " ";
            }
            file << std::endl;
        }
    }
    else
    {
        std::cout << "No se pudo crear el archivo" << "/n";
    }
}
void ArbolQUAD::color(std::list<NodoQUAD *> hijos, int startX, int startY, int x, int y, int tam, const char START, char **matrix, const int COMBINED)
{
    //I don't need the first position, because it's th
    //same node (Or might be 2), else i'll paint it in the other function
    std::list<NodoQUAD *>::iterator it = hijos.begin();
    advance(it, 1);
    if (it == hijos.end())
        return;
    int car;
    const int ASCII_ZERO = 48;
    int w, k, real_size;
    // Color children, if the children is COMBINED, call again the function with the appropiate parameters from that node
    for (; it != hijos.end(); ++it)
    {
        car = (*it)->getData();
        real_size = (*it)->realSize(this->levelOfNode(*it), this->realSize());
        if (car != COMBINED)
        {
            for (w = 0; w < real_size; ++w)
                for (k = 0; k < real_size; ++k)
                    matrix[y + w][x + k] = (car + ASCII_ZERO);
            x += k;
            x = x % (startX + tam);
            if (x == 0)
            {
                x = startX;
                y += w;
                y = y % (startY + tam);
            }
        }
        else
        {
            if (matrix[y][x] != START)
                startX += tam / 2;
            if (startX >= this->realSize())
            {
                startX = 0;
                startY += tam / 2;
            }
            x = startX;
            y = startY;
            color((*it)->preOrder(-100), startX, startY, x, y, real_size, START, matrix, COMBINED);
        }
    }
}