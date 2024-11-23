/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-23 15:03:54
 * @LastEditTime : 2024-11-23 17:46:56
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : restore.cpp
 * @     © 2024 FeiYehua
 */
//这题就离谱，瞎写的乱搞做法居然就T一个点！
#include<bits/stdc++.h>
using namespace std;
//k小于1000.
//n小于1e4
int t,n,k;
const int maxN=1e4+10;
struct node{
    int l,r;
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
int ans[maxN];
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
                printf("%d ",ans[i]);
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
        for(int j=1;j<=n;j++)
        {
            a[j].l=fr(),a[j].r=fr();
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
            getAns();
        }
    }
}