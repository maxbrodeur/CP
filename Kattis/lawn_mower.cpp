#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool comp_pair(pair<float, float> p1, pair<float, float> p2){
	return (p1.first < p2.first);

}

int main() {
	int nx, ny;
	float w;

	
	cin >> nx >> ny >> w;
	while(nx != 0 && ny != 0 && w != 0.0){

		vector<pair<float, float> > y_axis;
		vector<pair<float, float> > x_axis;

		
		float min = 100, max = 0;

		bool done = false;


		float y;
		for (int i = 0; i < nx; ++i)
		{
			cin >> y;
			float down, up;
			down = y-w/2.0;
			up = y+w/2.0;
			if(down<0){down = 0;}
			if(up>75){up = 75;}
			if(up>max)max=up;
			if(down<min)min = down;
			y_axis.push_back(make_pair(down,up));

		}

		if(min>0 || max<75){cout<<"NO"<<endl;done=true;}

		min = 100;
		max = 0;
		float x;
		for (int i = 0; i < ny; ++i)
		{
			cin >> x;
			float left, right;
			left = x-w/2.0;
			right = x+w/2.0;
			if(left<0){left = 0;}
			if(right>100){right = 100;}
			if(right>max)max=right;
			if(left<min)min = left;
			x_axis.push_back(make_pair(left,right));


		}

		if(!done && (min>0 || max<100)){cout<<"NO"<<endl;done=true;}

		sort(x_axis.begin(), x_axis.end(), comp_pair);
		sort(y_axis.begin(), y_axis.end(), comp_pair);

		if(!done){

			for (vector<pair<float, float > >::iterator i = x_axis.begin(); i != x_axis.end(); ++i)
				{
				vector<pair<float, float > >::iterator next = i+1;
				while(next != x_axis.end() && (*next).second<=(*i).second) ++next;
				if(next != x_axis.end()){
						if((*next).first>(*i).second){
							cout<<"NO"<<endl;
							done = true;
							break;
						}
					}
				}
				if(!done){
					
					for (vector<pair<float, float > >::iterator i = y_axis.begin(); i != y_axis.end(); ++i)
					{
						vector<pair<float, float > >::iterator next = i+1;
						while(next != y_axis.end() && (*next).second<=(*i).second) ++next;
						if(next != y_axis.end()){
							if((*next).first>(*i).second){
								cout<<"NO"<<endl;
								done = true;
								break;
							}
						}
					}

					if(!done)cout<< "YES" << endl;
				}

		}

		cin >> nx >> ny >> w;
	}


	

}