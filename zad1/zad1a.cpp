#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int licz(ifstream &fin)
{
	int suma = 0;
    int max[3];
	string lic;
	while(getline(fin,lic)){
		if(lic.empty()){
				if(suma>max[0]){
					max[2]=max[1];
                    max[1]=max[0];
                    max[0]=suma;
				}
                else if(suma>max[1]){
					max[2]=max[1];
                    max[1]=suma;
				}
                else if(suma>max[2]){
					max[2]=suma;
				}
				suma=0;
                continue;
		}
		else{
			suma+=stoi(lic);
		}
	}
    suma=max[0]+max[1]+max[2];    
	return suma;
}

int main()
{
	ifstream fin;
	fin.open("input.txt");

	cout<<licz(fin)<<endl;

	fin.close();
	return 0;
}