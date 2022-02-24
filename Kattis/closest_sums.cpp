#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int closest_sum(int num, int *arr, int n){
	int sum = arr[0] + arr[1];
	int a, b, i, j;
	b = 0;
	for (int i = 0; i < n; ++i)
	{
		int new_sum = sum;
		a = arr[i];
		if(i<n-1){
			b = arr[i+1];
			new_sum = a+b;
		}
		for (int j = i+1; j < n && a+b<=num; ++j)
		{
			b = arr[j];
			int temp_sum = a+b;
			int diff_1 = abs(num - temp_sum);
			int diff_2 = abs(num - new_sum);
			if(new_sum<0 || diff_1<diff_2)new_sum = temp_sum;
		}
		if(abs(new_sum - num)<abs(sum - num))sum = new_sum;
	}
	return sum;
}

int main() {
	int n;
	int count = 1;
	while(cin>>n){
		int arr[n];
		for (int i = 0; i < n; ++i)cin>>arr[i];
		sort(arr, arr+n); //MAYBE NOT USEFUL

		int m;
		cin >> m;
		cout<<"Case "<<count<<":"<<endl;
		for (int i = 0; i < m; ++i)
		{
			int q;
			cin>>q;

			cout<<"Closest sum to "<<q<<" is "<<closest_sum(q, arr, n)<<"."<<endl;
			
		}
		count++;
	}

}