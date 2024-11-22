/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-22 19:09:30
 * @LastEditTime : 2024-11-22 22:42:50
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P4447.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
//注意到如果出现了间断，则怎么样都连不上，如此可以将一长段能力值分为若干个小段，再进行处理。
//
int n;
const int maxN=1e5+10;
int a[maxN];
int curStart=1;
struct node{
    int l,r,len;
};
vector<node> b;
vector<int> c;
int minLen=INT_MAX;
int ans=INT_MAX;
int cnt[maxN];
void add(int *end)//在end后加入一个新元素
{
    (*end)++;
    cnt[*end]++;
    return;
}
void remove(int *start)
{
    ans=min(ans,cnt[*start]);
    (*start)++;
    return;
}
void update(int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        cnt[i]++;
    }
    return;
}
void getAns()
{
    //每一段应该保持对应点的原本总个数单调不减
    //想象一个队列结构，每次多加一个点时，队列中元素+1；
    //当点个数不变时，所有元素+1，表示长度+1；
    //当点个数减小时，移除队首的元素
    memset(cnt,0,sizeof(cnt));
    int start=1;
    int end=0;
    for(int i=1;i<=c[0];i++) 
    {
        add(&end);
    }
    for(int i=1;i<c.size();i++)
    {
        if (c[i - 1] > c[i])
        {
            for (int j = 1; j <= c[i - 1] - c[i]; j++)
            {
                remove(&start);
            }
            update(start,end);
        }
        else if (c[i] == c[i - 1])
            update(start, end);
        else //c[i - 1] < c[i]
        {
            update(start,end);
            for (int j = 1; j <= c[i] - c[i - 1]; j++)
            {
                add(&end);
            }
        }
    }
    for(int i=start;i<=end;i++)
    {
        ans=min(ans,cnt[i]);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(n==1)
    {
        cout<<"1"<<endl;
        return 0;
    }
    sort(a+1,a+1+n);
    c.push_back(1);
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]>1) 
        {
            getAns();
            c.clear();
            c.push_back(1);
            continue;
        }
        if(a[i]==a[i-1])
        {
            (*(c.end()-1))++;
        }
        else 
        {
            c.push_back(1);
        }
    }
    getAns();
    cout<<ans<<endl;
    return 0;
}