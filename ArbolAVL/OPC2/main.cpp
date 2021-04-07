#include "Comparision.h"
#include <iostream>
using namespace std;
int main(int argc, char** argv){
    typedef string T;
    Comparision <T> comp;
    if (argc>1){
        pair<double, double> times=comp.insertFileDataToBoth(argv[1]);
        cout<<"RB time: "<<times.first<<" seconds"<<endl;
        cout<<"AVL time: "<<times.second<<" seconds"<<endl;
        cout<<"Equal elements: "<<comp.compare()<<" size: "<<comp.size();
    }
    return 0;
}
