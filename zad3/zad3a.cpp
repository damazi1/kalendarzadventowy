#include <iostream>
#include <fstream>

using namespace std;

int licz(string str1, string str2, string str3)
{
    int wynik=0;
    bool prawda = false;
    for (int i=0;i<str1.length();i++){     
        for(int j=0;j<str2.length();j++){
            for(int k=0;k<str3.length();k++){
                if (str1[i] == str2[j] && str1[i] == str3[k])
                        {
                            char t = str1[i];
                            if (isupper(t))
                            {
                                int k = int(t);
                                k -= 38;
                                cout << k << '\t' << t << endl;
                                wynik += k;
                                prawda = true;
                                break;
                            }
                            else
                            {
                                int k = int(t);
                                k -= 96;
                                cout << k << '\t' << t << endl;
                                wynik += k;
                                prawda = true;
                                break;
                            }
                        }
                        if (prawda == true)
                            break;
                    }
                    if (prawda == true)
                        break;
                }
                if (prawda == true)
                    break;
            }
        return wynik;
        }
int Ruck(ifstream &fin)
{
    int wynik = 0;
    string str, str1, str2;
    while (fin >> str >> str1 >> str2)
    {
        wynik+=licz(str,str1,str2);   
    }
    return wynik;
}
int main()
{
    ifstream fin("input.in");
    cout << Ruck(fin) << endl;
    fin.close();
    return 0;
}