/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-06 19:15:24
 * @LastEditTime : 2024-11-06 20:03:46
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1318.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int n;
const int maxN=1e5+10;
int h[maxN];
int curStart,curEnd;
int ans;
//我们考虑用双指针来做。
//考虑从start开始，end向右移动，到第一个小于等于start的地方结束，计算两个块之间的积水面积；
void getWaterSize(int l,int r)
{
    int height=min(h[l],h[r]);
    for(int i=l+1;i<r;i++)
    {
        ans+=max(height-h[i],0);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }
    for(int i=n-1;i>0;i--)//如果在结束前有一段递减区间，会导致此前的一小段积水面积无法被正常计算。
    //但是这样还是会导致某些段出问题。
    //正解是将水坑分为三种，前后分别搜索。
    //如5000 1 1 1 4 5 4 3 2 1 0
    {
        if(h[i]<h[i-1]) h[i]=0;
        else break;
    }
    while(h[n-1]==0) n--;
    curStart=2,curEnd=3;
    while(1)
    {
        while(h[curStart]>h[curEnd]&&curEnd<n) curEnd++;
        if(curEnd>=n) {getWaterSize(curStart,n-1);break;}
        getWaterSize(curStart,curEnd);
        curStart=curEnd,curEnd++;
    }
    cout<<ans<<endl;
    return 0;
}