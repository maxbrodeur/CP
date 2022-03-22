#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>


using namespace std;

int main(){
	string line;
	getline(cin, line);
	int t = stoi(line);

	for (int i = 0; i < t; ++i)
	{
		getline(cin, line);
		int n = stoi(line);
		unordered_set<string> book;
		string numbers[n];
		bool found = false;
		for (int j = 0; j < n; ++j)
		{
			getline(cin, line);
			string prefix = "";
			for(int k = 0; k<line.size()-1; ++k){
				char c = line[k];
				prefix += string(1,c);
				book.insert(prefix);
			}
			numbers[j]=line;
		}

		for (int j = 0; j < n; ++j)
		{
			if(!book.insert(numbers[j]).second){
				cout<<"NO"<<endl; 
				found = true; 
				break;}
		}

		if(!found)cout<<"YES"<<endl;
		
	}
}