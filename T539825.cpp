/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-15 20:00:59
 * @LastEditTime : 2024-11-15 20:04:18
 * @LastEditors  : FeiYehua
 * @Description  : 202411F Rise
 * @FilePath     : T539825.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=1010;
int n,m;
string s;
int l,r,k;
int h[maxN];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        char ch;
        ch=getchar();
        while(ch!='\n') ch=getchar();
        cin>>s;
        if(s=="water") 
        {
            cin>>l>>r;
            for(int j=l;j<=r;j++)
            {
                h[j]++;
            }
        }
        else if(s=="rise")
        {
            int cnt=0;
            cin>>l>>r>>k;
            for(int j=l;j<=r;j++)
            {
                if(h[j]>=k) cnt++,h[j]=0;
            }
            cout<<cnt<<endl;
        }
    }
}