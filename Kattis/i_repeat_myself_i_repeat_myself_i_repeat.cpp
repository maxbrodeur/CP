#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// LPS = Longest proper prefix which is also a suffix
void make_LPS(string pat, int* LPS){

	size_t M = pat.size();
	LPS[0]=0;
	size_t i = 1;
	size_t start = 0;
	while(i<M){
		if(pat[i]==pat[start]){ 
			start++;
			LPS[i]=start;
			i++;
		}else if(start!=0){ // iterate back to beggining (no i++ !!)
			start = LPS[start-1];
		}else{
			LPS[i]=0;
			i++;
		}
	}
}

int KMP_first(string pat, string text, int* LPS){
	int j = 0;
	for (int i = 0; i < text.size(); ++i)
	{

		while(j != 0 && pat[j]!=text[i]) {j=LPS[j-1];}
		if(pat[j]==text[i])j++;
		if(j==pat.size()){
			return i+1-pat.size();
			j=LPS[j-1];
		}
	}
	return -1;
}

int main(){
	string line;
	getline(cin, line);
	int N = stoi(line);
	for (int i = 0; i < N; ++i)
	{
		getline(cin,line);
		
		int LPS[line.size()];
		make_LPS(line, LPS);
		string suffix = "";
		for (int j = 0; j < line.size(); ++j)
		{
			suffix += string(1,line[j]);
			string s;
			int n = ceil(line.size()/(double)suffix.size());
			for (int k = 0; k < n; ++k){s += suffix;}
			if(KMP_first(line,s, LPS)!=-1){
				cout<<suffix.size()<<endl;
				break;
			}

		}
		
	}
}









