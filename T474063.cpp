/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-10 14:44:52
 * @LastEditTime : 2024-11-10 16:42:44
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : T474063.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int x,y,p,q;
int main()
{
    cin>>x>>y>>p>>q;
    cout<<min(min(p,x-p),min(q,y-q));
    return 0;
}