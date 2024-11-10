/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-10 23:17:13
 * @LastEditTime : 2024-11-10 23:34:39
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1077.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int m,n;
const int mod=1e6+7;
const int maxn=110;
int dp[maxn][maxn];
int maxCnt[maxn];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>maxCnt[i];
    }
    for(int i=0;i<=n;i++) dp[0][i]=1;
    for(int i=1;i<=m;i++)//前m盆
    {
        for(int j=1;j<=n;j++)//前n种
        {
            for(int k=0;k<=maxCnt[j]&&i-k>=0;k++)//摆k盆
            {
                dp[i][j]+=dp[i-k][j-1];
                dp[i][j]%=mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=dp[m][i];
        ans%=mod;       
    }
    cout<<dp[m][n]<<endl;//这里注意，因为前面已经考虑到使k=0，所以不用再处理ans+=dp[m][i];
    return 0;
}