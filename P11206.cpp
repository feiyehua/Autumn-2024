/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-04 20:38:33
 * @LastEditTime : 2024-12-05 08:30:25
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11206.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
//考虑从最底层向树根分配编号。最底层分配大编号，
//这样可以保证从右端分配的号数量一定会大于等于从左端分配的号，即不会出现不符合题意的情况。
//考虑指定一个点为树根，然后向下DFS遍历树，然后按照层数分配编号（模拟）即可。
//将每一层的节点编号存入vector。由于采用DFS遍历，所以在同一层中，左边一点先于右边进入vector中。
//但是如果出现了上一层有大量树叶的情况，就会导致分配出现问题。
//能否使用树论相关知识，将这棵树调整到深度最小的状态？

//题解：每次分配时，分配了一组大、小编号，此时一批父亲和儿子节点就对此后的分配没有影响了。如此继续分配，每次都成对分配，才能保证使需要分配小数字的地方均被分配小数字。
bool frontGuard;
int t,n;
const int maxN=1e5+10;
int head[maxN];
int num[maxN];
int tot;
struct node{
    int v;
    int last;
}side[maxN*2];//双向图，空间要开两倍
int l,r;
int u,v;
int cnt;
bool endGuard;
int fr()
{
    char ch;
    int num=0;
    ch=getchar_unlocked();
    while(isspace(ch)) ch=getchar_unlocked();
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar_unlocked();
    }
    return num;
}
void dfs(int u,int f)
{
    // cnt++;
    // assert(cnt<=1e6+10);
    int cur=head[u];
    while(cur!=0)
    {
        if(side[cur].v!=f) dfs(side[cur].v,u);
        cur=side[cur].last;
    }
    if(num[u]==0)
    {
        num[u]=r;
        r--;//u没有被赋过值，说明对其没有额外的要求，赋大值，父亲赋小值
        if(f!=0&&num[f]==0)
        {
            num[f]=l;
            l++;
        }
    }
}
void add(int u,int v)
{
    tot++;
    side[tot].v=v;
    side[tot].last=head[u];
    head[u]=tot;
    return;
}
int main()
{
    #ifdef TEST
    freopen("test.in","r",stdin);
    freopen("ans.out","w",stdout);
    cout<<(&endGuard-&frontGuard)/1024;
    #endif
    t=fr();
    for(int i=1;i<=t;i++)
    {
        tot=0;
        // cnt=0;
        memset(head,0,sizeof head);
        memset(side,0,sizeof side);
        memset(num,0,sizeof num);
        n=fr();
        l=1,r=n;
        for(int j=1;j<n;j++)
        {
            u=fr();
            v=fr();
            add(u,v);
            add(v,u);
        }
        dfs(1,0);
        for(int j=1;j<=n;j++)
        {
            cout<<num[j]<<' ';
        }
        cout<<"\n";
    }
    return 0;
}
/*
1
10
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10

*/