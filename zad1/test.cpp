#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

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
            suma += stoi(s);
        }
    }
    return t;
}

int main()
{
    ifstream in("in.txt");
    int *t = ile(in, 250);
    sort(t,t+250);
    cout<<t[247]<<'\n'<<t[248]<<'\n'<<t[249]<<endl;
    if (t)
    {
        delete[] t;
        t = nullptr;
    }

    in.close();
    return 0;
}
