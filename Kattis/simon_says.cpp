#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int n,N;
	cin>>n;

	N = n;
	string line;
	getline(cin,line);
	string words = "Simon says";
	while(n--){
		getline(cin,line);
		bool yes = true;
		for (int i = 0; i < words.length(); ++i)
		{
			if(line[i]!=words[i]){
				yes = false;
				break;
			}
		}
		if(yes){
			for (int j = words.length(); j < line.length(); ++j)
			{
				cout<<line[j];
			}
			cout<<endl;
		}
	}
	
	return 0;
}