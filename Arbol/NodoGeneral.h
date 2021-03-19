#ifndef __NODO_H__
#define __NODO_H__
#include <list>
#include <string>
template <typename T>
class NodoGeneral{
    private:
        T data;
        std::list<NodoGeneral<T>*> children;
    public:
        NodoGeneral(T data);
        ~NodoGeneral();
        void recursiveDelete();
        void childRecursiveDelete(NodoGeneral<T>* node);
        T getData();
        void setData(T data);
        std::list<NodoGeneral<T>*> getChildren();
        void setChildren (std::list<NodoGeneral<T>*> children);
        NodoGeneral<T>* addChild(NodoGeneral<T>* child);
        NodoGeneral<T>* addChild(T data);
        std::string print(int level=0);
        bool leaf();
        
};
#include "NodoGeneral.hxx"
#endif
