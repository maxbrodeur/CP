#include <iostream>

using namespace std;

int main(){
    int count = 0;
    for (size_t i = 1; i < 1000; i++)
    {

        if (i%3 == 0 || i%5 == 0)
        {
            count+=i;
        }
        
    }
    cout<<count<<endl;  
}