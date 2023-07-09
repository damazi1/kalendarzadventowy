#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int szukaj(ifstream& fin){
    string src;
    fin>>src;
    size_t n=src.size();
    for(int i=0;i<n-3;i++){
        string temp=src.substr(i,4);
        if(temp[0]==temp[1]||temp[0]==temp[2]||temp[0]==temp[3]||temp[1]==temp[2]||temp[1]==temp[3]||temp[2]==temp[3]){
            cout<<temp<<endl;
            continue;
        }
        else{
            cout<<temp<<endl;
            return i+4;
        }
       }
    return 0;
}

int main(){

    ifstream fin;
    fin.open("in.txt");

    cout<<szukaj(fin)<<endl;

    fin.close();

    return 0;
}