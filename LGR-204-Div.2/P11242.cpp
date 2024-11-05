/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-05 23:14:19
 * @LastEditTime : 2024-11-05 23:23:02
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11242.cpp
 * @     © 2024 FeiYehua
 */
//我们简化题意：每个叶子结点必定使答案增加1；此外，到最深叶子结点上，每个深度都会对答案贡献1，加起来即可获得答案。
#include<bits/stdc++.h>
using namespace std;
int k;
const int maxA=1e5+10;
int maxDepth;
bool vis[maxA];
int ans;
int fr()
{
    char ch;int n=0;
    ch=getchar();
    while(isspace(ch)) ch=getchar();
    while(isdigit(ch))
    {
        n=n*10+ch-'0';
        ch=getchar();
    }
    return n;
}
priority_queue<int,vector<int>,greater<int>> a;
int main()
{
    k=fr();
    for(int i=1;i<=k;i++)
    {
        int tmp=fr();
        maxDepth=max(tmp,maxDepth);
        a.push(tmp);
    }//使用一个单调队列存储数据，从小到大
    ans=maxDepth-1+k;
    cout<<ans<<endl;
    return 0;
}