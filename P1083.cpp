/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-10-25 10:58:11
 * @LastEditTime : 2024-10-25 11:36:17
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1083.cpp
 * @     © 2024 FeiYehua
 */
#include<iostream>
#include<cstring>
using namespace std;

int n,m;
const int maxM=1e6+10;
struct rentInfo{
    int d,s,t;
}rents[maxM];
int r[maxM];
int diff[maxM];//存储下标天数与上一天可用教室数量的差值
bool isOK(int pos)
{
    memset(diff,0,sizeof(diff));
    //维护初始值
    for(int i=1;i<=n;i++)
    {
        diff[i]=r[i]-r[i-1];
    }
    for(int i=1;i<=pos;i++)
    {
        diff[rents[i].s]-=rents[i].d;
        diff[rents[i].t+1]+=rents[i].d;
    }
    for(int i=1,tmp=0;i<=n;i++)
    {
        tmp+=diff[i];
        if(tmp<0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    scanf(" %d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf(" %d",&r[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf(" %d %d %d",&rents[i].d,&rents[i].s,&rents[i].t);
    }
    if(isOK(m))
    {
        cout<<"0";
        return 0;
    }
    else
    {
        int start=1,end=m;
        int mid=(start+end)/2;
        while(start!=end)
        {
            mid=(start+end)/2;
            if(isOK(mid))
            {
                start=mid+1;
            }
            else
            {
                end=mid;
            }
        }
        cout<<"-1"<<endl<<end;
        return 0;
    }
}