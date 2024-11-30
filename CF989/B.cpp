/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-30 22:54:27
 * @LastEditTime : 2024-11-30 23:02:06
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : B.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
int t, n, m, k;
string s;
int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> m >> k >> s;
        // for(int j=1;j<=)
        int cnt = 0;
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '0')
                cnt++;
            if (s[j] == '1')
                cnt = 0;
            if (cnt == m)
            {
                ans++;
                for (int l = j; l < j + k&&l<n; l++)
                {
                    s[l] = '1';
                }
                cnt=0;
            }
        }
        cout << ans << endl;
    }
}