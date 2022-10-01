#include <iostream>
#include <vector>

using namespace std;

bool is_base10_palindrome(long N){
    vector<int> digits;
    int count = 0;
    while (N>0)
    {
        int temp = N;
        N/=10;
        int digit = temp - N*10;
        digits.push_back(digit);
        count++;
    }
    vector<int>::iterator bot = digits.begin();
    vector<int>::iterator top = digits.end();
    int i = 0;
    while(i<count/2){
        top--;
        if(*bot!=*top){
            return false;
        }
        bot++;
        i++;
    }
    return true;   
}

int main(){
    int max = 999*999;
    int N = max;

    while(N>99*99){
        while(!is_base10_palindrome(N)){N--;}
        int a = 999;
        int b = N/a;
        while(a>99 && b<1000 && (a*b!=N || b<100)){
            a--;
            b = N/a;
        }
        if(a*b==N && b>99 && a>99 && b<1000){
            cout<<a <<"and"<< b<< endl;
            N=1;
        } 
        N--;
    }
  
}