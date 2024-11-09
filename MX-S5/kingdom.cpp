/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-09 08:38:54
 * @LastEditTime : 2024-11-09 19:11:03
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : kingdom.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
int n;//s的长度
long long m;//看到后m个字符
int q;//q组测试
const int maxN=2e5+10;
bool str[maxN*2];
long long s,k;
int pri[maxN*2];//记录上一个1出现的位置
int nextLoc[maxN*2];
bool isAll0=1,isAll1=1;
int length[maxN];
bool vis[maxN];
long long fr()
{
    char ch;
    long long num=0;
    ch=getchar();
    while(isspace(ch)) ch=getchar();
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar();
    }
    return num;
}
void getNextLoc()//记录每个点开始、到下一个点是什么
{
    int len=m%n;
    for(int i=len+1;i>=2;i--)
    {
        if(str[i]||i==2) {nextLoc[1]=i;break;}
    }
    for(int i=2;i<=n;i++)
    {
        if(str[i+len]) nextLoc[i]=i+len;
        else nextLoc[i]=max(nextLoc[i-1],i+1);
    }
    for(int i=1;i<=n;i++)
    {
        length[i]=nextLoc[i]-i;
    }
    for(int i=1;i<=n;i++)
    {
        if(nextLoc[i]>n) nextLoc[i]-=n;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("/Users/xiong/Documents/CPP/Autumn-2024/MX-S5/kingdom/kingdom5.in","r",stdin);
    //freopen("/Users/xiong/Documents/CPP/Autumn-2024/MX-S5/kingdom/ans.out","w",stdout);
    #endif
    n=fr(),m=fr(),q=fr();
    int lastOne=-1;
    for(int i=1;i<=n;i++)
    {
        char ch;
        ch=getchar();
        while(isspace(ch)) ch=getchar();
        str[i]=ch-'0';
        if(str[i]==1) isAll0=false;
        if(str[i]==0) isAll1=false;
        pri[i]=lastOne;
        if(str[i]) lastOne=i;
    }
    if(!(isAll0|isAll1))
    {
        for(int i=n+1;i<=2*n;i++)
        {
            str[i]=str[i-n];
        }
        getNextLoc();
    }
    for(int i=1;i<=q;i++)
    {
        s=fr(),k=fr();
        //if(i<=4) continue;
        if (isAll0)
        {
            // 每次前移会移到i+1上
            printf("%lld\n",s+k);
            continue;
        }
        if(isAll1)
        {
            //每次都会移动到i+m上
            //long long a1=s%MOD,a2=k%MOD,a3=m%MOD,a4=(a2*a3)%MOD,a5=(a1+a4)%MOD;
            printf("%lld\n",(s+(k%MOD)*(m%MOD))%MOD);
            continue;
        }
        if(k==0) printf("%lld\n",s%MOD);
        else
        {
            long long ans=s;
            ans%=MOD;
            long long start=s%n;
            s%=n;
            if(s==0) s+=n;
            if(start==0) start+=n;
            long long b=((m/n)%MOD*n%MOD)%MOD;
            for (long long j = 1; j <= k; j++)
            {
                ans=ans+b+length[s];
                ans%=MOD;
                cout<<i<<" "<<s<<" "<<nextLoc[s]<<" "<<j<<" "<<length[s]<<endl;
                s=nextLoc[s];
                if(s==start) 
                {
                    //前j次为一个循环
                    //cout<<j<<endl;
                    ans=(((ans-start)%MOD)*((k/j)%MOD)%MOD)+start;
                    //cout<<s<<" "<<ans<<endl;
                    k=k%j,j=0;
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}