/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-10 16:30:44
 * @LastEditTime : 2024-11-10 17:47:18
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : T454254.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxN=3010;
int n;
struct pt{
    int a,b;
}points[maxN];
int a[maxN][maxN];//第一维表示为从n到下标，第二维为所取数中最大的b；
//从后向前取
//理解错了题意，还是应该考虑从前往后数，但是这样就变成三维大dp了
int k,ans;
bool flagB=0;
bool sel[maxN];
int maxB;
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>points[i].a;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>points[i].b;
        maxB=max(maxB,points[i].b);
        if(points[i].b!=0) flagB=1;
    }
    if(!flagB)
    {
        for(int i=1;i<=n;i++)
        {
            if(points[i].a>0) k++;
        }
        cout<<k<<"\n";
        for(int i=1;i<=n;i++)
        {
            if(points[i].a>0) {cout<<i<<" ";ans+=points[i].a;}
        }
        cout<<"\n";
        cout<<ans;
        return 0;
    }
    else 
    {
        for(int i=1;i<=n;i++)
        {
            if(points[i].a>0) sel[i]=1;
        }
        for(int i=1;i<=maxB;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(points[j].b==i)
                {
                    for(int k=1;k<j;k++)
                    {
                        
                    }
                }
            }
        }
    }
    return 0;
}