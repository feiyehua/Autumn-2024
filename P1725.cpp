/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-08 09:01:29
 * @LastEditTime : 2024-11-08 15:28:39
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1725.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
//这题用线段树找区间最大值，怪不得是一个绿题
int fr()
{
    char ch;
    ch=getchar();
    int s=1;
    int num=0;
    while(ch>'9'||ch<'0')
    {
        s=(ch=='-'?-1:1);
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar();
    }
    return num*s;
}
const int maxN=2e5+10;
long long sumA[maxN*2];//sumA[maxN*2];//
long long a[maxN];
int n,l,r;
long long ans=-__LONG_LONG_MAX__;
struct lineTree{
    int l;
    int r;
    long long max;
}treeAry[4*maxN];
int loc[maxN];//存储线段树叶子结点的下标
void build(int l,int r,int point)
{
    treeAry[point].l=l,treeAry[point].r=r;
    if(l==r) 
    {
        treeAry[point].max=a[l];
        loc[l]=point;
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,point*2);
    build(mid+1,r,point*2+1);
    treeAry[point].max=max(treeAry[point*2].max,treeAry[point*2+1].max);
    return;
}
long long getMax(int l,int r,int point,int tl,int tr)
{
    if(tl<0) tl=0;
    if(tr>n) tr=n;
    if(tr<l||tl>r||tl>tr)
    {
        return -__LONG_LONG_MAX__;//保险一点
    }
    if(l>=tl&&r<=tr)
    {
        return treeAry[point].max;
    }
    int mid=(l+r)/2;
    return max(getMax(l,mid,point*2,tl,tr),getMax(mid+1,r,point*2+1,tl,tr));
}
void update(int point,long long val)
{
    treeAry[point].max=val;//叶子结点是一定会被更新的
    point/=2;
    while(point!=1)
    {
        treeAry[point].max=max(treeAry[point*2].max,treeAry[point*2+1].max);//这里也写错了，更新是从子结点更新，而不是从新加的值更新
        point/=2;
    }
    treeAry[point].max=max(treeAry[point*2].max,treeAry[point*2+1].max);
}
int main()
{
    //freopen("./Autumn-2024/Cirno/cirno_hack.in","r",stdin);
    n=fr(),l=fr(),r=fr();
    for(int i=0;i<=n;i++)
    {
        a[i]=fr();
    }
    for(int i=1;i<l;i++)
    {
        a[i]=-__LONG_LONG_MAX__;
    }
    build(0,n,1);
    sumA[0]=a[0];
    for(int i=l;i<=n+r;i++)
    {
        // 从i-r到i-l可以跳到i
        // 需要保证i-l大于等于0，i-r小于等于n
        //if(i-r<0||i-l>n) continue;//一定不行 //这个地方写错了，需要理清楚i-l，i-r的大小关系；事实上，这个约束是多余的，在循环体中就已经确定了
        sumA[i]=a[i]+getMax(0,n,1,i-r,i-l);
        //cout<<i<<" "<<getMax(0,n,1,i-r,i-l)<<" "<<i-r<<" "<<i-l<<" "<<sumA[i]<<endl;
        if(i<=n) update(loc[i],sumA[i]);
    }
    for(int i=n+1;i<=n+l;i++)
    {
        ans=max(ans,sumA[i]);
    }
    cout<<ans<<endl;
    return 0;
}