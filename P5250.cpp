/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-12 11:25:34
 * @LastEditTime : 2024-11-12 11:41:05
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P5250.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int n;
int op,len;
set<int> a;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>op>>len;
        if(op==1)
        {
            if(a.count(len))
            {
                cout<<"Already Exist\n";
            }
            else
            {
                a.insert(len);
            }
        }
        else
        {
            if(a.empty())
            {
                cout<<"Empty\n";
            }
            else
            {
                if(a.count(len)) 
                {
                    cout<<len<<"\n";
                    a.erase(len);
                }
                else//没有刚好长度的木材
                {
                    auto tmp1=a.lower_bound(len);//返回了第一个大于len元素的迭代器；由于len不存在，所以上一个元素就是第一个小于len的；
                    if(tmp1==a.end())
                    {
                        cout<<*(--tmp1)<<"\n";
                        a.erase(tmp1);
                    }
                    else if(tmp1==a.begin())
                    {
                        cout<<*tmp1<<"\n";
                        a.erase(tmp1);
                    }
                    else 
                    {
                        auto tmp2=tmp1;
                        tmp2--;
                        int len2=*(tmp1),len1=*(tmp2);
                        if(len-len1<=len2-len)//删除前一个元素
                        {
                            cout<<*(tmp2)<<"\n";
                            a.erase(tmp2);
                        }
                        else
                        {
                            cout<<*tmp1<<"\n";
                            a.erase(tmp1);
                        }
                    }
                }
            }
        }
    }
    return 0;
}