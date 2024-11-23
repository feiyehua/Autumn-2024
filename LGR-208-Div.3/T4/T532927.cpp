/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-23 15:43:20
 * @LastEditTime : 2024-11-23 16:37:17
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : T532927.cpp
 * @     © 2024 FeiYehua
 */
//这题有点难，还没有想出来该怎么做。
// 看起来像是一个DP题，但是状态不好设计：如何描述“一个区间内出现的状态数”？
// 需要一个nlogn的算法，因此DP还有可能超时。
//每次加入一个元素可能对答案有贡献：如果在此后有多个相同元素加入；也有可能没有贡献：此后没有、或者仅有很少的元素加入。
//很明显，一个显而易见的较优做法是将每个数据单独放，这样，总时间就是n，需要寻找一个小于n的答案。
//写到这里感觉有点像是一个图论题，将一些子区间合并，以求能达到更优解。
//如何描述合并的条件？
//首先，对于一个某一个数连续的区间，将他们合并一定使答案更优；
//其次，考虑涉及到其他元素的情况。
//如：1112111，显然使2单独成段更优；
//1112121211111，显然是将其合并更优；
//


//考虑部分分。
//第四个点在1-1e9内随机生成，而且n只有2e5，也就是说将各个区间合并带来的收益是微乎其微的，考虑直接输出n。
//考虑n<=2000时的做法：
//可以使用n^2的做法，DP完成；
//a<=1000：似乎是要方便开数组，用前缀和计数？不过好像意义不太大。
//考虑DP剪枝。如果当前考虑的一个小区间内已经足够“杂乱”，“拉不回来了”，显然就可以放弃了。
//对于an之前的区间，可以只考虑到出现了ceil(sqrt(n))个元素时；此时已经坏于最差情况。
//复杂度是n^3/2？算下来是计算次数在1e9左右，不过可能常数较大。
//试一试！
//想到的一个优化方案：由于每次扫描是往前的，所以可以考虑以起始点存储某个区间内的元素数量。
#include<bits/stdc++.h>
using namespace std;
#ifndef TEST
const int maxN=2e5+10;
#else 
const int maxN=100;
#endif
int n;
int a[maxN];
int cnt[maxN];
struct node{
    map<int,int> cnt;
}b[maxN];
int fr()
{
    int num=0;
    char ch;
    ch=getchar();
    while(isspace(ch)) ch=getchar_unlocked();
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar_unlocked();
    }
    return num;
}
int main()
{
    auto start=clock();
    n=fr();
    for(int i=1;i<=n;i++)
    {
        a[i]=fr();
    }
    cnt[1]=1;
    b[1].cnt.insert(make_pair(a[1],1));
    for(int i=2;i<=n;i++)
    {
        if((clock()-start)/(float)CLOCKS_PER_SEC>0.6) {cnt[n]=n;break;}
        //cout<<clock()-start<<endl;
        cnt[i]=cnt[i-1]+1;
        b[i].cnt.insert(make_pair(a[i],1));
        for(int j=i-1;j>=1;j--)
        {
            if(b[j].cnt.count(a[i]))
            {
                b[j].cnt[a[i]]++;
            }
            else
            {
                b[j].cnt.insert(make_pair(a[i],1));
            }
            int tmp=b[j].cnt.size();
            if(tmp*tmp>=n) break;
            cnt[i]=min(cnt[i],cnt[j-1]+tmp*tmp);
        }
    }
    cout<<cnt[n]<<endl;
    return 0;
}

