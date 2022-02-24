#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
	string word;
	unordered_map<string,int> umap;
	while(cin>>word){
		string temp = word;
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if (umap.find(temp) == umap.end()){
			umap[temp]=0;
			cout<<" "<<word;
		}else{
			cout<<" .";
		}	
	}
	return 0;
}