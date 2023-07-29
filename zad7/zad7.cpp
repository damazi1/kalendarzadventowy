#include <iostream>
#include <fstream>

using namespace std;

struct Sdane{
    string nazwa_folderu;
    int waga_folderu;

    Sdane(){
        nazwa_folderu="";
        waga_folderu=NULL;
    }

    ~Sdane(){
        nazwa_folderu="";
        waga_folderu=NULL;
    }

};

struct Sfolder{

    Sdane *dane;



};




int main(){

    return 0;
}