/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-05 22:32:56
 * @LastEditTime : 2024-12-06 00:37:20
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : c.cpp
 * @     © 2024 FeiYehua
 */
/***
 * @Author       : FeiYehua
 * @Date         : 2024-12-05 22:32:56
 * @LastEditTime : 2024-12-06 00:34:03
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : c.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
int n, t;
string s;
int cnt[50];
bool getAns(int num)
{
    for (int j = 0; j <= min(20,cnt[2]); j++)
    {
        for (int k = 0; k <= min(20,cnt[3]); k++)
        {
            int p = (k * 6) % 9 + (j * 2) % 9;
            p %= 9;
            p +=  num;
            if (p % 9 == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> s;
        int num = 0;
        memset(cnt, 0, sizeof cnt);
        for (int j = 0; j < s.size(); j++)
        {
            num += s[j] - '0';
            num %= 9;
            cnt[s[j] - '0']++;
        }
        if (num == 0)
        {
            cout << "yes\n";
        }
        else
        {
            if(getAns(num)) cout<<"yes\n";
            else cout << "no\n";
        }
    }
    return 0;
}