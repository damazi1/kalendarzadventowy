#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int *ile(ifstream &in, int n)
{
    int *t = new int[n];
    int suma = 0, i = 0;
    string s;
    while (getline(in, s))
    {
        if (s.length() == 0)
        {
            cout << s << endl;
            t[i] = suma;
            i++;
            suma = 0;
        }
        else
        {
            cout << s << endl;
            suma += stoi(s);
            cout << suma << endl;
        }
    }
    return t;
}

int main()
{
    ifstream in("input.txt");
    int *t = ile(in, 300);
    if (t)
    {
        delete[] t;
        t = nullptr;
    }

    in.close();
    return 0;
}
