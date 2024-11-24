/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-24 15:32:53
 * @LastEditTime : 2024-11-24 17:00:27
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P3379.cpp
 * @     © 2024 FeiYehua
 */
//居然真的“一遍复述“出了lca代码
#include<bits/stdc++.h>
using namespace std;
const int maxN=5e5*2+10;
struct node{
    int last;//链表结构，表示上一条边
    //从x到y的一条边
    //以x为起点的边可能有很多条，所以不能直接通过数组访问，需要用一个链表结构。
    int y;

}tree[maxN];
int head[maxN];
int fat[maxN][30];
int n,m,s;
int a,b;
int x,y;
int tot;
int dep[maxN];
int lg[maxN];
void add(int x,int y)
{
    tot++;
    tree[tot].y=y;
    tree[tot].last=head[x];
    head[x]=tot;
}
void dfs(int now,int fath)
{
    dep[now]=dep[fath]+1;//维护当前节点的深度
    fat[now][0]=fath;
    for(int i=1;i<=lg[dep[now]];i++)
    {
        fat[now][i]=fat[fat[now][i-1]][i-1];
    }
    for(int i=head[now];i>0;i=tree[i].last)
    {
        if(tree[i].y!=fath) dfs(tree[i].y,now);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]!=dep[y])
    {
        x=fat[x][lg[dep[x]-dep[y]]];
    }
    if(x==y) return x;
    for(int i=lg[dep[x]];i>=0;i--)
    {
        if(fat[x][i]!=fat[y][i])
        {
            x=fat[x][i],y=fat[y][i];
        }
    }
    return fat[x][0];
}
int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        add(x,y);add(y,x);//树是没有方向的，故需要添加两次
    }
    for(int i=1;i<=n;i++)
    {
        lg[i]=lg[i-1]+(1<<lg[i-1]==i/2);
    }
    dfs(s,0);//从树根开始，将树遍历一次
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
    return 0;
}















#if 0

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct zzz {
    int t, nex;//这里用来存边
    //t是
}e[500010 << 1]; int head[500010], tot;
void add(int x, int y) {
	e[++tot].t = y;//y是儿子节点，x是父亲节点
	e[tot].nex = head[x];//这里应该是一个邻接表结构
    //head[x]就是存储上一个以x为起点的边的下标，通过使用nex即可访问
    //
	head[x] = tot;
}
int depth[500001], fa[500001][22], lg[500001];
void dfs(int now, int fath) {
    //从s，即树的根开始遍历
	fa[now][0] = fath; //记录距离自己为2^0点是自己的父亲
    depth[now] = depth[fath] + 1;//存储现在的深度，等于父亲的深度+1
	for(int i = 1; i <= lg[depth[now]]; ++i)//保证找2^i远的父亲不会超出当前总深度，附带了一个边界检查
		fa[now][i] = fa[fa[now][i-1]][i-1];//自己的2^i远的父亲等于自己2^i-1远的父亲的2^i-1远父亲
	for(int i = head[now]; i/*即i!=0，从表头遍历到表尾*/; i = e[i].nex)//继续向下搜索
		if(e[i].t != fath/*显然这里的用处是防止反向寻找，确保遍历一直向下*/) dfs(e[i].t, now);
}
int LCA(int x, int y) {
	if(depth[x] < depth[y]) swap(x, y);
	while(depth[x] > depth[y])//这个while语句保证了他们最终深度一定相等
		x = fa[x][lg[depth[x]-depth[y]] - 1];//-1的原因：预处理的时候已经+了1
	if(x == y) return x;//如果他们已经相等了，就直接返回
	for(int k = lg[depth[x]] - 1; k >= 0; --k)//否则一起向上跳
		if(fa[x][k] != fa[y][k])//如果跳到一起了，显然这两个就相等了，所以不跳。
			x = fa[x][k], y = fa[y][k];
	return fa[x][0];//最终返回的是最近的使fa[x][0]=fa[y][0]的点
}
int main() {
	int n, m, s; scanf("%d%d%d", &n, &m, &s);
	for(int i = 1; i <= n-1; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	for(int i = 1; i <= n; ++i)
		lg[i] = lg[i-1] + (1 << lg[i-1] == i);//预处理lgi的值
	dfs(s, 0);
	for(int i = 1; i <= m; ++i) {
		int x, y; scanf("%d%d",&x, &y);
		printf("%d\n", LCA(x, y));
	}
    for(int i=1;i<=1000;i++)
    {
        cout<<i<<" "<<lg[i]<<endl;
    }
	return 0;
}
#endif