/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-05 22:32:50
 * @LastEditTime : 2024-12-05 22:41:06
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : A.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
int n, m, t;
string s;
int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> m;
        int cnt = 0;
        bool flag = 0;
        for (int j = 1; j <= n; j++)
        {
            cin >> s;
            if (cnt + s.size() <= m && !flag)
            {
                cnt += s.size();
            }
            else if (flag == 0)
            {
                flag = 1;
                cout << j-1 << endl;
            }
        }
        if(flag==0)
        {
            cout<<n<<endl;
        }
    }
    return 0;
}