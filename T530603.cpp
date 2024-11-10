/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-10 16:16:10
 * @LastEditTime : 2024-11-10 16:29:12
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : T530603.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6+10;
bool a[maxN];
int cnt[maxN];
int n,q;
int l,r,k;//l,r分别为左右端点；k为目标值
int fr()
{
    char ch;
    int num=0;
    ch=getchar();
    while(isspace(ch)) ch=getchar();
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar();
    }
    return num;
}
int main()
{
    n=fr(),q=fr();
    for(int i=1;i<=n;i++)
    {
        a[i]=fr();
        cnt[i]=a[i]+cnt[i-1];
    }
    for(int i=1;i<=q;i++)
    {
        l=fr(),r=fr(),k=fr();//总共有r-l+1个数
        int ranCnt=cnt[r]-cnt[l]+a[l];//范围中1的个数
        if(k>r-l) {printf("-1\n");continue;}
        else if(k==r-l)//有两种情况：1是将所有的编程1，2是将r-l个变成1
        {
            printf("%d\n",min(r-l+1-ranCnt,abs(ranCnt-(r-l))));
        }
        else printf("%d\n",abs(ranCnt-k));
        //平凡的情况，k是多少个，就需要多少个1
    }
    return 0;
}