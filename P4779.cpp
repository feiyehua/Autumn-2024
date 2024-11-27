/***
 * @Author       : FeiYehua
 * @Date         : 2024-11-27 18:50:44
 * @LastEditTime : 2024-11-27 19:39:41
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P4779.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxN = 1e5 + 10;
int n, m, s;
int head[maxN];
int tot;
struct node
{
    int x;    // 终边
    int next; // 下一条同起始点的边的下标
    int w;    // 权
} sides[5 * maxN];
void add(int u, int v, int w)
{
    tot++;
    sides[tot].x = v;
    sides[tot].w = w;
    sides[tot].next = head[u];
    head[u] = tot;
}
int fr()
{
    int num = 0;
    char ch;
    ch = getchar_unlocked();
    while (isspace(ch))
        ch = getchar_unlocked();
    while (isdigit(ch))
    {
        num = num * 10 + ch - '0';
        ch = getchar_unlocked();
    }
    return num;
}
struct node1
{
    int num, d;
    bool operator>(const node1 &a) const
    {
        return d > a.d;
    }
    bool operator<(const node1 &a) const
    {
        return d < a.d;
    }
};
priority_queue<node1, vector<node1>, greater<node1>> disHeap; // 存储已知最短边
bool vis[maxN];
int dis[maxN];
int u, v, w;
int cnt = 1;
signed main()
{
    #ifdef TEST
    freopen("/Users/xiong/Documents/CPP/Autumn-2024/P3371_2.in","r",stdin);
    freopen("/Users/xiong/Documents/CPP/Autumn-2024/ans.out","w",stdout);
    #endif
    n = fr(), m = fr(), s = fr();
    for (int i = 1; i <= m; i++)
    {
        u = fr(), v = fr(), w = fr();
        add(u, v, w);
        // add(v,u,w);
    }
    // memset(dis,0x3f,sizeof dis);
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[s] = 0, vis[s] = 1;
    int cur = s; // 从第一个点开始
    while (cnt < n)
    {
        cnt++;
        int tmp = head[cur]; // 存储边下标
        while (tmp != 0)
        {
            if (dis[cur] + sides[tmp].w < dis[sides[tmp].x])
            {
                node1 a;
                a.num = sides[tmp].x;
                a.d = dis[cur] + sides[tmp].w;
                disHeap.push(a);
                dis[sides[tmp].x] = dis[cur] + sides[tmp].w;
            }
            tmp = sides[tmp].next;
        }
        while (!disHeap.empty() && vis[disHeap.top().num])
        //这个语句为什么不行？原来是因为把s点记错了……无语
        //堆内存储的是当前更新了的节点，但是这些节点可能已经被访问过了
        //while (!disHeap.empty() && dis[disHeap.top().num] < disHeap.top().d)
        //需要弹出一些已经被更新过的节点，即该节点已经有了更短的路径
        {
            disHeap.pop();
        }
        if (!disHeap.empty())
        {
            cur = disHeap.top().num;
            disHeap.pop();
            vis[cur] = 1;
        }
        else
        {
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}