/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-15 19:10:25
 * @LastEditTime : 2024-11-15 21:01:48
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : T539827.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=1010;
int n,m;
string ori[maxN];
bool haveWall[maxN];
int aCnt[maxN],bCnt[maxN];
bool rem[maxN][maxN];
void parseWar(int x)
{
    for(int i=0;i<m;i++)
    {
        if(ori[x][i]=='H') haveWall[x]=1;
        if(ori[x][i]=='A') aCnt[x]++;
        if(ori[x][i]=='B') bCnt[x]++;
    }

}
void wallEdi(int x)
{
    int i=0;
    for(;i<aCnt[x];i++)
    {
        ori[x][i]='A';
    }
    while(ori[x][i]!='H')
    {
        ori[x][i]='#';
        i++;
    }
    int j=1;
    for(;j<=bCnt[x];j++)
    {
        ori[x][m-j]='B';
        //cout<<" "<<endl;
    }
    for(int k=i+1;k<m-j+1;k++)
    {
        ori[x][k]='#';
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>ori[i];
        parseWar(i);
        if(haveWall[i])
        {
            wallEdi(i);
        }
        else if(aCnt[i]==bCnt[i])
        {
            for(int j=0;j<m;j++)
            {
                ori[i][j]='#';
            }
        }
        else if(aCnt[i]>bCnt[i])
        {
            for(int j=m-1;j>=(m-aCnt[i]);j--)
            {
                ori[i][j]='A';
            }
            for(int j=0;j<m-aCnt[i];j++)
            {
                ori[i][j]='#';
            }
        }
        else if(bCnt[i]>aCnt[i])
        {
            for(int j=0;j<bCnt[i];j++)
            {
                ori[i][j]='B';
            }
            for(int j=bCnt[i];j<m;j++)
            {
                ori[i][j]='#';
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ori[i][j]=='A'||ori[i][j]=='B')
            {
                if(ori[i-1][j]==ori[i][j]||ori[i+1][j]==ori[i][j]) rem[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(rem[i][j]) ori[i][j]='#';
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ori[i]<<endl;
    }
    return 0;
}