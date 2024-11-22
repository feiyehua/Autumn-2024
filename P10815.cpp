/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-21 11:28:39
 * @LastEditTime : 2024-11-21 11:37:48
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P10815.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
int fr()
{
    int num=0;
    int w=1;
    char ch;
    ch=getchar_unlocked();
    while(isspace(ch)||ch=='-')
    {
        if(ch=='-') w=-1;
        ch=getchar_unlocked();
    }
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar_unlocked();
    }
    return w*num;
}
int n;
int ans;
signed main()
{
    n=fr();
    for(int i=1;i<=n;i++)
    {
        ans+=fr();
    }
    cout<<ans;
    return 0;
}