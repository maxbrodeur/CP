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
	int n,N;
	cin>>n;
	N = n;
	int g;
	int count = 1;
	while(n--){
		cin>>g;
		unordered_map<int,int> umap;
		while(g--){
			int c;
			cin>>c;
			if (umap.find(c) == umap.end()){
				umap[c]=1;
			}else{
				umap.erase(c);
			}
		}
		cout<<"Case #"<<count<<":";
		for(auto x : umap){
			cout<<" "<<x.first;
		}
		cout<<endl;
		count++;
	}
	
	return 0;
}