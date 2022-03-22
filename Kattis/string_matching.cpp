#include <iostream>
#include <string>
#include <vector>


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

void print_int_arr(int* arr, int size){
	cout<<"[";
	for (int i = 0; i < size; ++i)
	{
		cout<<" ";
		cout<<arr[i];
	}
	cout<<" ]"<<endl;
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

vector<int> KMP_all(string pat, string text, int* LPS){
	int j = 0;
	vector<int> ans;
	for (int i = 0; i < text.size(); ++i)
	{
		while(j != 0 && pat[j]!=text[i]) {j=LPS[j-1];}
		if(pat[j]==text[i])j++;
		if(j==pat.size()){
			ans.push_back(i+1-pat.size());
			j=LPS[j-1];
		}
	}
	return ans;
}

int main(){
	string line;
	while(getline(cin, line)){
		string pat = line;
		getline(cin, line);
		int* LPS = new int[pat.size()];

		make_LPS(pat, LPS);
		vector<int> ans = KMP_all(pat, line, LPS);

		for (int i = 0; i < ans.size(); ++i)
		{
			cout<<ans[i];
			if(i!=ans.size()-1)cout<<" ";
		}
		cout<<endl;


	}
	
	

}