/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-27 10:22:37
 * @LastEditTime : 2024-11-27 11:20:00
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P7076.cpp
 * @     © 2024 FeiYehua
 */
//不是，哥们！真的连unsigned long long都会爆掉嘛
#include<bits/stdc++.h>
using namespace std;
const int maxK=70;
const int maxN=1e6+10;
bool have[maxK];//标记是否有某个数的二进制某位为1
bool res[maxK];
__int128 a[maxN];
struct node{
    int p,q;
}req[maxN];
__int128 fr()
{
    __int128 num=0;//快读记得初始化变量
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
void print(__int128 x)
{
    if(x>=10)//这里记得带等号
    {
        print(x/10);
    }
    putchar(x%10+'0');
}
int fri()
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
void getHave(unsigned long long x)//获取x的哪些位中有1；
{
    int cnt=0;
    while(x>0)
    {
        if(x%2)
        {
            have[cnt]=1;
        }
        cnt++;
        x/=2;
    }
    return;
}
int n,m,c,k;
int main()
{
#ifdef TEST
    //freopen("/Users/xiong/Documents/CPP/Autumn-2024/zoo/zoo3.in", "r", stdin);
#endif
    n=fri(),m=fri(),c=fri(),k=fri();
    //cin>>n>>m>>c>>k;
    for(int i=1;i<=n;i++)
    {
        a[i]=fr();//已经购买的饲料
        getHave(a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        req[i].p=fri(),req[i].q=fri();//保证所有的q不相同
        //只需要取出实际已经购买的饲料和没有购买的饲料
        if(!have[req[i].p])//没有人需要这种饲料，那么这一位不能选
        {
            res[req[i].p]=1;
        }
    }
    __int128 ans=1;
    for(int i=0;i<k;i++)
    {
        if(!res[i])
        {
            ans*=2;
        }
    }
    ans-=n;
    //cout<<ans-n<<endl;
    print(ans);
    return 0;
}