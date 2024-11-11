/***
 * @Author       : FeiYehua
 * @Date         : 2024-10-30 10:03:24
 * @LastEditTime : 2024-11-11 16:46:47
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P2073.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct flower
{
    int w, c;
};
int w, cc;
const int maxN = 1e6 + 10;
bool vis[maxN];
int c[maxN];
// vector<flower> flowers;
struct lessCmp
{
    bool operator()(const flower &a, const flower b) // 实现一个大顶堆
    {
        return a.c < b.c;
    }
};
struct greaterCmp
{
    bool operator()(const flower &a, const flower &b) // 实现一个大顶堆
    {
        return a.c > b.c;
    }
};
priority_queue<flower, vector<flower>, lessCmp> a;    // 大顶堆
priority_queue<flower, vector<flower>, greaterCmp> b; // 小顶堆
//开始的思路为什么会错：假设删除了最小的元素，再加入了相同元素，则大顶堆中会出现问题：不知道哪个是被删除的元素
//使用c数组，存储了每个c对应的w值；如果w值与c不匹配，说明这个是之前已经被删除的节点，应当忽略。
int cnt;
int op;
int fr()
{
    char ch;
    int num = 0;
    int s = 1;
    ch = getchar();
    while (isspace(ch))
    {
        if (ch == '-')
            s = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        num = num * 10 + ch - '0';
        ch = getchar();
    }
    return num * s;
}
signed main()
{

    while (1)
    {
        op = fr();
        while(cnt!=0&&c[a.top().c]!=a.top().w) a.pop();
        while(cnt!=0&&c[b.top().c]!=b.top().w) b.pop();//这时堆顶元素一定是正确的元素
        switch (op)
        {

        case 1:
        {
            flower tmp;
            tmp.w = fr(), tmp.c = fr();
            if (c[tmp.c] == 0)
            {
                a.push(tmp);
                b.push(tmp);
                cnt++, c[tmp.c] = tmp.w;
            }
            break;
        }
        case 2:
        {
            if (cnt == 0)
                break;
            c[a.top().c] = 0;
            a.pop();
            cnt--;
            break;
        }
        case 3:
        {
            if (cnt == 0)
                break;
            c[b.top().c] = 0;
            b.pop();
            cnt--;
            break;
        }
        default:
            goto END;
        }
    }
END:
    // for (int i = 1; i <= cnt; i++)
    // {
    //     w += a.top().w, cc += a.top().c;
    //     a.pop();
    // }
    while(cnt!=0&&c[a.top().c]!=a.top().w) a.pop();
    while(cnt!=0&&c[b.top().c]!=b.top().w) b.pop();//这时堆顶元素一定是正确的元素
    int i=0;
    while(i<cnt)
    {
        while(c[a.top().c]!=a.top().w) a.pop();
        i++;
        w += a.top().w, cc += a.top().c;
        a.pop();
    }
    printf("%lld %lld", w, cc);
    return 0;
}
