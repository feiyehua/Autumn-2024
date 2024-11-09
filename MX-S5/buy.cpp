/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-09 09:03:54
 * @LastEditTime : 2024-11-09 12:06:58
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : T533912.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
//从优惠金额a-b最小的看起，找到优惠金额最大的优惠券
//用a-b排序物品，优惠起价w排序优惠券，区间查找最大的v
//使用线段树维护区间最大值
//找到最大优惠额，用总价减去即可
int n,m;
int maxDis,sum;
const int maxN=1e6+10;
int minA=maxN,maxW=0;
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
struct item{
    int a,b,disc;
}items[maxN];
struct cop{
    int w,v;//w起用
}cops[maxN];
struct tree{
    int l;
    int r;
    int maxDis;
    int loc;//取到最大值的时刻
}nodes[maxN*4];
int a[2*maxN];
int loc;
int leafLoc[maxN];
void updateMaxLoc(int point)
{
    if(nodes[point*2].maxDis>nodes[point*2+1].maxDis)
    {
        nodes[point].maxDis=nodes[point*2].maxDis;
        nodes[point].loc=nodes[point*2].loc;
    }
    else
    {
        nodes[point].maxDis=nodes[point*2+1].maxDis;
        nodes[point].loc=nodes[point*2+1].loc;
    }
}
// int findLoc(int w)
// {
//     w++;//找第一个小于等于w+1的下标
//     int l=1,r=n;
//     int mid=(l+r)/2;
//     while(l<r)
//     {
//         if(cops[mid].w<w) l=mid;
//         else if(cops[mid].w>=w) r=mid-1;
//     }
// }
void build(int l,int r,int point)
{
    nodes[point].l=l,nodes[point].r=r;
    if(l==r)
    {
        nodes[point].maxDis=cops[l].v;
        nodes[point].loc=l;
        leafLoc[l]=point;
        return;
    }
    else
    {
        int mid=(l+r)/2;
        build(l,mid,point*2);
        build(mid+1,r,point*2+1);
        //nodes[point].maxDis=max(nodes[point*2].maxDis,nodes[point*2+1].maxDis);
        updateMaxLoc(point);
    }
}
int getMax(int l,int r,int point,int tl,int tr,int* loc)
{
    if(r<tl||l>tr) return -INT_MAX;
    if(r<=tr&&l>=tl) {*loc=nodes[point].loc;return nodes[point].maxDis;}
    int mid=(l+r)/2;
    int loc1,loc2;
    int max1=getMax(l,mid,point*2,tl,tr,&loc1),max2=getMax(mid+1,r,point*2+1,tl,tr,&loc2);
    if(max1<max2)
    {
        *loc=loc2;
        return max2;
    }
    else
    {
        *loc=loc1;
        return max1;
    }
}
void update(int point)//这个点的券被用了
{
    nodes[point].maxDis=-INT_MAX;
    point/=2;
    while(point>=1)
    {
        updateMaxLoc(point);
        //nodes[point].maxDis=max(nodes[point*2].maxDis,nodes[point*2+1].maxDis);
        point/=2;
    }
}
bool cmpI(const item& a,const item& b)
{
    if(a.disc!=b.disc)
    return a.disc<b.disc;
    else return a.a<b.a;
}
bool cmpC(const cop& a,const cop& b)
{
    return a.w<b.w;
}
signed main()
{
    #ifndef ONLINE_JUDGE

    //freopen("./Autumn-2024/MX-S5/buy/buy3.in","r",stdin);
    #endif
    n=fr(),m=fr();
    for(int i=1;i<=n;i++)
    {
        items[i].a=fr(),items[i].b=fr();
        items[i].disc=items[i].a-items[i].b;
        sum+=items[i].a;
        minA=min(minA,items[i].a);
    }
    for(int i=1;i<=m;i++)
    {
        cops[i].w=fr(),cops[i].v=fr();
        maxW=max(maxW,cops[i].w);
    }
    if(maxW<=minA)
    {
        for(int i=1;i<=n;i++)
        {
            a[i]=items[i].disc;
        }
        for(int i=1;i<=m;i++)
        {
            a[i+n]=cops[i].v;
        }
        sort(a+1,a+1+m+n,greater<int>());
        for(int i=1;i<=n;i++)
        {
            sum-=a[i];
        }
        cout<<sum;
        return 0;
    }
    sort(items+1,items+1+n,cmpI);
    sort(cops+1,cops+1+m,cmpC);
    build(1,m,1);
    for(int i=1;i<=n;i++)
    {
        //对第i个物品用券
        cop tmp;
        tmp.w=items[i].a+1;
        int r=lower_bound(cops+1,cops+1+m,tmp,cmpC)-cops-1;
        loc=-1;
        int curMax=getMax(1,m,1,1,r,&loc);
        //cout<<r<<" "<<i<<" "<<curMax<<" "<<maxDis<<endl;
        maxDis+=max(curMax,items[i].disc);
        if(curMax>items[i].disc)
        {
            update(leafLoc[loc]);
        }
    }
    cout<<sum-maxDis<<endl;
    return 0;
}