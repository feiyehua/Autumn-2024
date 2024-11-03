/***
 * @Author       : FeiYehua
 * @Date         : 2024-11-03 21:27:25
 * @LastEditTime : 2024-11-03 22:39:10
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P11227.cpp
 * @     © 2024 FeiYehua
 */
#include "bits/stdc++.h"
using namespace std;
bool a[60][60];
int n;
int table1(char a)
{
    if (a == 'D')
    {
        return 1;
    }
    if (a == 'C')
    {
        return 2;
    }
    if (a == 'H')
    {
        return 3;
    }
    if (a == 'S')
    {
        return 4;
    }
    return 0;
}
int table2(char a)
{
    switch (a)
    {
    case ('A'):
        return 1;
        break;
    case ('T'):
        return 10;
        break;
    case ('J'):
        return 11;
        break;
    case ('Q'):
        return 12;
    case ('K'):
        return 13;
    default:
        return a - '0';
        break;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        a[table2(s[1])][table1(s[0])] = 1;
        char ch = getchar();
        while (ch != '\n')
        {
            ch = getchar();
        }
    }
    auto cnt = 0;
    for (int i = 1; i <= 13; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (a[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}