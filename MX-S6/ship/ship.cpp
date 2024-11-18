/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-17 10:13:01
 * @LastEditTime : 2024-11-18 19:37:30
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : ship.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
//相当于是一个追及问题
//加速会造成一定时间的落后，终点在落后区段内，则该区域不加速合适；其外的区域，加速合适；
//对于每个加油站点，到达此点的情况是唯一的（即对时间-速度的二元组有最优解）
//似乎不对，因为每次加速的收益是在此后通用的
//如果很多点都是在短时看不到收益的区间内，就不好说了
//预处理时，在每个加油站，更新此后的第一个能够被加速受惠的加油站
//对每次询问，找到相距最近的加油站，然后判断在该点是否加速即可
//考虑一个四维大dp
//从上一个点转移到下一个点（那其实就是三维）
//考虑到达某点的速度和时间
bool front_flag;
const int N=1e5;
double tim[N+1][31][20];
int n,q;
const int maxN=1e5+10;
struct sta{
    int p,x;
    double t;
}stas[maxN];
bool flag4=1;
int cnt[maxN][6];
int b[maxN];
bool end_flag;
//我的DP思路：以每次到达的加油站转移，分别存储加2倍、3倍、4倍的数量
//优化：首先注意到加油时间总是1，那么如果速度已经快到了一定程度，那么此后的加油都是没有意义的，所以数组后几维可以只开到35左右
//2^2=4，所以可以缩减1维，优化空间复杂度（常规来说是会爆内存的）
int main()
{
    #ifdef TEST
    freopen("/Users/xiong/Documents/CPP/Autumn-2024/MX-S6/ship/ship/ship4.in","r",stdin);
    freopen("/Users/xiong/Documents/CPP/Autumn-2024/MX-S6/ship/ship/ans.out","w",stdout);
    cout<<(&end_flag-&front_flag)/(1024*1024)<<endl;
    #endif
    
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>stas[i].p>>stas[i].t>>stas[i].x;
        b[i]=stas[i].p;
        tim[i][0][0]=(double) stas[i].p;
        //cnt[i][stas[i].x]++;
        if(stas[i].x!=1) flag4=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=4;j++)
        {
            cnt[i][j]=cnt[i-1][j];
        }
        cnt[i][stas[i].x]++;
    }
    if(!flag4)
    {
        //tim[1][0][0][0]=stas[1].p;
        for (int i = 2; i <= n; i++)
        {
            for (int k = 0; k <= min(cnt[i - 1][2],30); k++)
            {
                for (int l = 0; l <= min(cnt[i - 1][3],19); l++)
                {
                    for (int m = 0; m <= min(cnt[i - 1][4],15)&&m*2+k<=30; m++)
                    {
                        // if(i==3&&m*2+k==1&&l==0) 
                        //     cout<<" ";
                        if (tim[i][k + m * 2][l] == 0) // 第一次访问此点
                            tim[i][k + m * 2][l] = 1e9;
                        if (tim[i - 1][k + m * 2][l] != 0)
                            tim[i][k + m * 2][l] = min(tim[i][k + m * 2][l], tim[i - 1][k + m * 2][l] + ((double)stas[i].p - (double)stas[i - 1].p) / (pow(2, k) * pow(3, l) * (pow(4, m))));
                        if (stas[i - 1].x == 2 && k >= 1)
                            tim[i][k+m*2][l] = min(tim[i][k+m*2][l], tim[i - 1][k - 1+m*2][l] + ((double)stas[i].p - (double)stas[i - 1].p) / (pow(2, k) * pow(3, l) * (pow(4, m))) + stas[i - 1].t);
                        if (stas[i - 1].x == 3 && l >= 1)
                            tim[i][k+m*2][l] = min(tim[i][k+m*2][l], tim[i - 1][k+m*2][l - 1] + ((double)stas[i].p - (double)stas[i - 1].p) / (pow(2, k) * pow(3, l) * (pow(4, m))) + stas[i - 1].t);
                        if (stas[i - 1].x == 4 && m >= 1)
                            tim[i][k+m*2][l] = min(tim[i][k+m*2][l], tim[i - 1][k+(m-1)*2][l] + ((double)stas[i].p - (double)stas[i - 1].p) / (pow(2, k) * pow(3, l) * (pow(4, m))) + stas[i - 1].t);
                    }
                }
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int y;
        cin>>y;
        if(flag4)
        {
            cout<<y<<endl;
        }
        else
        {
            int loc=lower_bound(b+1,b+1+n,y)-b;
            if(stas[loc].p>y) loc--;
            if(loc==n+1) loc--;
            //cout<<"loc"<<loc<<endl;
            double ans=1e9;
            for (int k = 0; k <= min(cnt[loc-1][2],30); k++)
            {
                for (int l = 0; l <= min(cnt[loc-1][3],19); l++)
                {
                    for (int m = 0; m <= min(cnt[loc-1][4],15)&&m*2+k<=30; m++)
                    {
                        //cout<<k<<" "<<l<<" "<<m<<" \n";
                        // double tmp = ans;
                        ans = min(ans, tim[loc][k+m*2][l] + ((double)y - (double)stas[loc].p) / (pow(2, k) * pow(3, l) * (pow(4, m))));
                        // if (tmp != ans)
                        //     cout << l << " " << m << " " << k << " " << ans << " " << endl;
                        if (stas[loc].x == 2)
                        {
                            // tmp = ans;
                            ans = min(ans, tim[loc][k+m*2][l] + stas[loc].t + ((double)y - (double)stas[loc].p) / (pow(2, k + 1) * pow(3, l) * (pow(4, m))));
                            // if (tmp != ans)
                            //     cout << l << " " << m << " " << k << " " << ans << " " << endl;
                        }
                        if (stas[loc].x == 3)
                        {
                            // tmp = ans;
                            ans = min(ans, tim[loc][k+m*2][l] + stas[loc].t + ((double)y - (double)stas[loc].p) / (pow(2, k) * pow(3, l + 1) * (pow(4, m))));
                            // if (tmp != ans)
                            //     cout << l << " " << m << " " << k << " " << ans << " " << endl;
                        }
                        if (stas[loc].x == 4)
                        {
                            // tmp = ans;
                            ans = min(ans, tim[loc][k+m*2][l] + stas[loc].t + ((double)y - (double)stas[loc].p) / (pow(2, k) * pow(3, l) * (pow(4, m + 1))));
                            // if (tmp != ans)
                            //     cout << l << " " << m << " " << k << " " << ans << " " << endl;
                        }                  
                    }
                }
            }
            printf("%.10lf\n",ans);
            //cou << ans << endl;
        }
    }
   // cout<<pow(2,100);
    return 0;
}
