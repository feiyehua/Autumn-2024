/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-23 14:30:19
 * @LastEditTime : 2024-11-23 14:38:11
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : T472655.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,p;
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m>>k>>p;//n阵营，每阵营最多m人，p个人已经被分配，车队有k人
        if(k+p/n<=m) 
        {
            cout<<"Together\n";
        }
        else if((ceil(p/(float)m)<n&&m>=k)||p%m+k<=m)
        {
            cout<<"Chance\n";
        }
        else cout<<"Divide\n";
    }
}