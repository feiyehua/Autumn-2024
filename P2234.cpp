/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-28 11:10:02
 * @LastEditTime : 2024-11-28 11:20:35
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P2234.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
set<int> s;
int n,a;
int ans;
int main()
{
    cin>>n;
    cin>>a;
    s.insert(a);
    ans+=a;
    for(int i=2;i<=n;i++)
    {
        cin>>a;
        auto it=s.lower_bound(a);
        if(it==s.end())
        {
            ans+=abs(*(--s.end())-a);
            s.insert(a);
            continue;
        }
        if(it==s.begin())
        {
            ans+=abs(*(s.begin())-a);
            s.insert(a);
            continue;
        }
        auto last=it;
        last--;
        ans+=min(abs(*it-a),abs(*(last)-a));
        s.insert(a);
    }
    cout<<ans<<endl;
    return 0;
}