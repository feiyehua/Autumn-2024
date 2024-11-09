/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-09 00:14:26
 * @LastEditTime : 2024-11-10 00:03:10
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1006.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=60;
int a[maxN][maxN];
int val[2*maxN][maxN][maxN];
int m,n;
int x[]={-1,0,-1,0},y[]={-1,0,0,-1};
void update(int i,int j,int k,int l)
{
    if(j+x[l]<0||k+y[l]<0) return;
    val[i][j][k]=max(val[i][j][k],val[i-1][j+x[l]][k+y[l]]+a[j+1][i-j+1]+a[k+1][i-k+1]);//+a[j+x[l]][i+1-(j+x[l])]+a[k+y[l]][i+1-(k+y[l])]);
}
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=m+n-2;i++)//前i步
    {
        for(int j=max(i-n+1,0);j<=min(m-1,i);j++)//第一次向下走j步
        {
            for(int k=max(i-n+1,0);k<=min(m-1,i);k++)//第2次向下走k步
            {
                
                //转移到这个状态有四种可能：1下2下；1右2右；1下2右；1右2下
                for(int l=0;l<4;l++)
                update(i,j,k,l);
                if(k==j&&i!=m+n-2) 
                {
                    val[i][j][k]-=a[j+1][i-j+1];
                    //continue;
                }
                
            }
        }
    }
    cout<<val[m+n-2][m-1][m-1];
    return 0;
}