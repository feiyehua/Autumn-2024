/***
 * @Author       : FeiYehua
 * @Date         : 2024-11-28 08:46:14
 * @LastEditTime : 2024-11-28 10:20:54
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P3916.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
struct node
{
    int x, last;
} side[maxN];
int head[maxN];
int tot;
void add(int u, int v)
{
    tot++;
    side[tot].x = v;
    side[tot].last = head[u];
    head[u] = tot;
}
int u, v;
int n, m;
int ans[maxN];
void dfs(int x,int t)
{
    if (ans[x] >=t)
    {
        //assert(ans[x] >= x);
        return;// ans[x];
    }

    int v = head[x];
    ans[x]=t;
    //ans[x] = x;//这句话放在这里是不行的，因为此时这个点还是未知的。如果出现了双向边，则只有前一个被搜索的点是被正确更新的；后一个被搜索的点没有被正确更新
    while (v != 0)
    {
        dfs(side[v].x,t);
        v = side[v].last;
    }
    return;
}
//正解：反向建图反向跑dfs；这样可以保证每次更新出来的点一定是最远的点；
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        /* if(u>v) */ swap(u,v);
        add(u, v);
    }
    for (int i = n; i >= 1; i--)
    {
        if (ans[i] == 0)
        {
            dfs(i,i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}