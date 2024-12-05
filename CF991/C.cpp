/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-05 22:32:56
 * @LastEditTime : 2024-12-05 23:02:22
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : c.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int n,t;
string s;
int cnt[50];
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>s;
        int num=0;
        memset(cnt,0,sizeof cnt);
        for(int j=0;j<s.size();j++)
        {
            num+=s[j]-'0';
            num%=9;
            cnt[s[j]-'0']++;
        }
        if(num==0) 
        {
            cout<<"yes\n";
        }
        else
        {
            switch(num)
            {
                case 1:
                    if(cnt[1]!=0||(cnt[2]>=1&&cnt[3]>=1)||cnt[2]>=13)
                    {
                        cout<<"yes\n";
                    }
                    else cout<<"NO\n";
                    break;
                case 2:
                    if(cnt[1]>=2||cnt[2]>=8||(cnt[1]>=1&&cnt[2]>=2)||)
            }
        }
    }
    return 0;
}