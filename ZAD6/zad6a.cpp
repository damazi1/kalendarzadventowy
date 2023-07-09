#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int szukaj(ifstream &fin)
{
    string src;
    fin >> src;
    bool prawda = false;
    size_t n = src.size();
    for (int i = 14; i < n - 3; i++)
    {
        string temp = src.substr(i, 14);
        prawda = false;
        for (int j = 0; j < 14; j++)
        {
            for (int k = 0; k < 14; k++)
            {
                if (j != k)
                {
                    if (temp[j] == temp[k])
                    {
                        prawda = true;
                        break;
                    }
                }
                if (prawda)
                    break;
            }
            if (prawda)
                break;
        }
        if (!prawda)
            return i + 14;
    }
    return 0;
}

int main()
{

    ifstream fin;
    fin.open("in.txt");

    cout << szukaj(fin) << endl;

    fin.close();

    return 0;
}