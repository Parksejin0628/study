#include<iostream>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int main(void)
{
    FAST_IO;
    int input;
    cin>>input;
    for(int i=0; i<input; i+=4)
    {
        cout<<"long ";
    }
    cout<<"int";

    return 0;
}