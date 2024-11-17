/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-15 19:57:06
 * @LastEditTime : 2024-11-15 19:57:08
 * @LastEditors  : FeiYehua
 * @Description  : 202411C K/D/A
 * @FilePath     : T539822.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int n;
int k,d,a;
char c;
int b[100010];
int ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>k>>c>>d>>c>>a;
        if(k-d>=10) b[i]=k*(k-d)+a;
        else if(k>=d) b[i]=(k-d+1)*3+a;
        else b[i]=a*2;
        if(b[i]>b[ans]) ans=i;
    }
    cout<<ans;
}