#ifndef __COMPARISION_H__
#define __COMPARISION_H__
#include "ArbolAVL.h"
#include <set>
#include <fstream>
#include <ctime>
#include <cstring>
template <class T>
class Comparision{
    private:
        ArbolAVL<T> AVL;
        std::set<T> RB;
    public:
        bool insertToRB(T value);
        bool deleteFromRB(T value);
        bool deleteFromAVL(T value);
        bool insertToAVL(T value);
        bool insertToBoth(T value);
        bool deleteFromBoth(T value);
        double insertFileDataToRB(char* file_name);
        double insertFileDataToAVL(char* file_name);
        std::pair<double, double> insertFileDataToBoth(char* file_name);
        bool compare();
        int size();
};
#include "Comparision.hxx"
#endif
