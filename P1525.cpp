/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-12 15:52:51
 * @LastEditTime : 2024-11-12 17:49:40
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1525.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
//这题我们考虑二分答案：首先提出一个答案，再考虑答案能否被取到。
//检验能否取到答案的方式是：将任意两个冲突值大于答案的罪犯放入监狱，检验是否有矛盾。
//枚举的次数是logM，排序nlogn，检验n，应该可以通过。
const int maxM=1e6+10;
const int maxN=2e4+10;
int n,m;
struct cri{
    int a,b;
    int c;
}crimes[maxM];
bool vis[maxN];
bool cmp(const cri& cri1,const cri& cri2)
{
    return cri1.c<cri2.c;
}
//bool criMap[maxN][maxN];
long long fr()
{
    char ch;
    long long num=0;
    ch=getchar();
    while(isspace(ch)) ch=getchar();
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar();
    }
    return num;
}
bool isBitp(const vector< vector<int> >& criMap)
{
    vector<int> pts(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        if(pts[i]==-1)//这个节点没有被访问，需要进行bfs
        {
            pts[i]=0;//存储i点颜色
            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for (int j:criMap[node])
                {
                        if(j==0) continue;
                        if (pts[j] == -1)
                        {
                            pts[j]=!pts[node];
                            q.push(j);
                        }
                        else if (pts[j] == pts[node]) return 0;
                    
                }
            }
        }
    }
    return 1;
}
bool check(int x)//检查影响力最大为crimes[x].c时是否可行
{
    int ptc=0;
    memset(vis,0,sizeof vis);
    //memset(criMap,0,sizeof criMap);
    vector< vector<int> > criMap(n+1);//这里用一个二维向量存储图，避免爆内存。存一个4e8的图需要300多M空间，爆掉了；
    //注意不给第二维赋初始值的语法
    for(int i=x+1;i<=m;i++)
    {
        //大于这个值的罪犯，一定不能发生冲突。分别放置在两个监狱里。
        //似乎就是判断是否会出现环。
        //需要判断是否为二分图：如果是二分图，则会发生冲突。
        //二分图中，只能有偶环，因为其中节点可以被交替分为两组。
        //
        if(vis[crimes[i].a]==0) vis[crimes[i].a]=1,ptc++;
        if(vis[crimes[i].b]==0) vis[crimes[i].b]=1,ptc++;
        criMap[crimes[i].a].push_back(crimes[i].b);
        criMap[crimes[i].b].push_back(crimes[i].a);
    }
    return isBitp(criMap);
}
signed main()
{
    int l,r;
    n=fr(),m=fr();
    for(int i=1;i<=m;i++)
    {
        crimes[i].a=fr(),crimes[i].b=fr(),crimes[i].c=fr();
    }
    sort(crimes+1,crimes+1+m,cmp);//此时按照冲突升序排列
    l=0,r=m;
    int mid=(l+r)/2;
    while(l<r)
    {
        mid=(l+r)/2;
        if(check(mid))//可行，考虑更小的取值范围
        {
            r=mid;
            continue;
        }
        else//mid不可行
        {
            l=mid+1;
            continue;
        }
    }
    cout<<crimes[l].c<<endl;
    return 0;
}