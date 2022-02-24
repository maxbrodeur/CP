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
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	if(n==2){
		cout<<2<<endl;
		return 0;
	}
	int d = 0;
	int m = 1;
	while(m<n){
		d++;
		m = 2*m;
	}
	cout<<d+1<<endl;
	
	return 0;
}