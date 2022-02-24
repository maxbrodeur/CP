#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main() {
	string line;
	getline(cin,line);
	int n = stoi(line);

	string og;
	getline(cin, og);

	string del;
	getline(cin, del);

	int len = og.length();

	bool good = true;
	for (int i = 0; i < len; ++i)
	{
		char c1 = og.at(i);
		char c2 = del.at(i);

		if(n%2==0){
			if(c1 != c2)good = false;
		}else{
			if(c1 == c2)good = false;
		}
	}

	if(good){
		cout<<"Deletion succeeded"<<endl;
	}else{
		cout<<"Deletion failed"<<endl;
	}



}