#include "ArbolAVL.h"
 
template <class T>
ArbolAVL<T>::ArbolAVL(NodoAVL<T> *&head){
    this->head=head;
}

template <class T>
ArbolAVL<T>::ArbolAVL(T data){
    this->head=new NodoAVL<T>(data);
}

template <class T>
ArbolAVL<T>::~ArbolAVL(){
    if (this->head){
        delete this->head;
        this->head=NULL;
    }
}
        
template <class T>
NodoAVL<T>* ArbolAVL<T>::getHead(){
    return this->head;
}

template <class T>
void ArbolAVL<T>::setHead(NodoAVL<T>*& head){
    this->head=head;
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::insertNode(NodoAVL<T>*& node){
    if (this->insertNode(this->head, node)){
        this->balance(node);
        return node;
    }
    else
        return NULL;
}

template <class T>
bool ArbolAVL<T>::insertNode(NodoAVL<T>* toCompare, NodoAVL<T>*& node){
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
NodoAVL<T>* ArbolAVL<T>::insertNode(T node){
    NodoAVL<T>* c=new NodoAVL<T>(node);
    if (this->insertNode(this->head, c)){
        this->balance(c);
        return c;
    }
    else
        return NULL;
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::searchNodeFather(NodoAVL<T>* searching){
    if (!this->head)
        return NULL;
    if (this->head==searching)
        return this->head;
    return this->searchNodeR(this->getHead(), searching);
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::searchNodeR(NodoAVL<T>* node, NodoAVL<T>*& searching){
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
NodoAVL<T>* ArbolAVL<T>::searchNodeFather(T searching){
    NodoAVL<T>* node=this->head;
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
bool ArbolAVL<T>::removeNode(NodoAVL<T>*& node){
    NodoAVL<T>*padre=this->searchNodeFather(node);
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
    this->balance(padre);
    return true;
}

template <class T>
bool ArbolAVL<T>::removeNode(T node){
    NodoAVL<T>*padre=this->searchNodeFather(node);
    if (!padre)
        return 0;
    NodoAVL<T>*nodo;
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
    this->balance(padre);
    return true;
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::removeNodeMinor(NodoAVL<T>*& node){
    return node->removeSubMinor();
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::removeNodeGreater(NodoAVL<T>*& node){
    return node->removeSubGreater();
}

template <class T>
std::string ArbolAVL<T>::printTree(){
    if (this->head)
        return "Tree\n"+this->head->toString()+"\n";
    else
        return " ";
}

template <class T>
std::string ArbolAVL<T>::inOrder(){
    return this->head->inOrder();        
}

template <class T>
std::string ArbolAVL<T>::preOrder(){
    return this->head->preOrder();        
}

template <class T>
std::string ArbolAVL<T>::postOrder(){
    return this->head->postOrder();        
}

template <class T>
int ArbolAVL<T>::height(){
    if (!this->head)
        return -1;
    return this->head->height();
}

template <class T>
std::string ArbolAVL<T>::levelOrder(){
    std::list<NodoAVL<T>*> nextLevel;
    std::string levels="";
    nextLevel.push_back(this->getHead());
    for (typename std::list<NodoAVL<T>*>::iterator it=nextLevel.begin(); it!=nextLevel.end(); advance(it, 1)){
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
bool ArbolAVL<T>::balanced(){
    if (!this->head)
        return 1;
    return (this->nodeBalanced(this->head));
}

template <class T>
bool ArbolAVL<T>::nodeBalanced(NodoAVL<T>* node){
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
NodoAVL<T>* ArbolAVL<T>::composedRotation1 (NodoAVL<T>*& node, bool update){
    if (!node)
        return NULL;
    if (!this->searchNodeFather(node))
        return NULL;
    NodoAVL<T>* n=node->getLeft();
    NodoAVL<T>* nodoH=this->leftRotation(n);
    if (!nodoH)
        return NULL;
    node->setLeft(nodoH);
    NodoAVL<T>* nodoP=this->rightRotation(node);
    if (update){
        if (this->head==node)
            this->setHead(nodoP);
        else{
            NodoAVL<T>* toUpdate=this->searchNodeFather(node);
            if (toUpdate->getRight()==node)
                toUpdate->setRight(nodoP);
            else
                toUpdate->setLeft(nodoP);
        }
        
    }
    return nodoP;
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::composedRotation2 (NodoAVL<T>*& node, bool update){
    if (!node)
        return NULL;
    NodoAVL<T>* n=node->getRight();
    NodoAVL<T>* nodoH=this->rightRotation(n);
    if (!nodoH)
        return NULL;
    node->setRight(nodoH);
    NodoAVL<T>* nodoP=this->leftRotation(node);
    if (update){
        if (this->head==node)
            this->setHead(nodoP);
        else{
            NodoAVL<T>* toUpdate=this->searchNodeFather(node);
            if (toUpdate->getRight()==node)
                toUpdate->setRight(nodoP);
            else
                toUpdate->setLeft(nodoP);
        }
        
    }
    return nodoP;
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::leftRotation (NodoAVL<T>*& node, bool update){
    if (!node)
        return NULL;
    NodoAVL<T>* nodoP=node->getRight();
    if (!nodoP)
        return NULL;
    NodoAVL<T>* nodoR=nodoP->getLeft();
    NodoAVL<T>* nodoH=nodoP->getRight();
    node->setRight(nodoH);
    nodoP->setLeft(node);
    nodoP->setRight(nodoR);
    if (update){
        if (this->head==node)
            this->setHead(nodoP);
        else{
            NodoAVL<T>* toUpdate=this->searchNodeFather(node);
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
NodoAVL<T>* ArbolAVL<T>::rightRotation (NodoAVL<T>*& node, bool update){
    if (!node)
        return NULL;
    NodoAVL<T>* nodoP=node->getLeft();
    if (!nodoP)
        return NULL;
    NodoAVL<T>* nodoR=nodoP->getLeft();
    NodoAVL<T>* nodoH=nodoP->getRight();
    node->setLeft(nodoH);
    nodoP->setRight(node);
    nodoP->setLeft(nodoR);
    if (update){
        if (this->head==node)
            this->setHead(nodoP);
        else{
            NodoAVL<T>* toUpdate=this->searchNodeFather(node);
            if (toUpdate->getRight()==node)
                toUpdate->setRight(nodoP);
            else
                toUpdate->setLeft(nodoP);
        }
        
    }
    return nodoP;
}

template <class T> 
bool ArbolAVL<T>::balance(NodoAVL<T>*& node){
    if (this->balanced())
        return 1;
    NodoAVL<T>* ft=this->searchNodeFather(node);
    NodoAVL<T>* lastFT=NULL;
    while (ft!=lastFT){
        if (ft->getLeft()||ft->getRight()){
            if (ft->getLeft()&&!ft->getRight()){
                if (!this->nodeBalanced(ft)){
                    //NodoAVL<T>* n=
                    this->rightRotation(ft, true);
                    ft=this->searchNodeFather(ft);
                }
            }
            
            else if (!ft->getLeft()&&ft->getRight()){
                if (!this->nodeBalanced(ft)){
                    //NodoAVL<T>* n=
                    this->leftRotation(ft, true);
                    ft=this->searchNodeFather(ft);
                }
            }
                    
            else if (ft->getLeft()&&ft->getRight()){
                NodoAVL<T>* n;
                if (!this->nodeBalanced(ft)){
                    if (!this->nodeBalanced(ft->getLeft())){
                        n=ft->getLeft();
                        if (!n->getLeft())
                            this->rightRotation(n);
                        else if (!n->getRight())
                            this->composedRotation1(n);
                        else if (n->getLeft()->height()-n->getRight()->height()>0)
                            this->rightRotation(n);
                        else
                            this->composedRotation1(n);
                    }
                    else if (!this->nodeBalanced(ft->getRight())){
                        n=ft->getRight();
                        if (!n->getLeft())
                            this->leftRotation(n);
                        else if (!n->getRight())
                            this->composedRotation2(n);
                        else if (n->getLeft()->height()-n->getRight()->height()<0)
                            this->leftRotation(n);
                        else
                            this->composedRotation2(n);
                    }
                    ft=this->searchNodeFather(ft);
                }
            }
            
        }
        lastFT=ft;
        ft=this->searchNodeFather(ft);
    }
    if (!ft)
        return 0;
    return 1;
}
