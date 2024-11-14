/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-13 11:37:31
 * @LastEditTime : 2024-11-14 23:31:22
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1621.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
#ifndef TEST
const int maxN=1e5+10;
#else
const int maxN=110;
#endif
bool vis[maxN];
int cnt;
int prime[maxN];
int a,b,p;
int fa[maxN];
int ans;
void getPrime()
{
    vis[1]=1;//1不是质数
    for(int i=2;i<=b;i++)
    {
        if(!vis[i])
        {
            cnt++;
            prime[cnt]=i;
        }
        for(int j=1;j<=cnt&&prime[j]*i<=b;j++)
        {
            vis[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
    // for(int i=1;i<=cnt;i++)
    // {
    //     cout<<prime[i]<<" ";
    // }
}
int find(int x)
{
    if(fa[x]!=x)
    {
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
void unite(int x,int y)
{
    fa[x]=find(x);
    fa[y]=find(y);
    fa[fa[x]]=fa[y];
}
int main()
{
    cin>>a>>b>>p;
    getPrime();
    for(int i=a;i<=b;i++)
    {
        fa[i]=i;
    }
    int start=lower_bound(prime+1,prime+cnt+1,p)-prime;
    //cout<<start;
    for(int i=start;i<=cnt;i++)
    {
        for(int j=ceil((float)a/prime[i])+1;j*prime[i]<=b;j++)//难绷！向上取整显然是需要算出一个浮点数才能向上取整，需要强制类型转换
        {
            unite(j*prime[i],(j-1)*prime[i]);
        }
    }
    memset(vis,0,sizeof vis);
    for(int i=a;i<=b;i++) find(i);
    for(int i=a;i<=b;i++)
    {
        if(vis[find(i)]==0) vis[find(i)]=1,ans++;
    }
    cout<<ans;
    return 0;
}