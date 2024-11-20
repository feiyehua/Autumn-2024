/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-20 20:33:05
 * @LastEditTime : 2024-11-20 20:47:06
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1250.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
struct node{
    int a,b,t;
}a[maxn];
bool c[maxn];
bool cmp(const node& a,const node& b)
{
    return a.b<b.b;
}
void plant(int i)
{
    int j=a[i].b;
    int x=0;
    for(int k=a[i].a;k<=a[i].b;k++)
    {
        x+=c[k];
    }
    while(j>=a[i].a&&x<a[i].t)//从后往前种树
    {
        if(c[j]) {
            j--;
            continue;
        }
        c[j]=1;
        x++;
        j--;
    }
}
int n,h;
int main()
{
    cin>>n;
    cin>>h;
    for(int i=1;i<=h;i++)
    {
        cin>>a[i].a>>a[i].b>>a[i].t;
    }
    sort(a+1,a+1+h,cmp);
    for(int i=1;i<=h;i++)
    {
        plant(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=c[i];
    }
    cout<<ans<<endl;
    return 0;
}