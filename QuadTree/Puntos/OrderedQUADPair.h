#ifndef __ORDEREDQUADPAIR_H__
#define __ORDEREDQUADPAIR_H__
#include <algorithm>
#include <string>
template <class T>
class OrderedQUADPair
{
    private:
        T data1;
        T data2;

    public:
        OrderedQUADPair(T data1, T data2);
        ~OrderedQUADPair();
        T getData1();
        T getData2();
        void setData1 (T data);
        void setData2 (T data);
        std::pair<T, T> getData();
        std::string print();
};
#include "OrderedQUADPair.hxx"
#endif