/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-07 09:19:05
 * @LastEditTime : 2024-11-07 10:13:11
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1364.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
struct townInfp{
    int u,v;
    int w;
    int father;
    int depth;
}towns[300];
int n,w,u,v;
bool haveFat[300];
int root=1;
int ans=1e9;
void getDepth(int depth,int pt)
{
    towns[pt].depth=depth;
    if(towns[pt].u!=0) getDepth(depth+1,towns[pt].u);
    if(towns[pt].v!=0) getDepth(depth+1,towns[pt].v);
    return;
}
int getLength(int pt1,int pt2)
{
    if(towns[pt1].depth==towns[pt2].depth)
    {
        if(pt1==pt2) return 0;
        if(towns[pt1].father==towns[pt2].father) return 2;
        else return towns[pt1].depth*2;
    }
    if(towns[pt1].depth<towns[pt2].depth) swap(pt1,pt2);//pt1深度大于pt2深度
    int result=0;
    while(towns[pt1].depth>towns[pt2].depth)
    {
        pt1=towns[pt1].father;
        result++;
    }
    result+=getLength(pt1,pt2);
    return result;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w>>u>>v;
        towns[i].w=w,towns[i].u=u,towns[i].v=v;
        haveFat[u]=1,haveFat[v]=1;
        towns[u].father=i,towns[v].father=i;
    }
    for(;root<=n;root++)
    {
        if(!haveFat[root]) break;
    }
    getDepth(0,root);
    for(int i=1;i<=n;i++)
    {
        int tmp=0;
        for(int j=1;j<=n;j++)
        {
            if(j==i) continue;
            else
            {
                tmp+=towns[j].w*getLength(i,j);
            }
        }
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}