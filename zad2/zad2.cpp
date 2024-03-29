#include <iostream>
#include <fstream>

using namespace std;

int pkn(ifstream &fin)
{
    int wynik = 0;
    string symbol1, symbol2;
    while(fin>>symbol1>>symbol2){
        if (symbol1 == "A")
        {
            if (symbol2 == "X")
            {
                wynik+=1+3;
            }
            else if (symbol2 == "Y")
            {
                wynik+=2+6;
            }
            else if (symbol2 == "Z")
            {
                wynik+=3+0;
            }
        }
        else if (symbol1 == "B")
        {
            if (symbol2 == "X")
            {
                wynik+=1+0;
            }
            else if (symbol2 == "Y")
            {
                wynik+=2+3;
            }
            else if (symbol2 == "Z")
            {
                wynik+=3+6;
            }
        }
        else if (symbol1 == "C")
        {
            if (symbol2 == "X")
            {
                wynik+=1+6;
            }
            else if (symbol2 == "Y")
            {
                wynik+=2+0;
            }
            else if (symbol2 == "Z")
            {
                wynik+=3+3;
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