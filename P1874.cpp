/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-07 19:28:01
 * @LastEditTime : 2024-11-08 00:03:10
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1874.cpp
 * @     © 2024 FeiYehua
 */
//观察本题数据范围，不难发现最大的求和值不大，可以作为dp的一维。
//另一维是已经求和的长度
#include<bits/stdc++.h>
using namespace std;
int n;
const int maxN=1e5+10;
string s;
int sum[50][50];
int cnt[50][maxN];
int getSum(int l,int r)
{
    int sum=0;
    while(l<=r&&sum<=1e6+10)
    {
        sum=sum*10+s[l]-'0';
        l++;
    }
    return sum;
}
void getStringSum()
{
    for(int i=0;i<s.size();i++)
    {
        for(int j=i;j<s.size();j++)
        {
            sum[i][j]=getSum(i,j);
        }
    }
}
int main()
{
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<maxN;j++)
        {
            cnt[i][j]=1e9;
        }
    }
    cin>>s>>n;
    while(s[0]=='0'&&s.size()>=1) s.erase(0,1);
    if(s.size()==0)
    {
        if(n==0) cout<<"0";
        else cout<<"-1";
        return 0;
    }
    getStringSum();
    //cnt[0][s[0]-'0']=0;//这样只考虑到了在前面1个数后加加号的情况
    cnt[0][0]=-1;
    for(int i=1;i<=s.size();i++)//前i个数字
    {
        for(int j=i-1;j>=0;j--)//我们从第j个位置后开始打加号
        {
            if(sum[j][i-1]>n) break;
            for(int k=sum[j][i-1];k<=n;k++)
            {
                //if(k<sum[j+1][i]) continue;
                cnt[i][k]=min(cnt[i][k],cnt[j][k-sum[j][i-1]]+1);
            }            
        }
    }
    //cout<<cnt[4][36];
    //cout<<cnt[1][9];
    if(cnt[s.size()][n]!=1e9) cout<<cnt[s.size()][n];
    else cout<<"-1";
    return 0;
}