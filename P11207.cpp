/***
 * @Author       : FeiYehua
 * @Date         : 2024-11-29 13:57:45
 * @LastEditTime : 2024-11-29 15:08:10
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P11207.cpp
 * @     © 2024 FeiYehua
 */
// 考虑统计出每次女方出完牌后牌堆里的三种牌的数量，
// 显然如果总牌数可以被3整除，就可以满足题意；
// 统计换牌次数：换牌次数是总偏移量/2.
// 找出最少的点即可
// 还需要判断：完成更换后，是否会导致男方先获胜？
//
// 不难发现，我们最多只需要操作两次就可以使她获胜：直接修改前三次操作中的两次即可。
// 现在考虑是否有操作0次或者1次的可能性。
// 1次：如果有某次出牌后男方可以获胜，不难发现至少需要操作一次。如果需要使女方获胜，则需要在此后某次女方取牌时偏移量只有1.
// 此后，即使女方能直接获胜，依然也需要2次（即换走、再换回），所以可以直接忽略
// 下面考虑答案为0的情况。发现只能是男方一定无法取胜且女方可以直接获胜。
//
#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int t, n;
string g, b;
int cnt[maxN][5];
int getNum(char c)
{
    switch (c)
    {
    case 'P':
        return 0;
        break;
    case 'V':
        return 1;
        break;
    case 'W':
        return 2;
        break;
    default:
        break;
    }
    return -1;
}
int getDiff(int a, int b, int c)
{
    if ((a + b + c) % 3 != 0)
        return -1;
    int base = (a + b + c) / 3;
    int diff = abs(a - base) + abs(b - base) + abs(c - base);
    return diff;
    // 如果abc和base的差之和为2，则可以使答案更优
}
bool cant[10][10];
int cantCnt;
int getCant(int a, int b, int c)
{
    if (a - b == 2)
    {
        cantCnt += (!cant[1][2]);
        cant[1][2] = 1;
    }
    if (b - a == 2)
    {
        cantCnt += (!cant[2][1]);
        cant[2][1] = 1;
    }
    if (a - c == 2)
    {
        cantCnt += (!cant[1][3]);
        cant[1][3] = 1;
    }
    if (c - a == 2)
    {
        cantCnt += (!cant[3][1]);
        cant[3][1] = 1;
    }
    if (b - c == 2)
    {
        cantCnt += (!cant[2][3]);
        cant[2][3] = 1;
    }
    if (c - b == 2)
    {
        cantCnt += (!cant[3][2]);
        cant[3][2] = 1;
    }

    return cantCnt == 6;
    // assert(0);
}
int can(int a, int b, int c)
{
    // assert(0);
    if (a - b == 2 && cant[1][2] == 0)
    {
        return 1;
    }
    if (b - a == 2 && cant[2][1] == 0)
    {
        return 1;
    }
    if (a - c == 2 && cant[1][3] == 0)
    {
        return 1;
    }
    if (c - a == 2 && cant[3][1] == 0)
    {
        return 1;
    }
    if (b - c == 2 && cant[2][3] == 0)
    {
        return 1;
    }
    if (c - b == 2 && cant[3][2] == 0)
    {
        return 1;
    }
    // assert(0);
    return 0;
}
int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        cin >> g >> b;
        // 先处理第一次出牌
        memset(cnt, 0, sizeof cnt);
        memset(cant, 0, sizeof cant);
        bool flag = 0;
        cnt[0][getNum(g[0])]++;
        int ans = 2;
        cantCnt = 0;
        for (int j = 1; j < n; j++)
        {
            cnt[j][getNum(b[j - 1])]++;
            for (int k = 0; k <= 2; k++)
            {
                cnt[j][k] += cnt[j - 1][k];
            }
            // 如果某次男方diff为2，且之前已经出现过可以取牌获胜的情况，这时候会限制此前能取牌的情况；
            if (flag && (2 * j) % 3 == 0)
            {
                if (getDiff(cnt[j][0], cnt[j][1], cnt[j][2]) == 2)
                {
                    if (getCant(cnt[j][0], cnt[j][1], cnt[j][2])) // 维护不能取到的情况；
                        break;
                }
            }
            if (cnt[j][0] == cnt[j][1] && cnt[j][1] == cnt[j][2])
                flag = 1; // 男方取牌获胜的情况
            cnt[j][getNum(g[j])]++;
            if ((j * 2 + 1) % 3 == 0) // 可能可以实现女方获胜
            {
                if (flag && getDiff(cnt[j][0], cnt[j][1], cnt[j][2]) == 2 && can(cnt[j][0], cnt[j][1], cnt[j][2]))
                {
                    ans = 1;
                }
                if (!flag && getDiff(cnt[j][0], cnt[j][1], cnt[j][2]) == 2)
                {
                    ans = 1;
                }
                if (!flag && getDiff(cnt[j][0], cnt[j][1], cnt[j][2]) == 0)
                {
                    ans = 0;
                    break;
                }
            }
        }
        cout << ans << endl;
        // int ans=INT_MAX;
        // for(int j=1;j<n;j++)
        // {
        //     if(((j)*2+1)%3!=0) continue;
        //     int t=0;
        //     int base=((j)*2+1)/3;
        //     for(int k=0;k<=2;k++)
        //     {
        //         t+=abs(base-cnt[j][k]);
        //     }
        //     if(t%2) continue;
        //     t/=2;
        //     ans=min(ans,t);
        // }
        // cout<<ans<<endl;
    }
    return 0;
}