/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-08 23:48:25
 * @LastEditTime : 2024-11-08 23:55:47
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1007.cpp
 * @     © 2024 FeiYehua
 */
//什么物理题……两个士兵碰撞后“交换人生”，太吴潇啦！别看士兵转向挺吓人，其实发现只是“交换人生”之后很简单
#include<bits/stdc++.h>
using namespace std;
const int maxN=5e3+10;
bool a[maxN];
int l,n;
int minAns,maxAns;
int main()
{
    cin>>l>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        a[t]=1;
    }
    for(int i=1;i<=l;i++)
    {
        if(a[i])
        {
            minAns=max(minAns,min(i,l+1-i));
            maxAns=max(maxAns,max(i,l+1-i));
        }
    }
    cout<<minAns<<" "<<maxAns;
    return 0;
}