#include "ArbolBinarioOrdenado.h"
 
template <class T>
ArbolBinarioOrdenado<T>::ArbolBinarioOrdenado(NodoBinarioOrdenado<T> *&head){
    this->head=head;
}

template <class T>
ArbolBinarioOrdenado<T>::ArbolBinarioOrdenado(T data){
    this->head=new NodoBinarioOrdenado<T>(data);
}

template <class T>
ArbolBinarioOrdenado<T>::~ArbolBinarioOrdenado(){
    if (this->head){
        delete this->head;
        this->head=NULL;
    }
}
        
template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::getHead(){
    return this->head;
}

template <class T>
void ArbolBinarioOrdenado<T>::setHead(NodoBinarioOrdenado<T>*& head){
    this->head=head;
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::insertNode(NodoBinarioOrdenado<T>*& node){
    if (this->insertNode(this->head, node)){
        return node;
    }
    else
        return NULL;
}

template <class T>
bool ArbolBinarioOrdenado<T>::insertNode(NodoBinarioOrdenado<T>* toCompare, NodoBinarioOrdenado<T>*& node){
    if (toCompare->getData()==node->getData())
        return false;
    else if (toCompare->getData()>node->getData()){
        if (!toCompare->getLeft()){
            toCompare->setLeft(node);
            return true;
        } else
            return this->insertNode(toCompare->getLeft(), node);
    }
    else if (toCompare->getData()<node->getData()){
        if (!toCompare->getRight()){
            toCompare->setRight(node);
            return true;
        } else
            return this->insertNode(toCompare->getRight(), node);
    }
    return true;
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::insertNode(T node){
    NodoBinarioOrdenado<T>* c=new NodoBinarioOrdenado<T>(node);
    if (this->insertNode(this->head, c)){
        return c;
    }
    else
        return NULL;
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::searchNodeFather(NodoBinarioOrdenado<T>* searching){
    if (!this->head)
        return NULL;
    if (this->head==searching)
        return this->head;
    return this->searchNodeR(this->getHead(), searching);
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::searchNodeR(NodoBinarioOrdenado<T>* node, NodoBinarioOrdenado<T>*& searching){
    if (!node)
        return NULL;
    if (node->getLeft()==searching||node->getRight()==searching)
        return node;
    if (!node->getLeft()&&!node->getRight())
        return NULL;
    if (!node->getLeft()&&node->getRight()!=searching)
        return this->searchNodeR(node->getRight(), searching);
    if (node->getLeft()!=searching&&!node->getRight())
        return this->searchNodeR(node->getLeft(), searching);
    else{
        while (this->searchNodeR(node->getLeft(), searching))
            node=this->searchNodeR(node->getLeft(), searching);
        if (node->getRight())
            while (this->searchNodeR(node->getRight(), searching))
                node=this->searchNodeR(node->getRight(), searching); 
        if (node==this->head&&(!(this->head->getRight()==searching||this->head->getLeft()==searching)))
            node=NULL;
    }
    return node;
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::searchNodeFather(T searching){
    NodoBinarioOrdenado<T>* node=this->head;
    if (!node)
        return node;
    if (node->getData()==searching)
        return node;
    bool enc=false;
    while (!enc){
        if (!(node->getLeft()||node->getRight()))
            return NULL;
        if ((node->getData()<searching&&!node->getRight()))
            return NULL;
        if ((node->getData()>searching&&!node->getLeft()))
            return NULL;
        if ((node->getData()<searching&&node->getRight())){
            if (node->getRight()->getData()==searching)
                enc=true;
            else
                node=node->getRight();
        }
        else if ((node->getData()>searching&&node->getLeft())){
            if (node->getLeft()->getData()==searching)
                enc=true;
            else
                node=node->getLeft();
        }
    }
    return node;
}

template <class T>
bool ArbolBinarioOrdenado<T>::removeNode(NodoBinarioOrdenado<T>*& node){
    NodoBinarioOrdenado<T>*padre=this->searchNodeFather(node);
    if (!(node->getRight()||node->getLeft())){
        if (padre->getRight()==node){
            delete node;
            node=NULL;
            padre->setRight(node);
        }
        else {
            delete node;
            node=NULL;
            padre->setLeft(node);
        }     
    }
    else if ((!node->getRight())&&(node->getLeft()))
        this->removeNodeGreater(node);
    else
        this->removeNodeMinor(node);
    return true;
}

template <class T>
bool ArbolBinarioOrdenado<T>::removeNode(T node){
    NodoBinarioOrdenado<T>*padre=this->searchNodeFather(node);
    if (!padre)
        return 0;
    NodoBinarioOrdenado<T>*nodo;
    if (padre->getLeft()){
        if (padre->getLeft()->getData()==node)
            nodo=padre->getLeft();
    }
    else
        nodo=padre->getRight();
    if (!(nodo->getRight()||nodo->getLeft())){
        if (padre->getRight()==nodo){
            delete nodo;
            nodo=NULL;
            padre->setRight(nodo);
        }
        else {
            delete nodo;
            nodo=NULL;
            padre->setLeft(nodo);
        }    
    }
    else if ((!nodo->getRight())&&(nodo->getLeft()))
        this->removeNodeGreater(nodo);
    else
        this->removeNodeMinor(nodo);
    return true;
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::removeNodeMinor(NodoBinarioOrdenado<T>*& node){
    return node->removeSubMinor();
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::removeNodeGreater(NodoBinarioOrdenado<T>*& node){
    return node->removeSubGreater();
}

template <class T>
std::string ArbolBinarioOrdenado<T>::printTree(){
    if (this->head)
        return "Tree\n"+this->head->toString()+"\n";
    else
        return " ";
}

template <class T>
std::string ArbolBinarioOrdenado<T>::inOrder(){
    return this->head->inOrder();        
}

template <class T>
std::string ArbolBinarioOrdenado<T>::preOrder(){
    return this->head->preOrder();        
}

template <class T>
std::string ArbolBinarioOrdenado<T>::postOrder(){
    return this->head->postOrder();        
}

template <class T>
int ArbolBinarioOrdenado<T>::height(){
    if (!this->head)
        return -1;
    return this->head->height();
}

template <class T>
std::string ArbolBinarioOrdenado<T>::levelOrder(){
    std::list<NodoBinarioOrdenado<T>*> nextLevel;
    std::string levels="";
    nextLevel.push_back(this->getHead());
    for (typename std::list<NodoBinarioOrdenado<T>*>::iterator it=nextLevel.begin(); it!=nextLevel.end(); advance(it, 1)){
        try{
            if ((*it)->getData()){
                levels+=(*it)->toString(true);
                if ((*it)->getLeft())
                    nextLevel.push_back((*it)->getLeft());
                if ((*it)->getRight())
                    nextLevel.push_back((*it)->getRight());
            }
        }
        catch (...){}
    }
    return levels;
}

template <class T>
bool ArbolBinarioOrdenado<T>::balanced(){
    if (!this->head)
        return 1;
    return (this->nodeBalanced(this->head));
}

template <class T>
bool ArbolBinarioOrdenado<T>::nodeBalanced(NodoBinarioOrdenado<T>* node){
    if (node->getLeft()||node->getRight()){
        if (!node->getLeft())
            if (1+node->getRight()->height()>1||1+node->getRight()->height()<-1)
                return 0;
        if (!node->getRight())
            if (1+node->getLeft()->height()>1||1+node->getLeft()->height()<-1)
                return 0;
        if (node->getLeft()&&node->getRight())
            if (node->getLeft()->height()-node->getRight()->height()<-1||node->getLeft()->height()-node->getRight()->height()>1)
                return 0;
        if (node->getLeft())
            if (!this->nodeBalanced(node->getLeft()))
                return 0;
        if (node->getRight())
            if (!this->nodeBalanced(node->getRight()))
                return 0;
    }
    return 1;
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::composedRotation1 (NodoBinarioOrdenado<T>*& node, bool update){
    if (!node)
        return NULL;
    if (!this->searchNodeFather(node))
        return NULL;
    NodoBinarioOrdenado<T>* n=node->getLeft();
    NodoBinarioOrdenado<T>* nodoH=this->leftRotation(n);
    if (!nodoH)
        return NULL;
    node->setLeft(nodoH);
    NodoBinarioOrdenado<T>* nodoP=this->rightRotation(node);
    if (update){
        if (this->head==node)
            this->setHead(nodoP);
        else{
            NodoBinarioOrdenado<T>* toUpdate=this->searchNodeFather(node);
            if (toUpdate->getRight()==node)
                toUpdate->setRight(nodoP);
            else
                toUpdate->setLeft(nodoP);
        }
        
    }
    return nodoP;
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::composedRotation2 (NodoBinarioOrdenado<T>*& node, bool update){
    if (!node)
        return NULL;
    NodoBinarioOrdenado<T>* n=node->getRight();
    NodoBinarioOrdenado<T>* nodoH=this->rightRotation(n);
    if (!nodoH)
        return NULL;
    node->setRight(nodoH);
    NodoBinarioOrdenado<T>* nodoP=this->leftRotation(node);
    if (update){
        if (this->head==node)
            this->setHead(nodoP);
        else{
            NodoBinarioOrdenado<T>* toUpdate=this->searchNodeFather(node);
            if (toUpdate->getRight()==node)
                toUpdate->setRight(nodoP);
            else
                toUpdate->setLeft(nodoP);
        }
        
    }
    return nodoP;
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::leftRotation (NodoBinarioOrdenado<T>*& node, bool update){
    if (!node)
        return NULL;
    NodoBinarioOrdenado<T>* nodoP=node->getRight();
    if (!nodoP)
        return NULL;
    NodoBinarioOrdenado<T>* nodoR=nodoP->getLeft();
    NodoBinarioOrdenado<T>* nodoH=nodoP->getRight();
    node->setRight(nodoH);
    nodoP->setLeft(node);
    nodoP->setRight(nodoR);
    if (update){
        if (this->head==node)
            this->setHead(nodoP);
        else{
            NodoBinarioOrdenado<T>* toUpdate=this->searchNodeFather(node);
            if (toUpdate->getRight()==node)
                toUpdate->setRight(nodoP);
            else
                toUpdate->setLeft(nodoP);
            //std::cout<<toUpdate->toString()<<'\n';
        }
    }
    return nodoP;
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::rightRotation (NodoBinarioOrdenado<T>*& node, bool update){
    if (!node)
        return NULL;
    NodoBinarioOrdenado<T>* nodoP=node->getLeft();
    if (!nodoP)
        return NULL;
    NodoBinarioOrdenado<T>* nodoR=nodoP->getLeft();
    NodoBinarioOrdenado<T>* nodoH=nodoP->getRight();
    node->setLeft(nodoH);
    nodoP->setRight(node);
    nodoP->setLeft(nodoR);
    if (update){
        if (this->head==node)
            this->setHead(nodoP);
        else{
            NodoBinarioOrdenado<T>* toUpdate=this->searchNodeFather(node);
            if (toUpdate->getRight()==node)
                toUpdate->setRight(nodoP);
            else
                toUpdate->setLeft(nodoP);
        }
        
    }
    return nodoP;
}
