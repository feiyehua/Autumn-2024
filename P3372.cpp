/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-10-30 10:07:34
 * @LastEditTime : 2024-10-30 11:09:59
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P3372.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int maxN=1e5+10;
int a[maxN];
struct P3372
{
    int l,r;
    int sum;
    int lazy;//懒标记，标记没有向下传递的更改
}b[4*maxN];
void buildTree(int l,int r,int place)
{
    b[place].l=l,b[place].r=r;
    if(l==r)
    {
        b[place].sum=a[l];
        return;
    }
    else
    {
        int mid=(l+r)/2;
        buildTree(l,mid,place*2);
        buildTree(mid+1,r,place*2+1);
        b[place].sum=b[place*2].sum+b[place*2+1].sum;
        return;
    }
}
void update(int curL,int curR,int place,int l,int r,int num)
{
    if(curL>r||curR<l)
    {
        return;
    }
    else if(curL>=l&&curR<=r)
    {
        b[place].sum+=(curR-curL+1)*num;
        b[place].lazy+=num;
        return;
    }
    else if(curL==curR)
    {
        b[place].sum+=num;
        return;
    }
    else
    {
        int mid=(curL+curR)/2;
        b[place*2].lazy+=b[place].lazy;
        b[place*2+1].lazy+=b[place].lazy;
        b[place*2+1].sum+=b[place].lazy*(b[place*2+1].r-b[place*2+1].l+1);
        b[place*2].sum+=b[place].lazy*(b[place*2].r-b[place*2].l+1);
        b[place].lazy=0;
        update(curL,mid,place*2,l,r,num);
        update(mid+1,curR,place*2+1,l,r,num);
        b[place].sum=b[place*2].sum+b[place*2+1].sum;
        return;
    }
}
int getSum(int curL,int curR,int place,int l,int r)
{
    if(curL>r||curR<l)
    {
        return 0;
    }
    else if(curL>=l&&curR<=r)
    {
        return b[place].sum;
    }
    else if(curL==curR)
    {
        b[place].lazy=0;
        return b[place].sum;
    }
    else
    {
        int mid=(curL+curR)/2;
        b[place*2].lazy+=b[place].lazy;
        b[place*2+1].lazy+=b[place].lazy;
        b[place*2+1].sum+=b[place].lazy*(b[place*2+1].r-b[place*2+1].l+1);
        b[place*2].sum+=b[place].lazy*(b[place*2].r-b[place*2].l+1);
        b[place].lazy=0;
        return getSum(curL,mid,place*2,l,r)+getSum(mid+1,curR,place*2+1,l,r);
    }
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    buildTree(1,n,1);
    for(int i=1;i<=m;i++)
    {
        int ope=0;
        scanf("%lld",&ope);
        int x=0,y=0,k=0;
        switch(ope)
        {
            case 1:
            {
                scanf("%lld%lld%lld",&x,&y,&k);
                update(1,n,1,x,y,k);
                break;
            }
            case 2:
            {
                scanf("%lld%lld",&x,&y);
                printf("%lld\n",getSum(1,n,1,x,y));
                break;
            }
        }
    }
    return 0;
}