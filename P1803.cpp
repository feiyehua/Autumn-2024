/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-19 16:30:53
 * @LastEditTime : 2024-11-19 17:49:03
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1803.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6+10;
int n;
struct con{
    int a,b;
    bool del;
    int l,r;
    
}cont[maxN];
bool cmp(const con&a, const con& b)
    {
        return a.a<b.a;
    }
int fr()
{
    char ch;
    ch=getchar();
    int num=0;
    while(isspace(ch)) ch=getchar();
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar();
    }
    return num;
}
void mySort(int l,int r)
{
    if(l>=r) return;
    con pivot=cont[l];
    int cl=l,cr=r;
    while(cl!=cr)
    {
        while(cl<cr&&cont[cr].a>=pivot.a)
        {
            cr--;
        }
        //此时cr对应的数小于pivot
        //如果break出来，可能是因为cl等于cr，这时也是安全的
        cont[cl]=cont[cr];
        while(cl<cr&&cont[cl].a<=pivot.a)
        {
            cl++;
        }
        //此时cl对应的数大于pivot，交换cl，cr
        cont[cr]=cont[cl];
    }
    cont[cl]=pivot;
    mySort(l,cl-1);
    mySort(cl+1,r);
}
void build()
{
    cont[1].r=2,cont[n].l=n-1;
    for(int i=2;i<=n-1;i++)
    {
        cont[i].l=i-1,cont[i].r=i+1;
    }
}
void dele(int i)
{
    if(cont[i].del||i<=0) return;
    cont[i].del=1;
    cont[cont[i].l].r=cont[i].r;
    cont[cont[i].r].l=cont[i].l;
}
int main()
{
    n=fr();
    for(int i=1;i<=n;i++)
    {
        cont[i].b=fr(),cont[i].a=fr();
    }
    sort(cont+1,cont+1+n,cmp);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<cont[i].a<<" "<<cont[i].b<<endl;
    // }
    // cout<<endl;
    //下面需要去重：去除所有可以覆盖其余任何一个线段的线段，即保证b也递增
    //方法很简单：只需要将所有不满足b递增的数据删掉即可
    //我们使用一个链表结构来维护
    //int last=cont[1].b;
    // build();
    // for(int i=2;i<=n;i++)
    // {
    //     if(cont[cont[i].l].b>=cont[i].b) dele(cont[i].l);
    // }
    int endTime=cont[1].a;
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(cont[i].b<endTime) continue;
        cnt++;
        endTime=cont[i].a;
    }
    cout<<cnt<<endl;
    return 0;
}
