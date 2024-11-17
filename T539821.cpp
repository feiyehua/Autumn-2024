/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-15 19:55:23
 * @LastEditTime : 2024-11-15 19:56:25
 * @LastEditors  : FeiYehua
 * @Description  : 202411B Legends Never Die
 * @FilePath     : T539821.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int a,b,c,k;

int main()
{
    cin>>a>>b>>c>>k;
    if(a+b>=k) cout<<"Yes";
    else cout<<"No";
    cout<<endl;
    if(a+c>=k) cout<<"Yes";
    else cout<<"No";
    cout<<endl;
    if(b+c>=k) cout<<"Yes";
    else cout<<"No";
    cout<<endl;
}