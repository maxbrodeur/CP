#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
	string line;
	while(getline(cin,line)){

		int n = stoi(line);

		// INIT DS
		priority_queue<int> p;
		stack<int> s;
		queue<int> q;

		bool pb, sb, qb;
		pb = true;
		sb = true;
		qb = true;
		int count = 3;
		for (int i = 0; i < n; ++i)
		{

			int command;
			cin >> command;

			int x;
			cin >> x;

			if (command == 1){

				p.push(x);
				s.push(x);
				q.push(x);

			} else {

				if(!p.empty()){
					int pe, se, qe;
					pe = p.top();
					se = s.top();
					qe = q.front();
					p.pop();
					s.pop();
					q.pop();

					if(pe != x && pb){count--;pb = false;}
					if(qe != x && qb){count--;qb = false;}
					if(se != x && sb){count--;sb = false;}
				} else {
					count = 0;
				}
				



			}


		}

		if (count <= 0){
			cout << "impossible" << endl;
		}else if(count > 1){
			cout << "not sure" << endl;
		}else{
			if(sb)cout<<"stack"<<endl;
			if(pb)cout<<"priority queue"<<endl;
			if(qb)cout<<"queue"<<endl;
		}

		getline(cin,line);

	}



}