/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-11 16:02:50
 * @LastEditTime : 2024-11-11 16:10:08
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P3378.cpp
 * @     © 2024 FeiYehua
 */
/***
 * @Author       : FeiYehua
 * @Date         : 2024-11-11 16:02:50
 * @LastEditTime : 2024-11-11 16:05:07
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P3378.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
bool cmp(const long long& a,const long long& b)
{
    return a<b;
}
priority_queue<long long, vector<long long>,greater<long long> > a;
int n, op, x;
long long fr()
{
    char ch;
    long long num = 0;
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
int main()
{
    n = fr();
    for (int i = 1; i <= n; i++)
    {
        op = fr();
        switch (op)
        {
        case 1:
            x = fr();
            a.push(x);
            break;
        case 2:
            printf("%lld\n", a.top());
            break;
        case 3:
            a.pop();
            break;
        default:
            break;
        }
    }
    return 0;
}