/***
 * @Author       : FeiYehua
 * @Date         : 2024-11-17 10:13:01
 * @LastEditTime : 2024-11-18 19:55:42
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : ship.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
// 相当于是一个追及问题
// 加速会造成一定时间的落后，终点在落后区段内，则该区域不加速合适；其外的区域，加速合适；
// 对于每个加油站点，到达此点的情况是唯一的（即对时间-速度的二元组有最优解）
// 似乎不对，因为每次加速的收益是在此后通用的
// 如果很多点都是在短时看不到收益的区间内，就不好说了
// 预处理时，在每个加油站，更新此后的第一个能够被加速受惠的加油站
// 对每次询问，找到相距最近的加油站，然后判断在该点是否加速即可
// 考虑一个四维大dp
// 从上一个点转移到下一个点（那其实就是三维）
// 考虑到达某点的速度和时间
bool front_flag;
const int N = 1e5;
double tim[N + 1][31][20];
int n, q;
const int maxN = 1e5 + 10;
struct sta
{
    int p, x;
    double t;
} stas[maxN];
int cnt[maxN][6];
int b[maxN];
bool end_flag;
int y;
double ans = 1e9;
double tmp;
inline double myMin(const double& a,const double& b) {return a<b ? a:b;}
// 我的DP思路：以每次到达的加油站转移，分别存储加2倍、3倍、4倍的数量
// 优化：首先注意到加油时间总是1，那么如果速度已经快到了一定程度，那么此后的加油都是没有意义的，所以数组后几维可以只开到35左右
// 2^2=4，所以可以缩减1维，优化空间复杂度（常规来说是会爆内存的）
inline int fr()
{
    char ch;
    int num = 0;
    ch = getchar();
    while (isspace(ch))
        ch = getchar();
    while (isdigit(ch))
    {
        num = num * 10 + ch - '0';
        ch = getchar();
    }
    return num;
}
bool can[50][50];
void getCan()
{
    for(int i=0;i<=30;i++)
    {
        for(int j=0;j<=19;j++)
        {
            if(pow(2,i)*pow(3,j)<1e9) can[i][j]=1;
        }
    }
}
int main()
{
#ifdef TEST
    freopen("/Users/xiong/Documents/CPP/Autumn-2024/MX-S6/ship/ship/ship3.in", "r", stdin);
    freopen("/Users/xiong/Documents/CPP/Autumn-2024/MX-S6/ship/ship/ans.out", "w", stdout);
    cout << (&end_flag - &front_flag) / (1024 * 1024) << endl;
#endif
    getCan();
    n = fr(), q = fr();
    for (register int i = 1; i <= n; i++)
    {
        stas[i].p = fr(), stas[i].t = fr(), stas[i].x = fr();
        b[i] = stas[i].p;
        tim[i][0][0] = (double)stas[i].p;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= 4; j++)
        {
            cnt[i][j] = cnt[i - 1][j];
        }
        cnt[i][stas[i].x]++;
    }

    for (register int i = 2; i <= n; i++)
    {
        for (register int k = 0; k <= myMin(cnt[i - 1][2] + cnt[i - 1][4] * 2, 30); k++)
        {
            //tmp=1<<k;
            for (register int l = 0; l <= myMin(cnt[i - 1][3], 19); l++)
            {          
                if(!can[k][l]) break;     
                tim[i][k][l] = 1e9;
                if (tim[i - 1][k][l] != 0)
                    tim[i][k][l] = myMin(tim[i][k][l], tim[i - 1][k][l] + ((double)stas[i].p - (double)stas[i - 1].p) / (pow(2, k) * pow(3, l)));
                switch (stas[i - 1].x)
                {
                case 2:
                {
                    if (k >= 1)
                        tim[i][k][l] = myMin(tim[i][k][l], tim[i - 1][k - 1][l] + ((double)stas[i].p - (double)stas[i - 1].p) / (pow(2, k) * pow(3, l)) + stas[i - 1].t);
                    break;
                }
                case 3:
                {
                    if (l >= 1)
                        tim[i][k][l] = myMin(tim[i][k][l], tim[i - 1][k][l - 1] + ((double)stas[i].p - (double)stas[i - 1].p) / (pow(2, k) * pow(3, l)) + stas[i - 1].t);
                    break;
                }
                case 4:
                {
                    if (k >= 2)
                        tim[i][k][l] = myMin(tim[i][k][l], tim[i - 1][k - 2][l] + ((double)stas[i].p - (double)stas[i - 1].p) / (pow(2, k) * pow(3, l)) + stas[i - 1].t);
                    break;
                }
                }
            }
        }
    }

    for (int i = 1; i <= q; i++)
    {
        y = fr();
        {
            int loc = lower_bound(b + 1, b + 1 + n, y) - b;
            if (stas[loc].p > y || loc == n + 1)
                loc--;
            ans = 1e9;
            if (stas[loc].p != y)
            {
                for (int k = 0; k <= myMin(cnt[loc - 1][2] + cnt[loc - 1][4] * 2, 30); k++)
                {
                    //tmp=1<<k;
                    for (int l = 0; l <= myMin(cnt[loc - 1][3], 19); l++)
                    {
                        // if (tmp > 1e9)
                        //     break;
                        // tmp *= 3;
                        if(!can[k][l]) break;  
                        ans = myMin(ans, tim[loc][k][l] + ((double)y - (double)stas[loc].p) / (pow(2, k) * pow(3, l)));
                        switch (stas[loc].x)
                        {
                        case 2:
                        {
                            ans = myMin(ans, tim[loc][k][l] + stas[loc].t + ((double)y - (double)stas[loc].p) / (pow(2, k + 1) * pow(3, l)));
                            break;
                        }
                        case 3:
                        {
                            ans = myMin(ans, tim[loc][k][l] + stas[loc].t + ((double)y - (double)stas[loc].p) / (pow(2, k) * pow(3, l + 1)));
                            break;
                        }
                        case 4:
                        {
                            ans = myMin(ans, tim[loc][k][l] + stas[loc].t + ((double)y - (double)stas[loc].p) / (pow(2, k + 2) * pow(3, l)));
                            break;
                        }
                        }
                    }
                }
            }
            else
            {
                for (int k = 0; k <= myMin(cnt[loc - 1][2] + cnt[loc - 1][4] * 2, 30); k++)
                {
                    for (int l = 0; l <= myMin(cnt[loc - 1][3], 19); l++)
                    {
                        if(!can[k][l]) break;  
                        ans = myMin(ans, tim[loc][k][l] + ((double)y - (double)stas[loc].p) / (pow(2, k) * pow(3, l)));
                    }
                }
            }
            printf("%.8lf\n", ans);
        }
    }
    return 0;
}
