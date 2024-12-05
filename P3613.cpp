/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-05 16:09:28
 * @LastEditTime : 2024-12-05 16:13:47
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P3613.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+10;
struct node{
    map<int,int> c;
}box[maxN];
int n,q;
int op,i,j,k;
int main()
{
    cin>>n>>q;
    for(int l=1;l<=q;l++)
    {
        cin>>op;
        switch (op)
        {
        case 1:
            cin>>i>>j>>k;
            if(k==0)
            {
                box[i].c.erase(j);
            }
            else
            {
                box[i].c.insert(make_pair(j,k));
            }
            break;
        case 2:
            cin>>i>>j;
            cout<<box[i].c[j]<<endl;
            break;
        default:
            break;
        }
    }
    return 0;
}