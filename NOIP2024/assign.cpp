/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-05 08:42:44
 * @LastEditTime : 2024-12-05 14:43:28
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : assign.cpp
 * @     © 2024 FeiYehua
 */
//分配二元限制时，有且仅有三种情况：
//xi，xi+1都没有预先限制，则ai，bi均是任意的；对答案的贡献是v^2;
//如果xi已经有预先限制，则如果分配xi=ai，会对bi的取值产生影响（相当于xi+1的值被固定），反之无影响；
//前一情况继续向后遍历时，相当于xi+1的值已经确定，贡献是v；反之则没有任何影响，贡献是（v-1）*v。
//此处也可以考虑连续多少个xi=ai，预处理出对答案的贡献；此后就不会对答案产生影响了。
//如果xi+1已经有预先限制，则一定存在一种方法使xi！=ai，即任何限制都不会对bi产生影响。
//如果xi，xi+1都有预先限制，那么有两种情况：ai=xi时，bi只有一种取值，贡献为1；ai！=xi时，bi取值是任意的，贡献为（v-1）*v。
//由于取值范围高达1e9，所以只能遍历一遍算出答案。
//但是限制的点是离散的，而只要没有限制，取值的贡献可以O(1)算出。
//采用倍增算法，求出连续n个没有限制的点对答案模的贡献；
//
//所以本质上只需要处理发生了限制的片段。
//考虑将限制片段排序。然后考虑发生的限制是否连续。
//将限制逐个处理。
//设前一个限制和后一个限制的差为k。
//保证中间的限制不会对此后的分配产生影响
//k=1，对答案的贡献是(v-1)*v+1；
//k>=2时，对答案的贡献是segma(v^i*((v-1)*v)^1*(v^2)^k-1-i)+v^(k-1);需要保证k-1-i>=0,i>=0;
//所以无论k取何值，对答案的贡献都是segma(v^i*((v-1)*v)^1*(v^2)^(k-1-i))+v^k-1;需要保证k-1-i>=0,i>=0。求出总和即可
//=(v-1)*v*segma(v^(2k-2-i))+v^(k-1),0<=i<=k-1
//=(v-1)*v*v^(k-1)*(v^k-1)/(v-1)+v^(k-1)
//=(v-1)*v*v^(k-1)*(v^k-1)*re%MOD+v^(k-1)
//这里涉及了求除法逆元。
//每次求幂复杂度是logn，总共k的和是1e9，似乎过不了，还需要优化。
//但是只有两个点到1e9，这个算法拿90分应该没问题。
//对于最后一个限制，
//如果他就是最后一个数，那么无需处理；
//如果他不是最后一个数，最后加的就是v^k
#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
bool frontGuard;
const int maxM=1e5+10;
int t,n,m,c,d;
long long v;
long long con1[100];//计算v^2*2^i对答案的贡献；
long long con2[100];//计算v*2^i对答案的贡献；
long long ans;
long long re;
long long f;//存储v*(v-1);
void preKsm(int n)//预处理两个幂
{
    memset(con1,0,sizeof con1);
    memset(con2,0,sizeof con2);
    // con1[0]=1;
    // con2[0]=1;
    con1[0]=v*v;
    con1[0]%=MOD;
    con2[0]=v;
    for(int i=1;i<=2*log2(n);i++)
    {
        con1[i]=(con1[i-1]*con1[i-1])%MOD;
        con2[i]=(con2[i-1]*con2[i-1])%MOD;
    }
    return;
}
long long ksm(int k,int i)//v^i*(v^2)^(k-1-i)=
{
    int a=i;
    int b=k-i-1;
    long long ans1=1,ans2=1;
    int cnt=0;
    while(a>0)
    {
        if(a%2!=0) ans1*=(con2[cnt]);
        ans1%=MOD;
        a/=2;
        cnt++;
    }
    cnt=0;
    while(b>0)
    {
        if(b%2!=0) ans2*=con1[cnt];
        ans2%=MOD;
        b/=2;
        cnt++;
    }
    return ((ans1*ans2)%MOD);
}
long long ksm2(int i)
{
    int cnt=0;
    long long ans=1;
    while(i>0)
    {
        if(i%2!=0) ans*=con2[cnt];
        ans%=MOD;
        i/=2;
        cnt++;
    }
    return ans;
}
long long getAns(int k,bool flag)
{
    long long ans=0;
    for(int i=0;i<=k-1;i++)
    {
        long long t=((ksm(k, i)) * (v - 1))%MOD;
        ans += (t * v) % MOD;
        assert(ans > 0);

        ans%=MOD;
    }
    ans+=ksm(k,k-1+flag);
    ans%=MOD;
    return ans;
}
template<typename T>
void fr(T* num)
{
    char ch=getchar_unlocked();
    *num=0;
    while(isspace(ch)) ch=getchar_unlocked();
    while(isdigit(ch))
    {
        (*num)+=(*num)*9+ch-'0';
        ch=getchar_unlocked();
    }
}
struct node{
    int c,d;
    bool operator<(const node&a) const
    {
        return c<a.c;
    }
}a[maxM];
void getRe()
{
    f=(v*(v-1))%MOD;
    long long k[100];
    k[0]=v-1;
    for(int i=1;i<=log2(MOD);i++)
    {
        k[i]=(k[i-1]*k[i-1])%MOD;
    }
    int p=MOD-2;//v-1的逆元是(v-1)^p
    re=1;
    int cnt=0;
    while(p>0)
    {
        if(p%2==1)
        {
            re*=k[cnt];
            re%=MOD;
        }
        cnt++;
        p/=2;
    }
    return;
}
long long getAnsFast(int k,bool flag)
{
    long long ans=f;
    ans*=ksm2(k-1);
    ans%=MOD;
    long long p=ksm2(k)-1;
    if(p<=0) p+=MOD;
    p*=re;
    p%=MOD;
    ans*=p;
    ans%=MOD;
    ans+=ksm2(k-1+flag);
    ans%=MOD;
    assert(ans > 0);
    return ans;
}
bool tailGuard;
int main()
{
    #ifdef TEST 
    cout<<(&tailGuard-&frontGuard)/1024<<endl;
    freopen("assign/assign3.in","r",stdin);
    freopen("assign/ans.ans","w",stdout);
    #endif
    fr(&t);
    for(int i=1;i<=t;i++)
    {
        fr(&n);fr(&m);fr(&v);
        memset(a,0,sizeof a);
        preKsm(n);
        getRe();//求v-1的逆元
        ans=1;
        map<int,int> cnt;
        cnt.clear();
        bool endflag=1;
        for(int j=1;j<=m;j++)
        {
            fr(&a[j].c);fr(&a[j].d);
            if (cnt.count(a[j].c))
            {
                if(cnt[a[j].c]!=a[j].d)
                endflag = 0;
            }
            else cnt.insert(make_pair(a[j].c,a[j].d));
        }
        if(!endflag) {cout<<"0\n";continue;}
        a[m+1].c=n;
        bool flag=0;
        if(a[m].c!=n) flag=1;
        sort(a+1,a+2+m);
        for(int j=2;j<=m;j++)
        {
            ans*=getAnsFast(a[j].c-a[j-1].c,0);
            // cout<<"j="<<j<<" "<<a[j].c-a[j-1].c<<" "<<getAns(a[j].c-a[j-1].c,0)<<endl;
            ans%=MOD;
        }
        ans*=getAnsFast(a[m+1].c-a[m].c,flag);
        ans%=MOD;
        assert(ans>0);
        // ans*=ksm(a[m].c+n,0);
        // ans%=MOD;
        ans*=ksm(a[1].c,0);
        ans%=MOD;
        assert(ans>0);
        cout<<ans<<endl;
    }
    return 0;
}