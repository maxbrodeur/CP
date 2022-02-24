#include <iostream>
#include <queue>
#include <list>
#include <utility>
#include <climits>

using namespace std;

int main(){
	int N,H,L;
	cin >> N >> H >> L;

	int HL[N];
	bool checked[N];

	for (int i = 0; i < N; ++i){HL[i]=-1;checked[i]=false;}
	queue<int> Q;

	//Enqueue horrors
	int h;
	for (int i = 0; i < H; ++i){
		cin >> h;
		Q.push(h);
		HL[h] = 0;
	}

	int count = 0;

	int ans = h;
	//Make sim list
	list<pair<int,int> > sim;
	int one, two;
	for (int i = 0; i < L; ++i)
	{
		cin >> one >> two;
		sim.push_back(make_pair(one,two));
	}

	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		if(!checked[cur]){
			for (list<pair<int,int> >::iterator i = sim.begin(); i != sim.end(); ++i)
			{
				pair<int,int> p = *i;
				if(p.first != -1){
					// if i matched my current
					if(p.first == cur){
						(*i).first = -1; //overwrite
						// and the second has never been chosen
						if(HL[p.second] == -1){
							HL[p.second] = HL[p.first]+1;
							//winnerwinner???
							if(HL[ans]<=HL[p.second]){
								if(HL[ans]==HL[p.second]){
									if(ans>p.second)ans=p.second;
								}else{
									ans = p.second;
								}
							}
						}
						Q.push(p.second);

					} else if(p.second == cur){ // if i matched my current
						(*i).first = -1; //overwrite
						// and the second has never been chosen
						if(HL[p.first] == -1){
							HL[p.first] = HL[p.second]+1;
							//winnerwinner???
							if(HL[ans]<=HL[p.first]){
								if(HL[ans]==HL[p.first]){
									if(ans>p.first)ans=p.first;
								}else{
									ans = p.first;
								}
							}
						}
						Q.push(p.first);

					}
				}

			}
			checked[cur]=true;
			count++;
		}


	}
	//if not all checked, find smallest -1 in HL
	if(count!=N){
		ans = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			if(HL[i]==-1 && i<ans)ans = i;
		}
	}
	cout<<ans<<endl;




}