#include <iostream>
#include <cmath>
#include <climits>

using namespace std;



int main(){
	float pa,ka,pb,kb,n;

    cin>>pa>>ka>>pb>>kb>>n;

    float slope = pa-(pb*ka)/kb;

    auto f = [=](int x) {return n/kb-ka/kb*x;};
    auto c = [=](int x, int y) {return pa*x+pb*y;};

    int na, nb, cost;

    int y = 0, x = 0;
    cost = INT_MAX;
    while(y>=0){
        y = static_cast<int>(ceil(f(x)));
        int cost_ = c(x,y);
        if (cost_<cost){
            cost = cost_;
            na = x;
            nb = y;
        }
        x++;
    }

    cout<<na<<" "<<nb<<" "<<cost<<endl;
	
	return 0;
}