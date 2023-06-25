#include <iostream>
#include <string>
#include <stack>
#include <fstream>

using namespace std;

struct SStos{
    int wysokosc;
    string *dane;

    SStos(){
        wysokosc=0;
        dane=nullptr;
    }
    ~SStos(){
        wysokosc=0;
        if(dane){
            delete [] dane;
            dane=nullptr;
        }
    }

    string pop();
    bool push(string);
    bool top();
    bool top1();
    bool iniciuj(ifstream&);
    void sortuj(ifstream&,SStos*);
    void sortuj2(ifstream&,SStos*);
};

string SStos::pop(){
    string src=dane[wysokosc-1]; //dane usuniętej pozycji
    string *temp=new string [wysokosc]; //tymczasowa tablica danych
    for(int i=0;i<wysokosc;i++){
        temp[i]=dane[i];
    }
    if (dane){
        delete [] dane;
        dane=nullptr;
    }
    wysokosc--;
    dane=new string [wysokosc];
    for(int i=0;i<wysokosc;i++){
        dane[i]=temp[i];
    }
    if(temp){
        delete [] temp;
        temp=nullptr;
    }
    return src;
}

bool SStos::push(string src){
    string *temp=new string [wysokosc+1];
    for(int i=0;i<wysokosc;i++){
        temp[i]=dane[i];
    }
    temp[wysokosc]=src;
    wysokosc++;
    if(dane){
        delete [] dane;
        dane=nullptr;
    }
    dane=new string [wysokosc];
    for(int i=0;i<wysokosc;i++){
        dane[i]=temp[i];
    }
    if(temp){
        delete [] temp;
        temp=nullptr;
    }
    return true;
}
bool SStos::top(){
    for(int i=0;i<wysokosc;i++){
        cout<<dane[i]<<'\t';
    }
    cout<<endl;
    return true;
}

bool SStos::top1(){
    cout<<dane[wysokosc-1]<<endl;
    return true;
}

bool SStos::iniciuj(ifstream& fin){
    string src;
    int i=0;
    while(getline(fin,src)){
        if(src.length()==0){
            return true;
        }
        else{
            if(!push(src)){
                cerr<<"blad podczas iniciowania tablicy"<<endl;
                return false;
            }
        }
    }
    return false;
}

void SStos::sortuj(ifstream& fin,SStos *stos){
    string ile,skad,dokad,temp;
    int i,s,d;
    while(fin>>temp>>ile>>temp>>skad>>temp>>dokad){
        i=stoi(ile);
        s=stoi(skad)-1;
        d=stoi(dokad)-1;
        for(int j=0;j<i;j++){
            temp=stos[s].pop();
            stos[d].push(temp);
        }
    }
}

void SStos::sortuj2(ifstream& fin,SStos *stos){
    string ile,skad,dokad,temp;
    string*temp1;
    int i,s,d;
    while(fin>>temp>>ile>>temp>>skad>>temp>>dokad){
        i=stoi(ile);
        s=stoi(skad)-1;
        d=stoi(dokad)-1;
        temp1=new string [i];
        for(int j=0;j<i;j++){
            temp1[j]=stos[s].pop();
        }
        for(int j=i-1;0<=j;j--){
            stos[d].push(temp1[j]);
        }
        if(temp1){
            delete []temp1;
            temp1=nullptr;
        }
    }
}

int main(){

    SStos* stos=new SStos [9];
    ifstream fin("in.txt");
    for(int i=0;i<9;i++){
        if(!stos[i].iniciuj(fin)){
            cerr<<"blad podczas iniciowania w main"<<endl;
            fin.clear();
            fin.close();
            return 1;
        }
        stos[i].top();
    }

    ifstream fin1("input.in");

    stos->sortuj2(fin1,stos);

    for(int i=0;i<9;i++){
        stos[i].top1();
    }

    fin1.close();
    fin.close();
    return 0;
}