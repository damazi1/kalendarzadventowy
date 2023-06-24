#include <iostream>
#include <fstream>

using namespace std;

int pkn(ifstream &fin)
{
    int wynik = 0;
    string src, symbol1, symbol2;
    while(fin>>symbol1>>symbol2){
        if(symbol2=="X"){
            if(symbol1=="A"){   //KAMIEŃ
                wynik+=3;
            }
            if(symbol1=="B"){   //PAPIER
                wynik+=1;
            }
            if(symbol1=="C"){   //NOŻYCZKI
                wynik+=2;
            }
        }
        if(symbol2=="Y"){
            if(symbol1=="A"){   //KAMIEŃ
                wynik+=1+3;
            }
            if(symbol1=="B"){   //PAPIER
                wynik+=2+3;
            }
            if(symbol1=="C"){   //NOŻYCZKI
                wynik+=3+3;
            }
        }
        if(symbol2=="Z"){
            if(symbol1=="A"){   //KAMIEŃ
                wynik+=2+6;
            }
            if(symbol1=="B"){   //PAPIER
                wynik+=3+6;
            }
            if(symbol1=="C"){   //NOŻYCZKI
                wynik+=1+6;
            }
        }

    }
    return wynik;
}

int main()
{
    ifstream fin("input.in");

    cout<<pkn(fin)<<endl;

    fin.close();
    return 0;
}