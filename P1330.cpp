/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-13 08:54:58
 * @LastEditTime : 2024-11-13 09:11:11
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1330.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
#ifdef TEST
const int maxN=30;
#else
const int maxN=1e4+10;
#endif
bool roadMap[maxN][maxN];
int m,n;
int u,v;
int col[maxN];
int getNumber()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        col[i]=-1;
    }
    for(int i=1;i<=n;i++)
    {
        if(col[i]==-1)
        {
            queue<int> q;
            q.push(i);
            col[i]=0;
            int colCnt[2]={1,0};
            while(!q.empty())//开始一个新的节点
            {
                int node=q.front();
                q.pop();
                for(int j=1;j<=n;j++)
                {
                    if(roadMap[node][j])
                    {
                        if(col[j]==-1)
                        {
                            q.push(j);
                            col[j]=!col[node];
                            colCnt[col[j]]++;
                        }
                        else if(col[j]==col[node])
                        {
                            return -1;
                        }
                    }
                }
            }
            ans+=min(colCnt[0],colCnt[1]);
        }
    }
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        roadMap[u][v]=1,roadMap[v][u]=1;
    }
    int ans=getNumber();
    if(ans==-1)
    {
        printf("Impossible");
    }
    else
    {
        printf("%d",ans);
    }
    return 0;
}