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
	string line;
	unordered_map<char,string> umap;
	umap['a']="@";
	umap['b']="8";
	umap['c']="(";
	umap['d']="|)";
	umap['e']="3";
	umap['f']="#";
	umap['g']="6";
	umap['h']="[-]";
	umap['i']="|";
	umap['j']="_|";
	umap['k']="|<";
	umap['l']="1";
	umap['m']="[]\\/[]";
	umap['n']="[]\\[]";
	umap['o']="0";
	umap['p']="|D";
	umap['q']="(,)";
	umap['r']="|Z";
	umap['s']="$";
	umap['t']="']['";
	umap['u']="|_|";
	umap['v']="\\/";
	umap['w']="\\/\\/";
	umap['x']="}{";
	umap['y']="`/";
	umap['z']="2";
	while(getline(cin,line)){
		for(char c : line){
			c = tolower(c);
			if (umap.find(c) == umap.end()){
				cout<<c;
			}else{
				cout<<umap[c];
			}
		}

	}
	return 0;
}


