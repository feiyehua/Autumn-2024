/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-27 23:40:46
 * @LastEditTime : 2024-11-28 08:10:29
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1141.cpp
 * @     © 2024 FeiYehua
 */
//考虑每个点搜索一次，复杂度是n^2。//算错了，是n^3，过不了n=1000.需要剪枝。
//询问o1。
#include<bits/stdc++.h>
using namespace std;
const int maxN=1010;
int m[maxN][maxN];
bool vis[maxN][maxN];
int ans[maxN][maxN];
int dirX[]={0,1,0,-1};
int dirY[]={1,0,-1,0};
int n,q;
int fr()
{
    int num=0;
    char ch;
    ch=getchar_unlocked();
    while(isspace(ch)) ch=getchar_unlocked();
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar_unlocked();
    }
    return num;
}
struct node{
    int x,y;
};
vector<node> visVec;
void dfs(int si,int sj,int ci,int cj)
{
    for(int i=0;i<=3;i++)
    {
        if(!vis[ci+dirX[i]][cj+dirY[i]]&&(!m[ci][cj])==m[ci+dirX[i]][cj+dirY[i]])
        {
            vis[ci+dirX[i]][cj+dirY[i]]=1;
            node a;
            a.x=ci+dirX[i],a.y=cj+dirY[i];
            visVec.push_back(a);
            ans[si][sj]++;
            dfs(si,sj,ci+dirX[i],cj+dirY[i]);
        }
    }
}
int main()
{
    n=fr(),q=fr();
    memset(m,0xff,sizeof m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char ch=getchar_unlocked();
            while(isspace(ch)) ch=getchar_unlocked(); 
            m[i][j]=ch-'0';
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(ans[i][j]!=0) continue;
            visVec.clear();
            //memset(vis,0,sizeof vis);
            vis[i][j]=1;
            ans[i][j]=1;
            dfs(i,j,i,j);
            for(auto it:visVec)
            {
                ans[it.x][it.y]=ans[i][j];
                vis[it.x][it.y]=0;//剪枝：点是互相可达的，所以所有访问过的点有相同的可达点数量
                //这里既然已经访问了被vis的点，就直接把vis数组给清掉。memset的常数有点大，用不起
            }
            vis[i][j]=0;
        }
    }
    for(int k=1;k<=q;k++)
    {
        int i,j;
        i=fr(),j=fr();
        cout<<ans[i][j]<<"\n";
    }
    return 0;
}