/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-10-24 23:45:54
 * @LastEditTime : 2024-10-25 00:04:28
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11213.cpp
 * @     © 2024 FeiYehua
 */
#include<iostream>
using namespace std;
int maxLen,subMaxLen;
int n;
void updateMaxLenAndSubMaxLen(int x)
{
    if(x<=subMaxLen)
    {
        return;
    }
    else if(x>subMaxLen&&x<=maxLen)
    {
        subMaxLen=x;
        return;
    }
    else if(x>maxLen)
    {
        subMaxLen=maxLen;
        maxLen=x;
        return;
    }
}
int main()
{
    //freopen("bamboo/bamboo3.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a=0,b=0;
        cin>>a>>b;
        b=max(b,a-b);
        updateMaxLenAndSubMaxLen(b);
        updateMaxLenAndSubMaxLen(a-b);
    }
    cout<<maxLen+subMaxLen<<endl;
    return 0;
}