
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
const int maxNumberOfN = 1e6 + 10;
int a[maxNumberOfN];
int fastRead()
{
    char ch = getchar();
    int x = 0;
    while (ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
    {
        x = x * 10 + (int)(ch - '0');
        ch = getchar();
    }
    return x;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        a[i] = fastRead();
    }
    for (int i = 1; i <= m; i++)
    {
        int num;
        cin >> num;
        int place = lower_bound(a + 1, a + n, num) - (a);
        if (a[place] == num)
        {
            printf("%d ", place);
        }
        else
        {
            printf("-1 ");
        }
    }
    return 0;
}