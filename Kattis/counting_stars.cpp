#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>

using namespace std;

class DisjSet{
	int *L, n;

public:

	DisjSet(int n){

		L = new int[n];
		this->n = n;
		make_set();


	}

	void make_set(){

		for (int i = 0; i < n; ++i)
		{
			L[i] = i;
		}

	}

	int find(int x){
		int root = x;
		while(root!=L[root])root = L[root];
		while(x!=L[x]){
			int next = L[x];
			L[x] = root;
			x = next;
		}
		return x;
	}

	void Union(int x, int y){
		L[find(x)] = find(y);
	}

};



int main() {
	
	int count = 1;
	int m, n; 
	cin >> m >> n;	
	string line;
	getline(cin, line); // for \n
	while(!cin.eof()){
		int grps = m*n; // bijection is (a, b) --> a*n + b where 0<=a<=m-1
		DisjSet set(grps);
		int blackroot = -1;
		for (int i = 0; i < m; ++i)
		{
			getline(cin, line);
			for (int j = 0; j < n; ++j)
			{
				int index = i*n + j;
				char c = line[j];

				//PUT ALL BLACKS IN SAME GROUP
				if (c == '#'){
					if(blackroot == -1){
						blackroot = index;
					}else{
						set.Union(index, blackroot);
						grps--;
					}
				} else {
					// IF above isn't black -> join 
					if (i>0) {
						if(blackroot==-1 || set.find(index-n)!=set.find(blackroot)){
							set.Union(index, index-n);
							grps--;
						}
					}
					// IF left isn't black -> join
					if (j>0) {
						if(blackroot==-1 || set.find(index-1)!=set.find(blackroot)){

							//Check if already counted above
							if(set.find(index)==index){grps--;}
							//Check if i just joined two separate groups!
							else if(i>0 && set.find(index-1) != set.find(index-n)){grps--;}

							set.Union(index,index-1);
						}
					}
				}

			}
		}
		if(blackroot!=-1)grps--; //remove group of black
		cout<<"Case "<<count<<": "<<grps<<endl;
		count++;
		cin >> m;
		if(!cin.eof()){
			cin>>n;
			getline(cin, line); //for \n
		}
		
	}

}



// Disjoint sets --> every star
// Key sets to count in the end (with Map??)