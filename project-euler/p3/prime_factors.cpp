#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> factorization(long N){
    vector<long> factors;
    for (size_t d = 2; d*d <= N; d++)
    {
        while(N%d==0){
            N /= d;
            factors.push_back(d);
        }
    }
    if (N>1)
    {
        factors.push_back(N);
    }
    return factors;
}

int main(){
    vector<long> factors = factorization(600851475143);
    long m = *max_element(factors.begin(), factors.end());
    cout<<m<<endl;
    cout<<"With factors: ";
    for (long p : factors)
    {
        cout<<p<<" ";
    }
    cout<<endl;
}