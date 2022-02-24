#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int e,f,c;
	cin>>e>>f>>c;
	int n = e+f;
	int r = n%c;
	int m = n - n%c;
	int count = m/c;
	m = m/c + r;
	while(m>=c){
		r = m%c;
		m = m-r;
		count+=m/c;
		m = m/c + r;
	}
	cout<<count<<endl;
	return 0;
}