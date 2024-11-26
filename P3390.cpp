/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-26 09:58:37
 * @LastEditTime : 2024-11-26 10:25:10
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P3390.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long 
constexpr const int mod=1e9+7;
int pre[50][110][110];
int result[2][110][110];
int n,k;
int p=0;
void ksm(int x)//求2的x次幂
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                pre[x][i][j]+=(pre[x-1][i][k]%mod)*(pre[x-1][k][j]%mod);
                pre[x][i][j]%=mod;
            }
        }
    }
}
void getResult(int x,int* p)
{
    *p=!(*p);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            result[*p][i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                result[*p][i][j]+=(pre[x][i][k]%mod)*(result[!(*p)][k][j]%mod);
                result[*p][i][j]%=mod;
            }
        }
    }
}

signed main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>pre[1][i][j];
            if(i==j) result[0][i][j]=1;
        }
    }
    for(int i=2;i<=log2(k)+1;i++)
    {
        ksm(i);
    }
    int cnt=1;
    while(k>0)
    {
        if(k%2==1)
        {
            getResult(cnt,&p);
        }
        cnt++;
        k/=2;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<result[p][i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}