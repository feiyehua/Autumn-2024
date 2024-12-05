/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-05 22:33:04
 * @LastEditTime : 2024-12-05 23:31:51
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : D.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>s;
        if(s.size()==1)
        {
            cout<<s<<endl;
        }
        else
        {
            for(int j=1;j<s.size();j++)
            {
                int k=j;
                while(s[k]>1+s[k-1]&&k>0&&s[k]>='2')
                {
                    s[k]-=1;
                    swap(s[k],s[k-1]);
                    k--;
                }
            }
            cout<<s<<endl;
        }
    }
}