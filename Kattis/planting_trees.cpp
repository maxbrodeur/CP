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
	int t;
	vector<int> dp;
	while(n--){
		cin>>t;
		dp.push_back(t+1);
	}

	int start, end;
	start = 0;
	end = 0;
	sort(dp.begin(),dp.end(),greater<int>());

	for (vector<int>::iterator i = dp.begin(); i != dp.end(); ++i)
	{
		if (start+*i>end)
		{
			end = start+*i;
		}
		++start;
	}

	cout<<end+1<<endl;
	return 0;
}