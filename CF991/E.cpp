/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-05 22:33:08
 * @LastEditTime : 2024-12-06 00:26:49
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : E.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int t;
string a,b,c;
const int maxN=1e3+10;
int dp[maxN*2][maxN];
void getDP()
{
    dp[0][0]=0;
    for(int i=1;i<c.size();i++)
    {
        if(max(0,(int)i+1-(int)b.size())==0)
        {
            dp[i][0]=min(dp[i][0],dp[i-1][0]+(b[i]!=c[i]));
        }
        for(int j=max(0,i+1-(int)b.size())+(max(0,(int)i+1-(int)b.size())==0);j<min(i+1,(int)a.size())-(min(i+1,(int)a.size())==i+1);j++)
        {
            dp[i][j]=min(dp[i][j],dp[i-1][j]+(b[i-j]!=c[i]));
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(a[j]!=c[i]));
        }
        if(min(i+1,(int)a.size())==i+1)
        {
            dp[i][i]=min(dp[i][i],dp[i-1][i-1]+(a[i]!=c[i]));
        }
    }
    cout<<dp[c.size()-1][a.size()-1]<<endl;
}
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        memset(dp,0x3f,sizeof dp);
        a='0'+a;
        b='0'+b;
        c='0'+c;
        getDP();
    }
    return 0;
}