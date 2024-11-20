#include<bits/stdc++.h>
using namespace std;
int ty,a,b,c,d;
int main()
{
    cin>>ty>>a>>b>>c>>d;
    if(ty==0)
    {
        cout<<a+b;
    }
    else 
    {
        cout<<max(a-c,0)+max(b-d,0);
    }
    return 0;
}