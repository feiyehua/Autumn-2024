/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-20 11:30:49
 * @LastEditTime : 2024-11-20 11:33:33
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1803_1.cpp
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
int start=1;
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
    cont[0].r=1;
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
    //if(i==start) start
}
int main()
{
    n=fr();
    for(int i=1;i<=n;i++)
    {
        cont[i].a=fr(),cont[i].b=fr();
    }
    //mySort(1,n);
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
    build();
    for(int i=2;i<=n;i++)
    {
        while(cont[cont[i].l].b>=cont[i].b) dele(cont[i].l);
    }
    int cur=cont[cont[0].r].r;
    //while(cont[cur].del) cur++;
    //cout<<cont[1].a<<" "<<cont[1].b<<cont[1].del<<endl;
    int endTime = cont[cont[0].r].b;
    int cnt=1;
    while(cur!=0)
    {
        //cout<<cont[cur].a<<" "<<cont[cur].b<<endl;
        
        if(cont[cur].a>=endTime) cnt++,endTime=cont[cur].b;
        cur=cont[cur].r;
    }
    cout<<cnt<<endl;
    return 0;
}
// 与P11232 [CSP-S 2024] 超速检测的区别：
// P11232:给出n个线段，要求找到尽量少的点，使每个线段上至少有一个点；
// 贪心策略：按照开始点排序；并删除所有包含其他任意一个区间的区间（因为无论选什么点，只要点在较小区间内，这个区间内一定会有这个点）
// 这时起始点、终点均严格递增；
// 每次贪心地取当前线段的最右端、无法覆盖左端时更新取值；
// P1802:给出n个线段，要求找到不重叠的最大线段数量；
// 贪心策略：按照结束点排序，那么选在前面的线段严格优于选后面的点；每次选后，在当前点开始时间大于等于上一个点结束时间时更新取值数量；
// 如果使用P11232相同的思路，同样是可以的！只是因为需要删除时间过长的点，所以时间复杂度会比较大，而且写一个链表结构调起来比较麻烦。
// 同理，P11232可不可以以区间尾端为关键字排序呢？
// 我们只需要每次记录区间结束，遇到一个区间开始大于记录的区间结束点的，就加一个点。