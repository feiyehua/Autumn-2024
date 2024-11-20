/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-15 19:14:12
 * @LastEditTime : 2024-11-15 19:21:20
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : T539824.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;

int x,n;
int cards[10];
int cnt[10];
int ans;
int main()
{
    cin>>x>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>cards[j];
        }
        sort(cards+1,cards+6);
        int j=5;
        while(cards[j]>x&&j>0) j--;
        //cout<<"j="<<j<<endl;
        if(j==0) continue;
        cnt[cards[j]]++;
        x-=cards[j];
    }
    for(int i=1;i<=5;i++)
    {
        cout<<cnt[i]<<" ";
    }
    cout<<endl<<x;
    return 0;
}