/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-13 10:51:44
 * @LastEditTime : 2024-11-13 11:13:16
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P5266.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
map<string, long long> a;
int op;
long long score;
string s;
int n;
int main()
{
    cin>>n;
    while (n--)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> s >> score;
            if (a.count(s))
                a[s] = score;
            else
                a.insert(make_pair(s, score));
            printf("OK\n");
            break;
        case 2:
            cin >> s;
            if (a.count(s))
                printf("%lld\n", a[s]);
            else
                printf("Not found\n");
            break;
        case 3:
            cin >> s;
            if (a.count(s))
            {
                printf("Deleted successfully\n");
                a.erase(s);
            }
            else
                printf("Not found\n");
            break;
        case 4:
            printf("%lu\n", a.size());
            break;
        default:
            break;
        }
        // if (op == 4)
        //     break;
    }
    return 0;
}