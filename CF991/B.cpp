/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-05 22:32:53
 * @LastEditTime : 2024-12-05 23:20:51
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : B.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t;
// const int maxN=
int a;
int sum[3];
int num[3];
signed main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        sum[1]=0;
        sum[0]=0;
        num[1]=0;
        num[0]=0;
        int mod[2];
        mod[0]=n/2;
        mod[1]=n/2+n%2;
        for(int j=1;j<=n;j++)
        {
            cin>>a;
            sum[j%2]+=a;
            num[j%2]+=sum[j%2]/(mod[j%2]);
            sum[j%2]%=(mod[j%2]);
        }
        if(sum[0]==0&&sum[1]==0&&num[0]==num[1])
        {
            cout<<"yes\n";
        }
        else cout<<"no\n";
    }
    return 0;
}