/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-04 20:09:41
 * @LastEditTime : 2024-12-04 20:17:11
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11371.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxN=1e5+10;
int n,k;
//不难发现，能够有解的充要条件是所有数关于k的模相等。
int mod;
bool flag;
int maxNum=0;
int cnt;
int a[maxN];
signed main()
{
    cin>>n>>k;
    cin>>a[1];
    mod=a[1]%k;
    maxNum=a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        maxNum=max(a[i],maxNum);
        if(mod!=a[i]%k) 
        {
            flag=1;
            cout<<"NO";
            break;
        }
    }
    if(!flag)
    {
        for(int i=1;i<=n;i++)
        {
            cnt+=(maxNum-a[i])/k;
        }
        cout<<"YES "<<cnt;
    }
    return 0;
}