#include <iostream>
#include <fstream>

using namespace std;

void licz(string str, string *liczby)
{
    string s1, s2;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ',')
        {
            s1 = str.substr(0, i);
            s2 = str.substr(i + 1, 5);
            break;
        }
    }
    n = s1.length();
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '-')
        {
            liczby[0] = s1.substr(0, i);
            liczby[1] = s1.substr(i + 1, 5);
            break;
        }
    }
    n = s2.length();
    for (int i = 0; i < n; i++)
    {
        if (s2[i] == '-')
        {
            liczby[2] = s2.substr(0, i);
            liczby[3] = s2.substr(i + 1, 5);
            break;
        }
    }
}

int contain(ifstream &fin)
{
    int wynik = 0;
    string str;
    string liczby[4];
    while (fin >> str)
    {
        licz(str, liczby);
        if(stoi(liczby[0])>=stoi(liczby[2])&&stoi(liczby[1])<=stoi(liczby[3])||stoi(liczby[0])<=stoi(liczby[2])&&stoi(liczby[3])<=stoi(liczby[1]))
                wynik++;
            }
    return wynik;
}

int main()
{
    ifstream fin("input.in");
    cout<<contain(fin)<<endl;
    fin.close();
    return 0;
}