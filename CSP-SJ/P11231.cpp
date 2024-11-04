/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-04 19:26:39
 * @LastEditTime : 2024-11-04 20:44:47
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11231.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxR=1e5+10;
int n;
int maxRInData=-1e9;
int minRInData=1e9;
struct card{
    int cnt;
    int total;
}cards[maxR];
int total=0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./Autumn-2024/CSP-SJ/duel/duel4.in", "r", stdin);
    freopen("./Autumn-2024/CSP-SJ/duel/ans.ans", "w", stdout);
#endif
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int r;
        cin>>r;
        maxRInData=max(maxRInData,r);
        minRInData=min(minRInData,r);
        cards[r].cnt++;
    }
    int last=minRInData;
    cards[minRInData].total=cards[minRInData].cnt;
    for(int i=minRInData+1;i<=maxRInData;i++)
    {
        if(cards[i].cnt!=0)
        {
            cards[i].total=max(0,cards[last].total-cards[i].cnt)+cards[i].cnt;
            last=i;
        }
    }
    cout<<cards[maxRInData].total<<endl;
}
#if 0
#include<bits/stdc++.h>
using namespace std;
const int maxR=1e5+10;
int n;
int maxRInData=-1e9;
int minRInData=1e9;
//手搓链表
//每次向最近的一个决斗，较小的退出决斗，数量-1；
struct card{
    int cnt;
    int next;
    int pri;
    int dueled;
}cards[maxR];
int ans;
void updateList()
{
    int last=minRInData;    
    for(int i=minRInData+1;i<=maxRInData;i++)
    {
        if(cards[i].cnt!=0)
        {
            cards[i].pri=last,cards[last].next=i;
            last=i;
        }
    }
}
void duel(int i)//战斗力i决斗
{
    if(cards[i].cnt<=0||cards[i].pri==0)
    {
        return;
    }
    int pri=cards[i].pri;
    while (cards[i].dueled < cards[i].cnt)
    {
        cards[i].dueled++;
        cards[pri].cnt--;
        if (cards[pri].cnt == 0)
        {
            cards[cards[pri].next].pri = cards[pri].pri;
            pri=cards[pri].pri;
            cards[cards[pri].pri].next = cards[pri].next;
            if(pri==0) return;
        }
    }
}
int main()
{

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int r;
        cin>>r;
        maxRInData=max(maxRInData,r);
        minRInData=min(minRInData,r);
        cards[r].cnt++;
    }
    updateList();
    int curR=minRInData;
    while(curR<=maxRInData&&curR>0)//从前往后决斗
    {
        duel(curR);
        curR=cards[curR].next;
    }
    for(int i=minRInData;i<=maxRInData;i++)
    {
        ans+=cards[i].cnt;
    }
    cout<<ans<<endl;
    return 0;
}
#endif
