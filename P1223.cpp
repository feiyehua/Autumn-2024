/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-19 23:13:02
 * @LastEditTime : 2024-11-19 23:17:19
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1223.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=1010;
int n;
struct node{
    int num,t;
}peo[maxN];
double t;
double total;
bool cmp(const node& a,const node& b)
{
    return a.t<b.t;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        peo[i].num=i;
        cin>>peo[i].t;
    }
    sort(peo+1,peo+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        total+=peo[i].t*(n-i);
        cout<<peo[i].num<<' ';
    }
    cout<<"\n";
    printf("%.2lf\n",total/n);
    return 0;
}