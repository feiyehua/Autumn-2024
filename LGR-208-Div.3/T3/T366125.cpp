/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-23 14:52:30
 * @LastEditTime : 2024-11-23 15:43:07
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : T366125.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
//经过归纳，总结得出操作次数是数字2因子的个数
//2因子越多，需要的操作数越多
int t;
int k;
signed main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>k;
        if(k==0) {cout<<"NO!\n";continue;}
        int cnt=0;
        while(k%2==0)
        {
            k/=2;
            cnt++;
        }
        cout<<cnt+1<<endl;
    }
    return 0;
}