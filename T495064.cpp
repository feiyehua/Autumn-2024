/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-10 16:33:35
 * @LastEditTime : 2024-11-10 17:30:20
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : T495064.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxN=2e5+10;
const int maxA=1e9+10;
int n,k;
struct pt
{
    int num;
    int loc;
    int next;
}a[maxN];
int b[maxN];
bool mut[maxN];
int cnt[maxN];
bool flagB;
int fr()
{
    char ch;
    int num=0;
    ch=getchar();
    while(isspace(ch)) ch=getchar();
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar();
    }
    return num;
}
bool isMut(int x)
{
    if(x==n) return 1;
    if(a[x].num+k>=a[a[x].next].num) return 0;
    return 1;
}
bool updateMut()
{
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
        //mut[i]=;//1可以移动
        if(!isMut(i)) {cnt[i]++;flag=0;}//不能移动时的处理
        else a[i].num+=k;
    }
    return flag;
}
bool cmp(const pt& a,const pt& b)
{
    return a.num<b.num;
}
signed main()
{
    n=fr(),k=fr();
    for(int i=1;i<=n;i++)
    {
        a[i].num=fr();
        a[i].loc=i;
        if(i>=3&&(a[i].num-a[i-1].num!=a[i-1].num-a[i-2].num||a[i].num-a[i-1].num==0)) flagB=1;
    }
    a[0].num=__LONG_LONG_MAX__;
    sort(a+1,a+n+1,cmp);
    int last=n;
    int i=last-1;
    while(a[i].num==a[last].num)
    {
        last--,i--;
    }
    for(i=last-1;i>=1;i--)
    {
        a[i].next=last;
        if(a[i-1].num!=a[i].num)
        {
            last=i;
        }
    }
    if(!flagB&&n>3000)
    {
        for(int i=n;i>=1;i--)
        {
            cnt[i]=n-i;
        }
        for(int i=1;i<=n;i++)
        {
            b[a[i].loc]=cnt[i];
        }
        for(int i=1;i<=n;i++)
        {
            cout<<b[i]<<" ";
        }
    }
    else if(n<=3000000)
    {
        while(!updateMut());
        for(int i=1;i<=n;i++)
        {
            b[a[i].loc]=cnt[i];
        }
        for(int i=1;i<=n;i++)
        {
            cout<<b[i]<<" ";
        }
    }
    return 0;
}