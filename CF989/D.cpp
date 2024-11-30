/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-30 23:31:54
 * @LastEditTime : 2024-12-01 00:06:10
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : D.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
// 考虑从最左端、最右端开始考虑
// 如果最左端是0，可以直接移除；
// 是2，可以考虑找到最右端的一个1交换，然后再找到最右端的0交换来，再移除；
// 对于1来说，
// 是1，则分情况考虑：如果已经没有0，则可以移除；（如果移除后没有1，说明这样已经是最优解；如果移除后还有1，说明依旧可以继续操作）
// 否则与最右端的0交换；移除0
// 由于只会：把2放到队末；找到队末的0；找到队末的1；将1放到队尾；
// 所以应该可以用一个优先队列来维护0，1，2的最右位置，只需要额外判断是否已经被在左侧被处理即可；这个问题可以通过单独统计剩余0，1，2解决
int t, n;
const int maxN = 2e5 + 10;
int a[maxN];
int cnt[10];
int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        memset(a, 0, sizeof a);
        cin >> n;
        memset(cnt, 0, sizeof cnt);
        priority_queue<int> loc1, loc2, loc0;
        // loc0.clear();
        // loc1.clear();
        // loc2.clear();
        for (int j = 1; j <= n; j++)
        {
            cin >> a[j];
            cnt[a[j]]++;
            switch (a[j])
            {
            case 0:
                loc0.push(j);
                break;
            case 1:
                loc1.push(j);
                break;
            case 2:
                loc2.push(j);
            default:
                break;
            }
        }
        vector<pair<int, int>> ope;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] == 0)
            {
                cnt[0]--;
                continue;
            }
            else if (a[j] == 1)
            {
                if(cnt[0]>0)
                {
                    int v = loc0.top();
                    loc0.pop();
                    loc1.push(v);
                    ope.push_back(make_pair(j, v));
                    swap(a[j],a[v]);
                    cnt[0]--;
                }
                else cnt[1]--;
            }
            else if(a[j]==2)
            {
                if(cnt[1]>0)
                {
                    int u=loc1.top();
                    loc1.pop();
                    ope.push_back(make_pair(u,j));
                    swap(a[j],a[u]);
                    if(cnt[0]>0)
                    {
                        int u2=loc0.top();
                        loc0.pop();
                        ope.push_back(make_pair(u2,j));
                        swap(a[u2],a[j]);
                        cnt[0]--;
                        loc1.push(u2);
                    }
                    else
                    {
                        cnt[1]--;
                    }
                }
                else 
                {
                    break;
                }
            }
        }
        cout<<ope.size()<<endl;
        for(auto it:ope)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    return 0;
}