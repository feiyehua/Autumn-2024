/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-15 19:03:52
 * @LastEditTime : 2024-11-15 19:06:01
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : T539823.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int a[1010],maxA[1010];
int n;
int cnt=1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    maxA[n]=a[n];
    for(int i=n-1;i>=1;i--)
    {
        maxA[i]=max(maxA[i+1],a[i]);
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]>maxA[i+1]) cnt++;
    }
    cout<<cnt;
}