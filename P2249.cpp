/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-10-25 09:42:21
 * @LastEditTime : 2024-10-25 10:35:57
 * @LastEditors  : FeiYehua
 * @Description  : #
 * @FilePath     : P2249.cpp
 * @     © 2024 FeiYehua
 */
#include<iostream>
using namespace std;
int n,m;
const int maxNumberOfN=1e6+10;
int a[maxNumberOfN];
int fastRead()
{
    char ch=getchar();
    int x=0;
    while(ch>'9'||ch<'0')
    {
        ch=getchar();
    }
    while(ch<='9'&&ch>='0')
    {
        x=x*10+(int)(ch-'0');
        ch=getchar();
    }
    return x;
}
/*int* myLowerBound(int* begin,int* end,int num)//针对从小到大的数组，找到第一个取大于等于的下标
{
//
    if(*begin>=num)//这样写会导致找到的不是“第一个”
    {
        return begin;
    }
    if(*end<=num)
    {
        return end;
    }
    //
    if(begin==end)
    {
        return end;
    }
    int* mid=begin+(end-begin)/2;
    int* x=myLowerBound(begin,mid,num);
    if(*x>=num)
    {
        return x;
    }
    return myLowerBound(mid+1,end,num);
}*/
//标准库中，lowerbound取等号，upperbound不取等号
int myLowerBound(int a[],int l,int r,int num)//针对从小到大的数组，找到第一个取大于等于的下标
{
    if(l==r)
    {
        if(a[l]==num)
        {
            return l;
        }
        return -1;
    }
    int mid=(l+r)/2;
    if(a[mid]>=num)
    {
        return myLowerBound(a,l,mid,num);
    }
    else return myLowerBound(a,mid+1,r,num);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        a[i]=fastRead();
    }
    for(int i=1;i<=m;i++)
    {
        int num;
        cin>>num;
        int place=myLowerBound(a,1,n,num);
        printf("%d ",place);
    }
    return 0;
}