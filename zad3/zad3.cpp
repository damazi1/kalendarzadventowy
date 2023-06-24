#include <iostream>
#include <fstream>

using namespace std;

int Ruck(ifstream& fin){
    int wynik=0;
    string str,str1,str2;
    while(fin>>str){
        int n=str.length();
        int m=n/2;
        str1=str.substr(0,m);
        str2=str.substr(m,m);
        for(int i=0;i<m;i++){
        bool prawda=false;
            for(int j=0;j<m;j++){
                if(str1[i]==str2[j]){
                    char t=str1[i];
                    if(isupper(t)){
                        int k=int(t);
                        k-=38;
                        cout<<k<<'\t'<<t<<endl;
                        wynik+=k;
                        prawda=true;
                        break;
                    }
                    else{
                        int k=int(t);
                        k-=96;
                        cout<<k<<'\t'<<t<<endl;
                        wynik+=k;
                        prawda=true;
                        break;
                    }
                }
                if(prawda==true)break; 
            }
            if(prawda==true)break; 
        }
    }
    return wynik;
}

int main(){
    ifstream fin("input.in");

    cout<<Ruck(fin)<<endl;

    fin.close();
    return 0;
}