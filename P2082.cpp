/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-06 09:01:45
 * @LastEditTime : 2024-11-06 09:09:48
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P2082.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+10;
int n;
struct aa{
    long long l;
    long long r;
}b[maxN];
bool cmp(const aa &a,const aa &b)
{
    return a.l<b.l;
}
long long fr()
{
    char ch;
    long long num=0;
    ch=getchar();
    while(isspace(ch)) ch=getchar();
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar();
    }
    return num;
}
long long ans;
int main()
{
    n=fr();
    for(int i=1;i<=n;i++)
    {
        b[i].l=fr();
        b[i].r=fr();
    }
    sort(b+1,b+1+n,cmp);
    long long start=b[1].l,end=b[1].r;
    for(int i=1;i<=n;i++)
    {
        if(b[i].r<=end&&b[i].l>=start) continue;
        else if(b[i].l<=end) end=b[i].r;
        else ans+=(end-start+1),start=b[i].l,end=b[i].r;
    }
    ans+=(end-start+1);
    cout<<ans<<endl;
    return 0;
}