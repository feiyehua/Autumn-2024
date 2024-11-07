/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-07 10:48:23
 * @LastEditTime : 2024-11-07 19:08:40
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P2285.cpp
 * @     © 2024 FeiYehua
 */
//DP题状态的设定：本题中将前i个鼠作为状态（而不是时间），节省了内存
//为什么可以这样做：从前一个点能否到达第二个点可以O(1)计算出来
#include<bits/stdc++.h>
using namespace std;
const int maxN=1e4+10;
int n,m;
struct mou{
    int x,y,t;
}mice[maxN];
int ans[maxN];
int res=0;
int getNum(int i,int j)//求从j点是否能到i点
{
    if(abs(mice[j].x-mice[i].x)+abs(mice[j].y-mice[i].y)<=mice[i].t-mice[j].t) return ans[j]+1;
    return 0;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>mice[i].t>>mice[i].x>>mice[i].y;
    }
    for(int i=1;i<=m;i++)
    {
        ans[i]=1;
        for(int j=1;j<i;j++)
        {
            ans[i]=max(ans[i],getNum(i,j));
            res=max(ans[i],res);
        }
    }
    cout<<res;
    return 0;
}