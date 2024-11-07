/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-07 08:55:21
 * @LastEditTime : 2024-11-07 09:02:19
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P4715.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int n,num;
int powVal[300];
int getWinner(int l,int r)
{
    if(r-l<=1) return(powVal[l]>powVal[r]? l:r);
    else 
    {
        int mid=(l+r)/2;
        int lw=getWinner(l,mid);
        int rw=getWinner(mid+1,r);
        return(powVal[lw]>powVal[rw]?lw:rw);
    }
}
int main()
{
    scanf("%d",&n);
    num=pow(2,n);
    for(int i=1;i<=num;i++)
    {
        scanf("%d",&powVal[i]);
    }
    int lw=getWinner(1,num/2);
    int rw=getWinner(num/2+1,num);
    cout<<(powVal[lw]<powVal[rw]?lw:rw);
    return 0;
}