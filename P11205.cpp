/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-28 17:10:10
 * @LastEditTime : 2024-11-28 23:40:30
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11205.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
//如果这个数量的花朵出现了多次，那么是可以取的；
//如此可以求出无论如何都能取的总花瓣数量，并对花瓣数量去重
//一部分来自前面的连续部分，一部分来自后面的间断部分
//现在可以将花瓣堆分成两个部分：第一部分是前面连续的n堆；第二部分是出现间断后的堆。
//从后往前取花，显然在尾部取至多一堆花就能补上至少一个空缺点；
//可以有两种选择：取或者不取；
//不取当且仅当：
//可以进行“收缩”操作，尽量每次在后一堆取完后，数量前一堆数量+1，如此可以达到答案下界a+1，其中a是给出花瓣中数量不重复的个数
//至于答案是否能增加：可以继续对剩下的花瓣“收缩”，收缩到无法收缩时即得答案。
//如果剩下的某堆花瓣数量太少，则最多可以将其取到只剩一个花瓣
//这里有一个问题，就是遇到重复元素时具体怎么处理。既可以接在下一个后处理，也可以留到下一轮再操作。
//如果收缩较多，显然可以直接留到下一轮；（但是这里也接着处理掉，是不是也可以？）
//如果收缩较少，就在当前轮处理完似乎更加合适
//不开long long见祖宗！
const int maxN=1e5+10;
int t,n;
int a[maxN];
int fr()
{
    int num=0;
    char ch;
    ch=getchar_unlocked();
    while(isspace(ch)) ch=getchar_unlocked();
    while(isdigit(ch)) 
    {
        num=num*10+ch-'0';
        ch=getchar_unlocked();
    }
    return num;
}
signed main()
{
    t=fr();
    for(int i=1;i<=t;i++)
    {
        memset(a,0,sizeof a);
        n=fr();
        for(int j=1;j<=n;j++)
        {
            a[j]=fr();
        }
        // if(n==1)
        // {
        //     if(a[1]==3) cout<<"3\n";
        //     else cout<<"2\n";
        //     continue;
        // }
        sort(a+1,a+1+n);
        //]
        int s=0;//可以随意支配的花瓣数量
        int ans=0;
        int m=0;//必须要分出的数量
        for(int j=1;j<=n;j++)
        {
            if(a[j]!=a[j-1]+1&&a[j]!=a[j-1])//出现了中断；
            {
                m+=a[j]-a[j-1]-1;
                a[j]=a[j-1]+1;
                ans++;
            }
            else if(a[j]==a[j-1])
            {
                s+=a[j]-1;
            }
            else
            {
                ans++;
            }
        }
        if(m<=a[n]+1&&m+s>=a[n]+1)
        {
            ans++;
        }
        //if((m+s)==(a[n]+1+a[n]+2)) ans++;
        cout<<ans+1<<endl;
    }
    return 0;
}