#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main() {
	int n;
	cin >> n;

	int x;
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if(x<0)ans++;
	}

	cout<<ans<<endl;



}