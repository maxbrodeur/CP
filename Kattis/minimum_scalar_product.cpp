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
	int c = 1;
	while(n--){
		int w,W;
		cin>>w;
		W = w;
		vector<long long> x;
		vector<long long> y;

		int temp;
		while(w--){
			cin>>temp;
			x.push_back(temp);
		}
		w = W;
		while(w--){
			cin>>temp;
			y.push_back(temp);
		}

		sort(x.begin(),x.end(),greater<int>());
		sort(y.begin(),y.end());

		long long product = 0;
		vector<long long>::iterator j = y.begin();
		for (vector<long long>::iterator i = x.begin(); i != x.end(); ++i)
		{
			product += (*i)*(*j);
			j=j+1;
		}
		printf("Case #%d: %lld\n",c,product);
		c++;

 
	}




	return 0;
}