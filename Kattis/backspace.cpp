#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>

using namespace std;

int main() {
	list<char> ans;
	char c;
	cin >> c;
	while(!cin.eof()){

		if (c == '<'){
			ans.pop_back();
		} else {
			ans.push_back(c);
		}
		cin >> c;
	}
	
	while(!ans.empty()){
		c = ans.front();
		cout<<c;
		ans.pop_front();
	}
	cout << endl;


}