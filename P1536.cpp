/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-13 09:18:21
 * @LastEditTime : 2024-11-13 09:33:03
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1536.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=1200;
int n,m;
bool roadMap[maxN][maxN];
int parent[maxN];
int u,v;
int find(int x)
{
    if(parent[x]!=x)
    {
        parent[x]=find(parent[x]);
    }
    return parent[x];
}
void unite(int x,int y)
{
    parent[x]=find(x);
    parent[y]=find(y);
    //parent[x]=parent[y];
    //这里写错了，应该是将x的祖先的祖先设置成y的祖先，而不是将x的祖先设置成y的祖先；这样的话，就相当于把x从一个集合中拿出来，放到另一个集合，而不是合并两个集合。
    parent[parent[x]]=parent[y];
}
int main()
{
    while(1)
    {
        int ans=0;
        memset(parent,0,sizeof parent);
        cin>>n;
        if(n==0) break;
        cin>>m;
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v;
            //roadMap[u][v]=1,roadMap[v][u]=1;
            unite(u,v);
        }
        for(int i=1;i<=n;i++)
        {
            if(parent[i]==i)
            {
                ans++;
            }
        }
        cout<<ans-1<<endl;
    }
    return 0;
}