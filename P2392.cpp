/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-05 16:36:06
 * @LastEditTime : 2024-12-05 16:39:22
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P2392.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int sumT,maxT;
int ans;
int s[5];
int ti[40];
void dfs(int dep,int maxDep,int t)
{
    if(t>sumT/2) return;
    if(maxDep==dep)
    {
        maxT=max(t,maxT);
    }
    else
    {
        dfs(dep+1,maxDep,t+ti[dep+1]);
        dfs(dep+1,maxDep,t);
    }
}
int main()
{
    for(int i=1;i<=4;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=4;i++)
    {
        sumT=0;
        maxT=0;
        for(int j=1;j<=s[i];j++)
        {
            cin>>ti[j];
            sumT+=ti[j];
        }
        dfs(0,s[i],0);
        ans+=(sumT-maxT);
    }
    cout<<ans<<endl;
}