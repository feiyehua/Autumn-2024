/***
 * @Author       : FeiYehua
 * @Date         : 2024-11-09 09:03:54
 * @LastEditTime : 2025-02-22 10:38:28
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : buy.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
// 从优惠金额a-b最小的看起，找到优惠金额最大的优惠券
// 用a-b排序物品，优惠起价w排序优惠券，区间查找最大的v
// 使用线段树维护区间最大值
// 找到最大优惠额，用总价减去即可
int n, m;
// 命题人介绍了反悔贪心；
// 同样需要考虑用券给总价格带来的贡献：disc-v，使贡献值达到最大。
// 比如，同样是5 4的优惠券，
// 有5 3
//
int maxDis, sum;
const int maxN = 1e6 + 10;
int minA = maxN, maxW = 0;
long long fr()
{
    char ch;
    long long num = 0LL;
    ch = getchar();
    while (isspace(ch))
        ch = getchar();
    while (isdigit(ch))
    {
        num = num * 10LL + ch - '0';
        ch = getchar();
    }
    return num;
}
struct item
{
    int a, b, disc;
} items[maxN];
struct cop
{
    int w, v; // w起用
    bool operator<(const cop &t) const
    {
        return v < t.v;
    }
    bool operator>(const cop &t) const
    {
        return v > t.v;
    }
} cops[maxN + maxN];
priority_queue<cop, vector<cop>, less<cop>> q;
bool cmpI(const item &a, const item &b)
{
    // if(a.disc!=b.disc)
    // return a.disc<b.disc;
    // else
    return a.a < b.a;
}
bool cmpC(const cop &a, const cop &b)
{
    return a.w < b.w;
}
signed main()
{
#ifndef ONLINE_JUDGE

    freopen("/Users/xiong/Documents/CPP/Autumn-2024/MX-S5/buy/buy6.in", "r", stdin);
    freopen("/Users/xiong/Documents/CPP/Autumn-2024/MX-S5/buy/ans.out", "w", stdout);
#endif
    // cin>>n>>m;
    n = fr(), m = fr();
    for (int i = 1; i <= n; i++)
    {
        items[i].a = fr(), items[i].b = fr();
        items[i].disc = items[i].a - items[i].b;
        sum += items[i].a;
    }
    for (int i = 1; i <= m; i++)
    {
        cops[i].w = fr(), cops[i].v = fr();
    }
    for (int i = m + 1; i <= m + n; i++)
    {
        cops[i].w = items[i - m].a;
        cops[i].v = items[i - m].disc;
    }
    sort(items + 1, items + 1 + n, cmpI);   // 对所有物品排序
    sort(cops + 1, cops + 1 + m + n, cmpC); // 对所有优惠券排序
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        // 对第i个物品用券
        while (cnt <= m + n && items[i].a >= cops[cnt].w)
        {
            q.push(cops[cnt]);
            cnt++;
        }
        if (!q.empty())
        {
            int curMax = q.top().v;
            q.pop();
            maxDis += curMax;
        }
    }
    // assert(sum>0);
    cout << (sum - maxDis) << endl;
    return 0;
}