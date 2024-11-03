/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-03 22:52:10
 * @LastEditTime : 2024-11-03 23:26:11
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11228.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
bool forestMap[1010][1010];
bool visited[1010][1010];
int x,y,d;
int cnt;
void readforestMap()
{
    char ch='0';
    while(ch!='\n') ch=getchar();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ch=getchar();
            if(ch=='x') forestMap[i][j]=1;
        }
        while(ch!='\n') ch=getchar();
    }
    return;
}
void nextStep()
{
    int nextX=x,nextY=y;
    switch (d)
    {
    case 0:
        nextY++;
        break;
    case 1:
        nextX++;
        break;
    case 2:
        nextY--;
        break;
    case 3:
        nextX--;
        break;
    default:
        break;
    }
    if(nextX<=n&&nextX>=1&&nextY>=1&&nextY<=m&&forestMap[nextX][nextY]==0)
    {
        x=nextX,y=nextY;
        if(!visited[x][y]) cnt++;
        visited[x][y]=1;
    }
    else
    {
        d=(d+1)%4;
    }
    return;
}
int main()
{
    cin>>t;
    //freopen("ans.ans","w",stdout);
    for(int i=1;i<=t;i++)
    {
        cnt=1;
        memset(forestMap,0,sizeof(forestMap));
        memset(visited,0,sizeof(visited));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        visited[x][y]=1;
        readforestMap();
        for(int i=1;i<=k;i++)
        {
            nextStep();
        }
        cout<<cnt<<endl;
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         cout<<visited[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}