#include "ArbolGeneral.h"

template <class T>
ArbolGeneral<T>::~ArbolGeneral(){
    if(this->head){
        int tam=this->head->getChildren().size();
        this->head->recursiveDelete();
        if (tam)
            delete this->head;
    }
}

template <class T>
ArbolGeneral<T>::ArbolGeneral(T head_data){
    this->head=new NodoGeneral<T> (head_data);
}

template <class T>
ArbolGeneral<T>::ArbolGeneral(NodoGeneral<T>* head){
    this->head=head;
}

template <class T>
NodoGeneral<T>* ArbolGeneral<T>::getHead(){
    return this->head;
}

template <class T>
void ArbolGeneral<T>::setHead(NodoGeneral<T> *head){
    this->head=head;
}

template <class T>
int ArbolGeneral<T>::level (NodoGeneral<T> *node){
    if (!this->head)
        return 0;
    return this->lookLevel(node, this->head);
}

template <class T>
int ArbolGeneral<T>::lookLevel(NodoGeneral<T>* looking, NodoGeneral<T> *node, int level){
    if (looking==NULL || node==NULL)
        return -1;
    if (node==looking)
        return level;
    else if (!node->getChildren().empty()){
        int i=0, ret=-1, val;
        std::list<NodoGeneral<T>*> c=node->getChildren();
        typename std::list<NodoGeneral<T>*>::iterator it=c.begin();
        while (it != c.end()){
            val=this->lookLevel(looking, *it, level+1);
            if (ret<val)
                ret=val;
            it++;
        }
        return ret;
    }
    else
        return -1;
}

template <class T>
int ArbolGeneral<T>::highness(){
    if (this->head==NULL)
        return -1;
    return this->maxHighness(this->head, 0);
}

template <class T>
int ArbolGeneral<T>::maxHighness(NodoGeneral<T> *node, int level){
    if (node->getChildren().empty())
        return level;
    else{
        int val, max=0;
        std::list<NodoGeneral<T>*> c=node->getChildren();
        typename std::list<NodoGeneral<T>*>::iterator it=c.begin();
        while (it != c.end()){
            val=this->maxHighness(*it, level+1);
            if (val>max)
                max=val;
            advance (it, 1);
            advance (it, 1);
        }
        return max;
    }
        
}

template <class T>
std::string ArbolGeneral<T>::printTree(){
    if (this->head)
        return "Tree\n"+this->head->print()+"\n";
    else
        return "Tree\n";
}

template <class T>
int ArbolGeneral<T>::pathLength(NodoGeneral<T> *source, NodoGeneral<T> *destination){
    if (source==NULL || destination==NULL)
        return -1;
    return this->path(source, destination).size()-1;
}

template <class T>
std::list<NodoGeneral<T>*> ArbolGeneral<T>::path(NodoGeneral<T> *source, NodoGeneral<T> *destination){
    std::list<NodoGeneral<T>*> path;
    if (source==NULL || destination==NULL)
        return path;
    if (source->getChildren().empty())
        return path;
    std::list<NodoGeneral<T>*> c=source->getChildren();
    typename std::list<NodoGeneral<T>*>::iterator it=c.begin();
    while (it != c.end()){
        if (this->pathExists(*it, destination)){
            path.push_back(source);
            path.push_back(*it);
            while(true){
                if (*it==destination)
                    return path;
                c=(*it)->getChildren();
                it=c.begin();
                while(!this->pathExists(*it, destination))
                    advance (it,1);
                path.push_back(*it);
            }
        }
        advance (it, 1);
    }
    return path;
}

template <class T>
NodoGeneral<T>* ArbolGeneral<T>::searchNode(T data){
    NodoGeneral<T>* nodo=NULL;
    if (this->head==NULL)
        return nodo;
    if (this->head->getData()!=data && this->head->getChildren().empty())
        return nodo;
    if (this->dataExists(this->head, data)){
        if (this->head->getData()==data)
            return this->head;
        std::list<NodoGeneral<T>*> c=this->head->getChildren();
        typename std::list<NodoGeneral<T>*>::iterator it=c.begin();
        while (true){
            while (!this->dataExists(*it, data))
                advance (it, 1);
            if ((*it)->getData()==data)
                return *it;
            else{
                c=(*it)->getChildren();
                it=c.begin();
            }
        }
    }
    return nodo;
}

template <class T>
bool ArbolGeneral<T>::dataExists(NodoGeneral<T>* node, T data){
    if (node->getData()==data)
        return true;
    else if (node->getChildren().empty())
        return false;
    else{
        std::list<NodoGeneral<T>*> c=node->getChildren();
        typename std::list<NodoGeneral<T>*>::iterator it=c.begin();
        while (it != c.end()){
            if (this->dataExists(*it, data))
                return true;
            advance (it, 1);
        }
        return false;
    }
}

template <class T>
bool ArbolGeneral<T>::pathExists (NodoGeneral<T> *actual, NodoGeneral<T> *destination){
    if (actual==destination)
        return true;
    else if(actual->getChildren().size()){
        std::list<NodoGeneral<T>*> c=actual->getChildren();
        typename std::list<NodoGeneral<T>*>::iterator it=c.begin();
        while (it != c.end()){
            if (this->pathExists(*it, destination))
                return true;
            advance (it, 1);
        }
        return false;
    }
    else
        return false;
}

template <class T>
std::list<std::string> ArbolGeneral<T>::preOrder(NodoGeneral<T>* node){
    std::list<std::string> lista;
    std::list<NodoGeneral<T>*>lis=node->getChildren();
    lista.push_back(std::to_string(node->getData())+" ");
    if (!lis.empty()){
        std::list<std::string> c;
        for(typename std::list<NodoGeneral<T>*>::iterator it=lis.begin(); it!=lis.end(); ++it){
            c=this->preOrder(*it);
            for (std::list<std::string>::iterator it2=c.begin(); it2!=c.end(); it2++)
                lista.push_back(*it2);
        }
    }
    return lista;
}

template <class T>
std::list<std::string> ArbolGeneral<T>::preOrder(){
    if (this->head)
        return this->preOrder(this->head);
    std::list<std::string> lista;
    return lista;
}

template <class T>
std::list<std::string> ArbolGeneral<T>::postOrder(NodoGeneral<T>* node){
    std::list<std::string> lista;
    std::list<NodoGeneral<T>*>lis=node->getChildren();
    if (!lis.empty()){
        std::list<std::string> c;
        for(typename std::list<NodoGeneral<T>*>::iterator it=lis.begin(); it!=lis.end(); ++it){
            c=this->postOrder(*it);
            for (std::list<std::string>::iterator it2=c.begin(); it2!=c.end(); it2++){
                lista.push_back(*it2);
            }
        }
    }
    lista.push_back(std::to_string(node->getData())+" ");
    return lista;
}

template <class T>
NodoGeneral<T> * ArbolGeneral<T>::insertNode(T father, T son){
    NodoGeneral<T>* f=this->searchNode(father);
    if ((!f)||(this->searchNode(son)))
        return NULL;
    return f->addChild(son);
}

template <class T>
std::list<std::string> ArbolGeneral<T>::postOrder(){
    if (this->head)
        return this->postOrder(this->head);
    std::list<std::string> lista;
    return lista;
}
