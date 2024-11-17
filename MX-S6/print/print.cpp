/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-17 09:09:42
 * @LastEditTime : 2024-11-17 21:03:48
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : print.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
#ifndef TEST
const int maxN=2e5+10;
#else
const int maxN=2e5+10;
#endif
struct fil{
    int s,t;
    int num;
}priFil[maxN];
struct task{
    int t,num;
    bool operator()(const task& a,const task& b)
    {
        if(a.t!=b.t)
        return a.t>b.t;
        else return a.num>b.num;
    }
};
int m,n;
bool filCmp(const fil& a,const fil& b)
{
    return a.t<b.t;
}
vector< vector<int> > priInfo(maxN+1);
priority_queue<int,vector<int>,greater<int> > printer;//存储可用的打印机
priority_queue<task,vector<task>,task > endTime;//存储打印机任务结束时间
int fr()
{
    char ch;
    int num=0;
    ch=getchar();
    while(isspace(ch)) ch=getchar();
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar();
    }
    return num;
}
signed main()
{
    #ifdef TEST
    freopen("/Users/xiong/Documents/CPP/Autumn-2024/MX-S6/print/print/print2.in","r",stdin);
    freopen("/Users/xiong/Documents/CPP/Autumn-2024/MX-S6/print/print/ans.out","w",stdout);
    #endif
    n=fr(),m=fr();
    for(int i=1;i<=m;i++) printer.push(i);
    for(int i=1;i<=n;i++)
    {
        priFil[i].s=fr(),priFil[i].t=fr();
        priFil[i].num=i;
    }
    sort(priFil+1,priFil+1+n,filCmp);
    
    for(int i=1;i<=n;i++)
    {
        task tmp;
        while(!endTime.empty()&&endTime.top().t<=priFil[i].t)
        {
            printer.push(endTime.top().num);
            endTime.pop();
        }
        //这里有坑：如果可用的打印机已经空了，就需要等待最先打完的打印机
        if (printer.empty())
        {
            priFil[i].t=endTime.top().t;
            printer.push(endTime.top().num);
            endTime.pop();
        }
        tmp.num = printer.top();
        printer.pop();
        tmp.t=priFil[i].t+priFil[i].s;
        endTime.push(tmp);
        priInfo[tmp.num].push_back(priFil[i].num);
    }
    for(int i=1;i<=m;i++)
    {
        if(priInfo[i].empty())
        {
            cout<<"0\n";
        }
        else
        {
            cout<<priInfo[i].size();
            sort(priInfo[i].begin(),priInfo[i].end());
            for(int j=0;j<priInfo[i].size();j++)
            {
                cout<<" "<<priInfo[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}