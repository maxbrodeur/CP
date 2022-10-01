#include <iostream>

using namespace std;

#define size 4000001

unsigned mem[size] = {0};
bool checked[size] = {false};

unsigned sum=0;

unsigned fib(unsigned N) {
    if (!checked[N]){
        mem[N]=fib(N-1)+fib(N-2);
        if (mem[N]%2==0)
        {
            sum+=mem[N];
        }
        checked[N]=true;
    }
    return mem[N];
}

int main(){
    mem[1]=1;
    mem[2]=2;
    checked[1]=true;
    checked[2]=true;
    sum+=2;
    
    unsigned res = 0;
    int i = 1;
    while(res<=4000000)
    {
       res = fib(i);
       i++;
    }
    cout<<sum<<endl;
    
}