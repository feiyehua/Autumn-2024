/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-13 10:15:14
 * @LastEditTime : 2024-11-13 10:39:54
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P3958.cpp
 * @     © 2024 FeiYehua
 */
//多测不清空见祖宗
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxN=1010;
int t,n,h,r;
int x,y,z;
struct pt{
    int x,y,z;
}pts[maxN];
int parent[maxN];
bool toTop[maxN];
bool toButtom[maxN];
bool isConnected(int x,int y)
{
    //printf("%lld %lld\n",((pts[x].x-pts[y].x)*(pts[x].x-pts[y].x)+(pts[x].y-pts[y].y)*(pts[x].y-pts[y].y)+(pts[x].z-pts[y].z)*(pts[x].z-pts[y].z)),y);
    if(((pts[x].x-pts[y].x)*(pts[x].x-pts[y].x)+(pts[x].y-pts[y].y)*(pts[x].y-pts[y].y)+(pts[x].z-pts[y].z)*(pts[x].z-pts[y].z))<=4*r*r)
    {
        //printf("%lld %lld 1\n",x,y);
        return 1;
    }
    return 0;
}
int find(int x)
{
    if(parent[x]!=x) parent[x]=find(parent[x]);
    return parent[x];
}
void unite(int x,int y)
{
    parent[x]=find(x);
    parent[y]=find(y);
    parent[parent[x]]=parent[y];
}
signed main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        memset(toButtom,0,sizeof toButtom);
        memset(toTop,0,sizeof toTop);
        cin>>n>>h>>r;
        for(int j=1;j<=n;j++)
        {
            parent[j]=j;
        }
        for(int j=1;j<=n;j++)
        {
            cin>>x>>y>>z;
            if(z<=r) toButtom[j]=1;
            if(z+r>=h) toTop[j]=1;
            pts[j].x=x,pts[j].y=y,pts[j].z=z;
            for(int k=1;k<j;k++)
            {
                if(isConnected(j,k)) unite(k,j);
            }
        }
        bool flag=0;
        for(int j=1;j<=n&&!flag;j++)
        {
            if(toButtom[j])
            {
                for(int k=1;k<=n&&!flag;k++)
                {
                    if(toTop[k]&&find(j)==find(k)) flag=1;
                }
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}