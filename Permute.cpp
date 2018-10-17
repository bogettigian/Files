#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

bool pertenece(int x, vector<int> xs){
	for(int i = 0; i < xs.size(); i++){
		if(xs[i] == x){
			return true;
		}
	}
	return false;
}

void permutar(string pass, vector<string> data, vector<int> vistos){
	for(int i = 0; i < data.size(); i++){
		if(!pertenece(i, vistos)){
			string newpass = pass + data[i];
			vector<int> newvistos = vistos;
			newvistos.push_back(i);
			if(newpass.size() > 5 and newpass.size() < 13){
				cout << newpass << endl;
			}
			if(newpass.size() < 13){
				permutar(newpass, data, newvistos);
			}
		}
	}
}

int main(){

	ifstream archivo;
	archivo.open("Data.txt");
	vector<string> informacion;
	vector<int> vistos;
	while(!archivo.eof()){
		string data;
		archivo >> data;
		if(data != ""){
			informacion.push_back(data);
		}
	}

	archivo.close();
	permutar("", informacion, vistos);

	return 0;
}
