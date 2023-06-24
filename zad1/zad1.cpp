#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int licz(ifstream &fin)
{
	int suma = 0, max = suma;
	string lic;
	while(getline(fin,lic)){
		if(lic.length()==0){
				if(suma>max){
					max=suma;
				}
				suma=0;
		}
		else{
			suma+=stoi(lic);
		}
	}
	return max;
}

int main()
{
	ifstream fin;
	fin.open("input.txt");

	cout<<licz(fin)<<endl;

	fin.close();
	return 0;
}