/***
 * @Author       : FeiYehua
 * @Date         : 2024-11-24 08:30:16
 * @LastEditTime : 2024-11-24 08:43:04
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : card.cpp
 * @     © 2024 FeiYehua
 */

#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
首先考虑vi小于等于2的情况，显然直接出单张和对子就可以了。
考虑vi小于等于3.显然尽量出3带1是更优解。此后有三带1剩余和不剩余两种情况。如果不剩余，就退化到了情况vi小于等于2时；如果剩余，就尽量出对子即可。
考虑vi更大的情况。
发现出四张其实与出三代一等价，只不过带的是同种牌而已。也就是说，只要有一堆牌有3个，就一定可以跟其他堆一起组合出出去。
所以将每一种牌尽量按每组三张分开，之后会剩下0/1/2张，这样就退化到了之前vi小于等于3的情况。
*/
//这题思维难度有点大qaq
const int maxN=3e5+10;
int t,n,v;
int cnt[10];
signed main()
{
#ifdef TEST
    freopen("./card/card4.in", "r", stdin);
    freopen("./card/out.ans", "w", stdout);
#endif
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        memset(cnt,0,sizeof cnt);//多测不清空见祖宗
        for(int j=1;j<=n;j++)
        {
            cin>>v;
            cnt[v%3]++;
            cnt[3]+=v/3;
        }
        if(cnt[3]==0)
        {
            cout<<cnt[2]+cnt[1]<<endl;
        }
        else
        {
            if(cnt[3]<=cnt[1])//3的堆太少了没办法解决完所有
            {
                cout<<cnt[2]+cnt[1]<<endl;
            }
            else if((cnt[3]-cnt[1])<=cnt[2]*2)//一个两个的堆需要解决两次；这是用不完2的堆的情况
            {
                if((cnt[3]-cnt[1])%2==0)//可以将某一个2堆消耗完
                {
                    cout<<cnt[1]+(cnt[3]-cnt[1])+cnt[2]-(cnt[3]-cnt[1])/2<<endl;
                }
                else cout<<cnt[3]+cnt[2]-(cnt[3]-cnt[1])/2<<endl;//似乎两种表达式其实是相同的……
            }
            else 
            {
                cout<<cnt[1]+cnt[2]*2+((cnt[3]-cnt[1]-2*cnt[2])*3)/4+(((cnt[3]-cnt[1]-2*cnt[2])*3)%4)/2+(((cnt[3]-cnt[1]-2*cnt[2])*3)%4)%2<<endl;
            }
        }
    }
    return 0;
}









#if 0
// 只要超过了四张，出炸一定划算。假的。
// 所以题目就弱化到了vi小于等于3的情况。显然此时要尽量多出三代一，然后尽量多出2，以此类推。
// 如，即使有4+1的情况，出三代一和炸+单排也是同样优秀的。
// 8+8+1+1:
// 5+1 三代一+双更加优秀，这种应该是唯一弱化的情况
// 6+1 三代一 3，四+双+单 3；
// 7+1 三代一+四
// 4+1 同样优秀
// 8+1
// 单独的2 最好情况是找后面两组3来带走
// 2+3+6
// 4+5 3次
// 2+4 2次，2+4；
// 2+5 3次，2+1+4
// 2+6 2次
// 2+7 3次
// 2+8 3次
// 2+9
// 5+5+5 15/4=3余3，5次？ 好像确实
// 试一下这样行不行
// 只统计1、2的个数；此后的求和除4；
// 特殊情况

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxN = 3e5 + 10;
int fr()
{
    int num = 0;
    char ch;
    ch = getchar_unlocked();
    while (isspace(ch))
        ch = getchar_unlocked();
    while (isdigit(ch))
    {
        num = num * 10 + ch - '0';
        ch = getchar_unlocked();
    }
    return num;
}
int n, t;
int cnt[10];
priority_queue<int, vector<int>> v;
signed main()
{
#ifdef TEST
    freopen("./card/card3.in", "r", stdin);
    freopen("./card/out.ans", "w", stdout);
#endif
    t = fr();
    for (int i = 1; i <= t; i++)
    {
        n = fr();
        while(!v.empty()) v.pop();
        int ans = 0;
        if (n == 1)
        {
            auto tmp = fr();
            ans = (tmp / 4) + ((tmp % 4) / 2) + (tmp % 4) % 2;
            cout << ans << "\n";
        }
        // else if(n==2)
        // {
        //     auto tmp1=fr();
        //     auto tmp2=fr();

        // }
        else
        {
            for (int j = 1; j <= n; j++)
            {
                // v.push_back(fr());
                //  ans += v[i] / 4;
                //  v[i] %= 4;
                //  cnt[v[i]]++;
                auto tmp = fr();
                if (tmp <= 2)
                {
                    cnt[tmp]++;
                }
                else
                    v.push(tmp);
            }
            while (v.size() != 0 && !(cnt[1] == 0 && cnt[2] == 0))
            {
                while (v.size() != 0 && cnt[1] != 0)
                {
                    int tmp = (v.top() ) - 3;
                    cnt[1]--;
                    ans++;
                    if (tmp <= 2)
                    {
                        cnt[tmp]++;
                        v.pop();
                    }
                }
                while (v.size() != 0 && cnt[2] != 0)
                {
                    int top=v.top();
                    if ( top >= 6)
                    {
                        top -= 6;
                        cnt[2]--;
                        ans+=2;
                        v.pop();
                        if (top >=3) v.push(top);
                        else cnt[top]++;
                        continue;
                    }
                    if(top>=3)
                    {
                        top-=3;
                        v.pop();
                        cnt[top]++;
                        cnt[2]--;
                        cnt[1]++;
                        ans++;
                        break;
                    }
                }
            }
            int tmp=0;
            while(!v.empty())
            {
                tmp+=v.top();
                v.pop();
            }
            ans+=(tmp / 4) + ((tmp % 4) / 2) + (tmp % 4) % 2;
            ans+=cnt[1]+cnt[2];
            cout<<ans<<endl;
        }
    }
    return 0;
}
#endif
#if 0
const int maxN = 3e5 + 10;
int n, t;
vector<int> v;

