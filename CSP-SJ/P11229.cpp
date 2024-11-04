/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-03 23:27:14
 * @LastEditTime : 2024-11-04 12:16:46
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11229.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
//0,1,2,3,4,5,6,7,8,9
//6,2,5,5,4,5,6,3,7,6
//17=5+6+6
int n;
int t;
int main()
{
    //freopen("ans.ans","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        if(n==1)
        {
            cout<<"-1"<<endl;
        }
        else if(n<=7)
        {
            if(n==2) cout<<"1\n";
            if(n==3) cout<<"7\n";
            if(n==4) cout<<"4\n";
            if(n==5) cout<<"2\n";
            if(n==6) cout<<"6\n";
            if(n==7) cout<<"8\n";
        }
        else if(n>14&&n%7==3)
        {
            cout<<"200";
            for(int j=1;j<=(n/7-2);j++)
            {
                cout<<"8";
            }
            cout<<"\n";
            continue;
        }
        else
        {
            //剩下的火柴数量：7-13根
            if(n%7==0) cout<<"8";
            else
            {
                switch(n%7+7)
                {
                    case 8:
                        cout<<"10";
                        break;
                    case 9:
                        cout<<"18";
                        break;
                    case 10:
                        cout<<"22";
                        break;
                    case 11:
                        cout<<"20";
                        break;
                    case 12:
                        cout<<"28";
                        break;
                    case 13:
                        cout<<"68";
                        break;
                    default:
                        break;
                }
            }
            for(int j=1;j<=(n/7-1);j++)
            {
                cout<<"8";
            }
            cout<<"\n";
        }
    }
}
