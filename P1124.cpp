/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-06 09:35:33
 * @LastEditTime : 2024-11-06 19:04:55
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1124.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=1e4+10;
int loc[30];//存储某个字母在b中第一次出现的下标；处理之后，更新下标
char a[maxN],b[maxN];//a是原始输入，b是排序后输入
bool cmp(const char& a,const char& b)
{
    return a<b;
}
char result[maxN];
int n,p;
int start;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    cin>>p;
    if(n==1) {cout<<a[1];return 0;}
    sort(b+1,b+1+n,cmp);
    loc[b[n]-'a']=n;
    char cur=b[n];
    for(int i=n-1;i>0;i--)
    {
        if(b[i]==a[p]) start=i;//存第一个字符第一次出现的点，因为相对应的字符串会在同起始字符串中第一个出现
        if(b[i]==cur) continue;
        loc[b[i]-'a']=i,cur=b[i];
    }
    result[1]=a[p],result[2]=b[p];
    cur=a[start];
    result[n]=a[start];
    for(int i=n-1;i>2;i--)
    {
        int locOfFirstLoc=loc[cur-'a'];//最后一个出现这个字符的下标
        result[i]=a[locOfFirstLoc];
        loc[cur-'a']--;
        cur=a[locOfFirstLoc];
    }
    for(int i=1;i<=n;i++)
    {
        cout<<result[i];
    }
    return 0;
}