#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;

int count(string board){
	int count = 0;
	for (char c : board){
		if (c=='o')count++;
	}
	return count;
}

string reduce(string board){
	string res;
	int cnt = count(board);
	string ans = board;
	int cur_count = cnt;
	string cur_str = ans;
	for (int i = 0; i < 11; ++i)
	{
		string left, right;
		left = board;
		right = board;
		char cur = board[i];
		char next = board[i+1];
		//RIGHT
		int right_count = 12;
		int left_count = 12;
		if(i != 10 && cur == 'o' && next == 'o' && board[i+2] == '-'){
			right[i] = '-';
			right[i+1] = '-';
			right[i+2] = 'o';
			right = reduce(right);
			right_count = count(right);
		}
		if(i!=0 && cur == 'o' && next == 'o' && board[i-1] == '-'){
			left[i] = '-';
			left[i+1] = '-';
			left[i-1] = 'o';
			left = reduce(left);
			left_count = count(left);
		}

		cur_count = left_count;
		cur_str = left;
		if(left_count>right_count){
			cur_count = right_count;
			cur_str = right;
		}
		if(cnt>cur_count){
			cnt = cur_count;
			ans = cur_str;
		}
	}
	return ans;
}

int main() {
	string line;
	getline(cin, line);
	int n = stoi(line);
	for (int i = 0; i < n; ++i)
	{
		getline(cin,line);
		cout<<count(reduce(line))<<endl;

	}

	return 0;

}