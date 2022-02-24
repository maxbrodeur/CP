#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string is_pangram(string str){
		string alphabet = "abcdefghijklmnopqrstuvwxyz";
		int ln = str.length();
		for (string::iterator i = str.begin(); i != str.end(); ++i){
			char c = *i;
			c = tolower(c);
			if(c >= 'a' && c <= 'z'){
				int pos = alphabet.find(c);
				if(pos>=0)alphabet.erase(pos, 1);
			} 
		}
		return alphabet;
}

int main() {
	string line;
	getline(cin,line);
	int n = stoi(line);
	for (int i = 0; i < n; ++i)
	{
		getline(cin,line);
		string alphabet = is_pangram(line);
		if(alphabet.length()==0){
			cout<<"pangram"<<endl;
		}else{
			cout<<"missing "<<alphabet<<endl;
		}
		
	}

}