/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-26 10:48:11
 * @LastEditTime : 2024-11-26 11:42:13
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1939.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
int n[110],t;
int pre[40][5][5];
int maxN;
void ksm(int x)
{
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=4;k++)
            {
                pre[x][i][j]+=(pre[x-1][i][k]%mod)*(pre[x-1][k][j]%mod);
                pre[x][i][j]%=mod;
            }
        }
    }
}

int result[2][5][5];
void getResult(int x,int* p)//x是被乘的幂次
{
    *p=!(*p);
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            result[*p][i][j]=0;
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=4;k++)
            {
                result[*p][i][j]+=(result[!(*p)][i][k]%mod)*(pre[x][k][j]%mod);
                result[*p][i][j]%=mod;
            }
        }
    }
}
signed main()
{
    pre[1][1][1]=1,pre[1][1][2]=1,pre[1][2][3]=1,pre[1][3][4]=1,pre[1][3][1]=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n[i];
        maxN=max(maxN,n[i]);
    }
    for(int i=2;i<=log2(maxN)+1;i++)
    {
        ksm(i);
    }
    for(int i=1;i<=t;i++)
    {
        if(n[i]<=3) cout<<"1\n";
        else
        {
            int po=n[i]-4;//矩阵要乘的幂次
            int cur=0;
            int cnt=1;
            memset(result,0,sizeof result);
            result[0][1][1]=1,result[0][2][2]=1,result[0][3][3]=1,result[0][4][4]=1;
            while(po>0)
            {
                if(po%2==1)
                {
                    getResult(cnt,&cur);
                }
                cnt++,po/=2;
            }
            int ans=(result[cur][1][1]*2)%mod+result[cur][4][1]+result[cur][2][1]+result[cur][3][1];
            ans%=mod;
            cout<<ans<<endl;
        }
    }
    return 0;
}