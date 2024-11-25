/***
 * @Author       : FeiYehua
 * @Date         : 2024-11-24 11:25:15
 * @LastEditTime : 2024-11-24 12:06:40
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : speaker.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
int n, q;
int c[maxN];
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
struct node
{
    int start, cur, price;
};
const int maxU = 20 + 10;
int m[maxU][maxU];
int price[maxU][maxU];
bool vis[maxU][maxU];
// void dfs(int start,int cur,int prize)
// {
//     price[start][cur]=prize;
//     for(int i=1;i<=n;i++)
//     {
//         if(m[cur][i]!=-1&&!vis[start][i])
//         {
//             vis[start][i]=1;
//             dfs(start,i,prize+m[cur][i]);
//         }
//     }
// }
int main()
{
#ifdef TEST
    freopen("./speaker/speaker1.in", "r", stdin);
    freopen("./speaker/out.ans", "w", stdout);
#endif
    n = fr(), q = fr();
    for (int i = 1; i <= n; i++)
    {
        c[i] = fr();
    }
    memset(m, 0xff, sizeof(m));
    memset(price, 0xff, sizeof(price));
    if (n <= 2000)
    {
        for (int i = 1; i < n; i++)
        {
            int u, v, w;
            u = fr(), v = fr(), w = fr();
            m[u][v] = w, m[v][u] = w;
        }
        deque<node> a;
        node tmp;
        tmp.start = 1, tmp.cur = 1, tmp.price = 0;
        a.push_front(tmp);
        vis[1][1] = 1;
        price[1][1]=0;
        int cur = 1;
        do
        {
            cur = a.back().cur;
            node curN = a.back();
            a.pop_back();
            for (int i = 1; i <= n; i++)
            {
                if (m[cur][i] !=-1)
                {
                    if (!vis[i][i]) // 这个点没有被访问过，以这个点为起点
                    {
                        vis[i][i] = 1;
                        price[i][i]=0;
                        node tmp;
                        tmp.start = i, tmp.cur = i, tmp.price = 0;
                        a.push_front(tmp);
                    }
                    node tmp = curN;
                    tmp.cur = i, tmp.price += m[cur][i];
                    for(int j=1;j<=n;j++)
                    {
                        if(j==i) continue;
                        if(price[cur][j]!=-1&&!vis[tmp.start][j])
                        {
                            price[tmp.start][j]=tmp.price+price[cur][j];
                            //price[j][tmp.start]=tmp.price+price[j][cur];
                            vis[tmp.start][j]=1;
                        }
                    }
                    if (!vis[tmp.start][i]  && tmp.start != tmp.cur)
                    {
                        vis[tmp.start][i]=1;;
                        price[tmp.start][tmp.cur] = tmp.price;
                        a.push_front(tmp);
                    }
                }
            }

        } while (!a.empty());
        // for(int i=1;i<=n;i++)
        // {
        //     dfs(i,i,0);
        // }
        for (int i = 1; i <= q; i++)
        {
            int x = fr();
            int y = fr();
            int ans = 0;
            for (int j = 1; j <= n; j++)
            {
                if (x == j)
                {
                    ans = max(ans, c[x] * 2 + c[y] - price[x][y]);
                }
                else if (y == j)
                {
                    ans = max(ans, c[x] + 2 * c[y] - price[x][y]);
                }
                else
                    ans = max(ans, c[x] + c[y] + c[j] - price[x][j] - price[y][j]);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}