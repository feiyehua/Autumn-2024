/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-12 18:00:15
 * @LastEditTime : 2024-11-12 23:29:31
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1160.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+10;
struct stu{
    int l,r;
}stus[maxN];
//实现一个链表结构
//下标是同学编号
void ins(int i,char op,int j)//将i插入到j旁边
{
    switch (op)
    {
    case 'l':
        stus[i].r=j;
        stus[i].l=stus[j].l;
        stus[stus[j].l].r=i;
        stus[j].l=i;
        break;
    case 'r':
        //改变j的右指针和j右的左指针
        stus[i].l=j;
        stus[i].r=stus[j].r;
        stus[stus[j].r].l=i;
        stus[j].r=i;
        break;
    default:
        break;
    }
    stus[0].l=0,stus[0].r=0;
    return;
}
void rem(int i)
{
    if(stus[i].l==0&&stus[i].r==0) return;
    int l=stus[i].l,r=stus[i].r;
    stus[i].l=0,stus[i].r=0;
    stus[l].r=r,stus[r].l=l;
    stus[0].l=0,stus[0].r=0;
    return;
}
int n,m;
int k,p;
int x;
int start=1;
int main()
{
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>k>>p;
        if(k==start&&p==0) start=i;
        if(p==0)
        {
            ins(i,'l',k);
        }
        else
        {
            ins(i,'r',k);
        }
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        if(start==x) start=stus[x].r;
        rem(x);
    }
    if(m==n) 
    {
        cout<<" ";
        return 0;
    }
    int cur=start;
    while(cur!=0)
    {
        cout<<cur<<" ";
        cur=stus[cur].r;
    }
    return 0;
}