int ans;
int fr()
{
    int num = 0;
    char ch;
    ch = getchar_unlocked();
    while (isspace(ch))
        ch = getchar_unlocked();
    while (isdigit(ch))
    {
        num = num * 10 + ch - '0';
        ch = getchar_unlocked();
    }
    return num;
}
int main()
{
#ifdef TEST
    freopen("./card/card3.in", "r", stdin);
    freopen("./card/out.ans", "w", stdout);
#endif
    t = fr();
    for (int j = 1; j <= t; j++)
    {
        n = fr();
        ans = 0;
        
        sort(v,v+n);
        while (!v.size() == 0 || !(cnt[1] == 0 && cnt[2] == 0))
        {
            while (v.size() != 0 && cnt[1] != 0)
            {
                *(v.end() - 1) -= 3;
                cnt[1]--;
                ans++;
                if (*(v.end() - 1) <= 2)
                {
                    cnt[*(v.end() - 1)]++;
                    v.pop_back();
                }
            }
            while(v.size()!=0&&cnt[2]!=0)
            {
                if(*(v.end() - 1)>=6)
                {
                    *(v.end() - 1)-=6;
                    cnt[2]--;
                    ans++;
                    if(*(v.end() - 1)<=6)
                }
                *(v.end() - 1)-=3;
                cnt[1]--;
                ans++;
                if (*(v.end() - 1) <= 2)
                {
                    cnt[*(v.end() - 1)]++;
                    v.pop_back();
                }
            }
        }
        // while (v.size() != 0)
        // {
        //     while (*(v.end() - 1) < 3)
        //     {
        //         cnt[*(v.end() - 1)]++;
        //         v.pop_back();
        //     }//处理落单的1，2；
            
        //     
        // }
    }
}
#endif
#if 0
int main()
{
#ifdef TEST
    freopen("./card/card3.in", "r", stdin);
    freopen("./card/out.ans", "w", stdout);
#endif
    t = fr();
    for (int j = 1; j <= t; j++)
    {
        n = fr();
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            v[i] = fr();
            ans += v[i] / 4;
            v[i] %= 4;
            cnt[v[i]]++;
        }
        // 下面的至少可以解决vi均小于等于3的情况……
        if (cnt[3] == 0)
        {
            ans += cnt[2] + cnt[1];
            cout << ans << endl;
        }
        else if (cnt[3] == cnt[1])
        {
            ans += cnt[1];
            cnt[3] = 0, cnt[1] = 0;
            ans += cnt[2];
            cout << ans << endl;
        }
        else if (cnt[3] > cnt[1])
        {
            ans += cnt[1];
            cnt[3] -= cnt[1];
            cnt[1] = 0;
            // 这个情况下，还剩了一堆三张、一堆两张。
            // 显然尽量依旧出三代一更划算。
            if (cnt[3] <= cnt[2] * 2)
            {
                ans += cnt[3];
                ans += (cnt[2] - cnt[3] / 2 + (cnt[3] % 2 > 0));
                cout << ans << endl;
            }
            else //cnt3有余
            {
                ans += cnt[2] * 2;
                cnt[3] -= cnt[2] * 2;
                ans += cnt[3] / 2 *2 + (cnt[3]%2)*2;
                cout << ans << endl;
            }
        }
        else
        {
            ans += cnt[3];
            cnt[1] -= cnt[3];
            ans += cnt[1] + cnt[2];
            cout << ans << endl;
        }
    }

    return 0;
}
#endif