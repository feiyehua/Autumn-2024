/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-06 23:20:38
 * @LastEditTime : 2024-11-06 23:26:22
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1616.cpp
 * @     © 2024 FeiYehua
 */
//不开long long见祖宗！
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxM=1e4+10;
const int maxT=1e7+10;
int m,t;
struct herbInfo{
    int a,b;
}herbs[maxM];
int value[maxT];
int ans;
signed main()
{
    cin>>t>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>herbs[i].a>>herbs[i].b;
    }
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i<herbs[j].a) continue;
            value[i]=max(value[i-herbs[j].a]+herbs[j].b,value[i]);
            ans=max(ans,value[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}