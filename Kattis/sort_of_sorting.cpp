#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

bool sort_of_sort(pair<string, int> p1, pair<string, int> p2){
	string s1 = p1.first;
	string s2 = p2.first;
	if(s1[0]==s2[0]){
		if(s1[1]==s2[1])return p1.second < p2.second;
		return (s1[1]<s2[1]);
	}

	return (s1[0]<s2[0]);
}

int main(){
	int n;
	cin >> n;
	while(n){
		vector<pair<string, int> > names;
		for (int i = 0; i < n; ++i)
		{
			string name;
			cin >> name;
			names.push_back(make_pair(name, i));

		}

		sort(names.begin(), names.end(),sort_of_sort);
		for (std::vector<pair<string, int> >::iterator i = names.begin(); i != names.end(); ++i)
		{
			cout<<(*i).first<<endl;
		}
		cin >> n;
		if(n)cout<<endl;
	}
	
}
