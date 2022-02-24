#include <iostream>
#include <string>
#include <climits>
using namespace std;

int G[1000][1000];

void print_graph(int n){
	cout<<"\t";
	for (int i = 0; i < n; ++i)
	{
		cout<<"\t"<<i;
	}
	cout<<endl<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<i<<"\t [";
		for (int j = 0; j < n; ++j)
		{
			cout<<"\t"<<G[i][j];
		}
		cout<<"\t]"<<endl;
	} 
}

//NB OF DIFFERING CHARACters in aa sgtring
int string_diff(string s1, string s2) {
	int count = 0;
  for (int i = 0; i < s1.length(); ++i)
  {
  	if(s1.at(i)!=s2.at(i))count++;
  }
  return count;
}

//Min spanning tree
void prim(int n){

	bool mst_check[n];
	for (int i = 0; i < n; ++i)mst_check[i]=false;
	mst_check[0]=true;
	pair<int,int> tree[n-1];
	int count = 1;
	int vx[n];
	vx[0]=0;

	int ans = 0;

	while(count<n){
		int min = INT_MAX;
		pair<int,int> e(0,0);
		//Find smallest edge going out of tree in graph.
		//For all vx in tree
		for (int i = 0; i < count; ++i)
		{
			int v = vx[i];
			//find its smallest edge
			for (int j = 0; j < n; ++j)
			{
				int cur = G[v][j];
				//if vx not already in tree, and edge is smaller
				if(!mst_check[j] && cur<min){
					min=cur;
					e = make_pair(v,j);
				}
			}
		}
		//Add edge to tree, mark edge as visited
		ans+=min;
		tree[count-1]=e;
		mst_check[e.second]=true;
		vx[count]=e.second;
		count++;
	}

	cout<<ans<<endl;
	for (int i = 0; i < n-1; ++i)
	{
		cout<<tree[i].first<<" "<<tree[i].second<<endl;
	}

}



int main(){

	int n,m;
	cin >> n >> m;
	char c;
	string strands[n];
	for (int i = 0; i < n; ++i)
	{
		string strand;
		for (int j = 0; j < m; ++j)
		{
			cin >> c;
			strand.push_back(c);
		}

		strands[i]=strand;

	}

	//CONSTRUCT G
	for (int i = 0; i < n-1; ++i)
	{
		string s = strands[i];
		for (int j = i+1; j < n; ++j)
		{
			int weight = string_diff(strands[i], strands[j]);
			G[i][j] = weight;
			G[j][i] = weight;
		}
	}

	prim(n);

}