#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int s,S,c,k;
	cin>>s>>c>>k;
	S = s;
	vector<int> socks;
	while(s--){

		int sock;
		cin>>sock;
		socks.push_back(sock);

	}

	sort(socks.begin(),socks.end());
	vector<int>::iterator i = socks.begin();
	int machines = 0;
	while(i != socks.end()){
		machines++;
		int j = c-1;
		while(j--){
			int cur = *i;
			i++;
			if(i==socks.end()){
				i--;
				break;
			}
			if(*i-cur>k){
				i--;
				break;
			}
		}
		i++;
	}

	cout<<machines<<endl;




	return 0;
}