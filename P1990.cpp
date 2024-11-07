/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-07 08:03:19
 * @LastEditTime : 2024-11-07 08:41:06
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1990.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int maxN =1e6+10;
int result[maxN];
int t[maxN];
signed main()
{
    cin>>n;
    result[1]=1,result[2]=2,result[3]=5,result[4]=11;
    t[1]=1,t[2]=3,t[3]=8,t[4]=19;
    for(int i=5;i<=n;i++)
    {
        result[i]=result[i-1]+result[i-2]+2*t[i-3]+2;
        result[i]%=10000;
        t[i]=result[i]+t[i-1];
        t[i]%=10000;
    }
    cout<<result[n];
    return 0;
}