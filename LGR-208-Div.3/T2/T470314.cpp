/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-23 14:43:19
 * @LastEditTime : 2024-11-23 14:51:23
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : T470314.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
const int maxN=1e5+10;
int k,n;
int a[maxN];
signed main()
{
    scanf("%lld",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld%lld",&n,&k);
        int maxB=0;
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&a[j]);
            maxB=max(maxB,a[j]);
            ans+=maxB;
        }
        if(k==0)
        {
            cout<<ans<<endl;
            continue;
        }
        if(n==2)//n=2时时特殊的情况，可能无法得到最优条件
        {
            if((a[1]>a[2]&&k%2==1)||(a[1]<a[2]&&k%2==0)||a[1]==a[2]) 
            {
                cout<<a[1]+a[2]<<endl;
            }
            else
            {
                cout<<2*maxB<<endl;
            }
        }
        else 
        {
            cout<<n*maxB<<endl;
        }
    }
    return 0;
}