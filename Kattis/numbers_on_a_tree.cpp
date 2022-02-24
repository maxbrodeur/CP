#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <math.h>	

using namespace std;



int main(){

	int H;
	cin>>H;
	int max = pow(2,H+1);
	int root = max-1;
	int ans = root;
	char c;
	while(cin>>c){
		if(c=='L'){
			ans = (ans << 1) & root;
		}

		if(c=='R'){
			ans = ((ans << 1) - 1) & root;
		}
	}

	cout<<ans<<endl;

	return 0;
}