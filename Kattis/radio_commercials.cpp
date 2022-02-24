#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;


int main() {
	int n,p;
	cin >> n >> p;
	int dp[n];
	int nums[n];
	int sum = 0;
	int max = -10000000;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		nums[i]=num-p;
		sum = sum + num-p;
		dp[i]= sum;
		if(sum>max)max=sum;
	}

	for (int i = 1; i < n; ++i)
	{
		if(nums[i]>dp[i]){
			sum = 0;
			for (int j = i; j < n; ++j)
			{
				sum = sum + nums[j];
				if(dp[j]<sum)dp[j]=sum;
				if(sum>max)max = sum;
			}
		}
	}

	if(n==0)max=0;
	cout<<max<<endl;

	
	return 0;

}