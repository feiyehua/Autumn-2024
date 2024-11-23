/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-23 15:03:54
 * @LastEditTime : 2024-11-23 21:49:53
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : restore.cpp
 * @     © 2024 FeiYehua
 */
//这题就离谱，瞎写的乱搞做法居然就T一个点！
//这一题，考虑两种区间的形式：
//第一种是全部都是长区间，即ri-li+1大于等于k恒成立，那么每个区间内一定能取到一个k的倍数。
//反之，则找到最短的区间，然后：
//首先，找到它的所有大于k的因数；
//然后，验证这些因数是否满足题意即可。
//虽然思路如此，但是似乎将每个r，l排序一下就可以了……
//原因显然是段区间对剪枝更加友好
//真是乱搞题
#include<bits/stdc++.h>
using namespace std;
//k小于1000.
//n小于1e4
int t,n,k;
const int maxN=1e4+10;
struct node{
    int l,r;
    int num;
    bool operator<(const node&a)
    {
        int len1=r-l+1;
        int len2=a.r-a.l+1;
        if(len1!=len2) return len1<len2;
        return l<a.l;
    }
}a[maxN];
int fr()
{
    int num=0;
    char ch;
    ch=getchar();
    while(isspace(ch)) ch=getchar_unlocked();
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar_unlocked();
    }
    return num;
}
int ans[maxN],ans1[maxN];
int minR=INT_MAX;
void getAns()
{
    int org=k;
    while (k <= minR&&k-org<=1e8)
    {
        bool flag=1;
        //memset(ans,0,sizeof(ans));
        for (int i = 1; i <= n; i++)
        {
            if(a[i].l%k==0||a[i].r%k==0)
            {
                ans[i]=(a[i].l%k==0 ? a[i].l : a[i].r);
                continue;
            }
            else if((a[i].l/k+1)*k<=a[i].r)
            {
                ans[i]=(a[i].l/k+1)*k;
                continue;
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            printf("Yes\n");
            for(int i=1;i<=n;i++)
            {
                ans1[a[i].num]=ans[i];
            }
            for(int i=1;i<=n;i++)
            {
                printf("%d ",ans1[i]);
            }
            printf("\n");
            return;
        }
        k++;
    }
    printf("No\n");
}
int main()
{
    t=fr();
    for(int i=1;i<=t;i++)
    {
        minR=INT_MAX;
        n=fr(),k=fr();
        //memset(a,0,sizeof(a));
        //这里删掉了几个清空的操作，节省了很多时间，看来memset还是很耗时的
        for(int j=1;j<=n;j++)
        {
            a[j].l=fr(),a[j].r=fr();
            a[j].num=j;
            minR=min(minR,a[j].r);
        }
        if(k==1)
        {
            printf("Yes\n");
            for(int j=1;j<=n;j++)
            {
                printf("%d ",a[j].l);
            }
            printf("\n");
        }
        else
        {
            sort(a+1,a+1+n);
            getAns();
        }
    }
}