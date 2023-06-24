#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream input("./input.txt");
    string line;
    int najwieksza = 0;
    int aktualna = 0;
    while(getline(input,line)){
        if (line.length() ==0){
            if (aktualna>najwieksza){
                najwieksza = aktualna;
            }
            aktualna=0;
        }
        aktualna+=

    }
    cout << najwieksza << endl;
    return 0;
}