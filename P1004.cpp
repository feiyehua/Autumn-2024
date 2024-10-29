/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-10-29 23:15:57
 * @LastEditTime : 2024-10-29 23:36:23
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1004.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int n;
struct pointInfo{
    int value;
    bool used;
}pointsInfo[10][10];
int maxValue;
int rangeMax[10][10];
void updateRangeMax(int x,int y)
{
    for(int i=x;i<=n;i++)
    {
        for(int j=y;j<=n;j++)
        {
            rangeMax[x][y]+=pointsInfo[i][j].value;
        }
    }
}
void dfs(int x,int y,int cnt,int curValue)
{
    if(cnt==2&&curValue+rangeMax[x][y]<=maxValue)
    {
        return;
    }
    if(x==n&&y==n&&cnt==1)
    {
        pointsInfo[x][y].used=1;
        dfs(1,1,2,curValue+pointsInfo[x][y].value);
        pointsInfo[x][y].used=0;
    }
    else if(x==n&&y==n&&cnt==2)
    {
        maxValue=max(maxValue,curValue);
        return;
    }
    else
    {
        bool flag=0;
        if(pointsInfo[x][y].used==0)
        {
            curValue+=pointsInfo[x][y].value;
            pointsInfo[x][y].used=1;
            flag=1;
        }
        if(x<n)
        {
            dfs(x+1,y,cnt,curValue);
        }
        if(y<n)
        {
            dfs(x,y+1,cnt,curValue);
        }
        if(flag)
        {
            pointsInfo[x][y].used=0;
        }
        return;
    }
}
int main()
{
    cin>>n;
    int x=0,y=0,z=0;
    do
    { 
        cin>>x>>y>>z;
        pointsInfo[x][y].value=z;
    } while (!(x==0&&y==0&&z==0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            updateRangeMax(i,j);
        }
    }
    dfs(1,1,1,0);
    cout<<maxValue<<endl;
    return 0;
}
