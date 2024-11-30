/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-30 22:46:11
 * @LastEditTime : 2024-11-30 22:48:19
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : A.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int t,a,b;
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
        if(a>=b) swap(a,b);//使a<b
        int l=lcm(a,b);
        // for(int j=0;j<a;j++)//枚举除以m的模
        // {

        // }
        cout<<l<<endl;
    }
}