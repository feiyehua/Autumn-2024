/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-10-26 09:06:15
 * @LastEditTime : 2024-10-26 10:24:18
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11314.cpp
 * @     © 2024 FeiYehua
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MOD = 1e9 + 7;
int n;
const int maxN = 2e5 + 10;
int m[maxN];
int a[maxN];
// 一个数组存到上边缘的距离
// 当上下边缘都可以时，该维数对总数贡献为2；
// 只有一边可以时，贡献是1；
// 上下都不行时，说明这个k取值无法取到，贡献为0
// 用乘法原理
/*
只需要写一个优先队列存点的信息：点的最近距离升序，弹出后，该点的贡献为1；
等到“最近值”超过min(max(dimDis[i].up,dimDis[i].down))时，有点的数量贡献为0，程序结束
*/
struct dis
{
    int up, down;
    int min;
};
struct compareDis
{
    bool operator()(const dis &a, const struct dis &b)
    {
        return a.min > b.min;
    }
};

priority_queue<dis, vector<dis>, compareDis> disQueue;
int minEndDis = INT_MAX;
int dimCount; // 记录贡献为2的维度数量；
int ans;
void updateAns(int x)
{
    int tmp = 1;
    for (int i = 1; i <= x; i++)
    {
        tmp *= 2;
        tmp %= MOD;
    }
    ans += tmp;
    ans %= MOD;
    return;
}
int main()
{
    scanf("%d", &n);
    dimCount = n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &m[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        dis dimDis;
        scanf("%d", &a[i]);
        dimDis.up = m[i] - a[i];
        dimDis.down = a[i] - 1;
        dimDis.min = min(dimDis.up,dimDis.down);
        disQueue.push(dimDis);
        minEndDis = min(max(dimDis.up, dimDis.down), minEndDis);
    }
    int start=0;
    while(disQueue.top().min<=minEndDis&&dimCount>0)
    {
        for(int i=start+1;i<=min(disQueue.top().min,minEndDis);i++)
        {
            updateAns(dimCount);
        }
        start=disQueue.top().min;
        dimCount--;
        disQueue.pop();
    }
    ans+=1;
    ans%=MOD;
    cout<<ans;
    return 0;
}