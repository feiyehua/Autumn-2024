/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-27 11:22:33
 * @LastEditTime : 2024-11-27 18:24:46
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1044.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int n,ans[20];
int mem[20][20];
int dfs(int a,int b,int x)//表示栈内和操作数序列内的数和总数
{
    
    if(a==0&&b==0)
    {
        ans[x]++;
        return 1;
    }
    if(a==0&&b<x)
    {
        ans[x]+=ans[b];
        return ans[b];
    }
    if(a>0)
    {
        if(mem[a-1][b]!=0)
        {
            mem[a][b]+=mem[a-1][b];
        }
        else 
        {
            mem[a-1][b]=dfs(a-1,b,x);
            mem[a][b]+=mem[a-1][b];
        }
    }
    if(b>0)
    {
        if(mem[a+1][b-1]!=0)
        {
            mem[a][b]+=mem[a+1][b-1];
        }
        else 
        {
            mem[a+1][b-1]=dfs(a+1,b-1,x);
            mem[a][b]+=mem[a+1][b-1];
        }
    }
    return mem[a][b];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        dfs(0,i,i);
    }
    
    //ans[1]=1,ans[2]=2,ans[3]=5
    cout<<mem[0][n];
}