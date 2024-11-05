/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-05 23:42:20
 * @LastEditTime : 2024-11-06 00:04:15
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11243.cpp
 * @     © 2024 FeiYehua
 */
//我们只需要找到连续的递增/递减区间，求出该区间里面的数字个数x，区间连续相等的数字个数yi，答案为sigma(c(x,2)-sigma(c(y,2)))
//不开long long见祖宗！
#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
string s;
int n;
int ans;
void getConseUp()
{
    int start=0,end=0;
    while (start < s.size() && end < s.size())
    {
        while (s[start] == '>' && start < s.size())
            start++;
        end = start;
        int consEqua=0;
        while (s[end] != '>' && end < s.size())
        {
            if(s[end]!='='&&consEqua)
            {
                int cnt=consEqua+1;
                ans-=(cnt*(cnt-1))/2;
                consEqua=0;
            }
            if(s[end]=='=') consEqua++;
            end++;
            
        }
        if(consEqua)
        {
            int cnt=consEqua+1;
            ans-=(cnt*(cnt-1))/2;
            consEqua=0;
        } 
        int cnt = end - start + 1;
        ans += (cnt * (cnt - 1)) / 2;
        start = end;
    }
}
void getConseDown()
{
    int start=0,end=0;
    while (start < s.size() && end < s.size())
    {
        while (s[start] == '<' && start < s.size())
            start++;
        end = start;
        int consEqua=0;
        while (s[end] != '<' && end < s.size())
        {
            if(s[end]!='='&&consEqua)
            {
                int cnt=consEqua+1;
                ans-=(cnt*(cnt-1))/2;
                consEqua=0;
            }
            if(s[end]=='=') consEqua++;
            end++;
            
        }
        if(consEqua)
        {
            int cnt=consEqua+1;
            ans-=(cnt*(cnt-1))/2;
            consEqua=0;
        } 
        int cnt = end - start + 1;
        ans += (cnt * (cnt - 1)) / 2;
        start = end;
    }
}
signed main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ans=0;
        cin>>n>>s;
        getConseUp();
        getConseDown();
        cout<<ans<<endl;
    }
}