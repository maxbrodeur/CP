#include <iostream>

using namespace std;

int main(){

	string line;
	getline(cin,line);
	int n = stoi(line);

	for (int i = 0; i < n; ++i)
	{
		getline(cin,line);
		cout<<line.size()<<endl;
	}
}