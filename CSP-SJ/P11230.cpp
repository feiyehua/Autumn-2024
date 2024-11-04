/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-04 15:36:11
 * @LastEditTime : 2024-11-04 18:26:44
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11230.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxL=2e5+10;
const int maxN=1e5+10;
int t,n,k,q;
int a[maxL];
int l[maxN];
int startOfDict[maxN];
int cnt[maxL];
bool ans[110][maxL];
struct visInfo{
    int peo;
    int loc;//存储接龙的人和接龙结束的数组下标
};
int fastRead()
{
    char ch=getchar();
    while(ch>'9'||ch<'0') ch=getchar();
    int num=0;
    while(ch>='0'&&ch<='9') 
    {
        num*=10;
        num+=(ch-'0');
        ch=getchar();
    }
    return num;
}
void getVisitability()
{
    vector<visInfo> b;    
    for(int i=1;i<=n;i++)
    {
        int start=-1;
        for(int j=0;j<l[i];j++)
        {
            if(start!=-1&&j+startOfDict[i]-start<k){
                visInfo tmp;
                tmp.peo=i,tmp.loc=j;
                b.push_back(tmp);//这个地方可以被访问到
            }
            if(a[j+startOfDict[i]]==1)
            {
                start=j+startOfDict[i];
            }
        }
    }//处理完初次接龙
    for(int r=2;r<=102;r++)
    {
        memset(cnt,0xff,sizeof(cnt));
        for(unsigned int i=0;i<b.size();i++)//标记本次可用的起始点
        {
            int num=a[b[i].loc+startOfDict[b[i].peo]];//结束对应的数字
            ans[r-1][num]=1;
            if(cnt[num]>0) cnt[num]=0;
            if(cnt[num]==-1) cnt[num]=b[i].peo;
        }
        b.clear();
        for(int i=1;i<=n;i++)
        {
            int start=-1;
            for(int j=0;j<l[i];j++)
            {
                if (start != -1 && j + startOfDict[i] - start < k)
                {
                    visInfo tmp;
                    tmp.peo = i, tmp.loc = j;
                    b.push_back(tmp); // 这个地方可以被访问到
                }
                if (cnt[a[j + startOfDict[i]]] >= 0 && cnt[a[j + startOfDict[i]]] != i)//判断是否连续起始
                {
                    start = j + startOfDict[i];//这个位置可以作为起始点
                }
            }
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./Autumn-2024/CSP-SJ/chain/chain4.in","r",stdin);
    freopen("./Autumn-2024/CSP-SJ/chain/ans.ans","w",stdout);
    #endif
    t=fastRead();   
    for (int kk= 1; kk <= t; kk++)
    {
        n=fastRead();
        k=fastRead();
        q=fastRead();
        memset(a,0,sizeof a);
        memset(startOfDict,0,sizeof startOfDict);
        memset(l,0,sizeof l);
        memset(ans,0,sizeof ans);
        for (int i = 1; i <= n; i++)
        {
            l[i] = fastRead();
            startOfDict[i + 1] = startOfDict[i] + l[i];
            for (int j = 0; j < l[i]; j++)
            {
                a[j + startOfDict[i]] = fastRead();
            }
        }
        getVisitability();
        for (int i = 1; i <= q; i++)
        {
            int r = fastRead(), c = fastRead();
            printf("%d\n", ans[r][c]);
        }
    }
    return 0;
}

#if 0
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;
const int MAXM = 1e2 + 10;

inline 
void read(int &x) {
	x = 0; char c = getchar();
	for (; isspace(c); c = getchar());
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
}

int T, n, m, q; int cnt[MAXN]; bool ans[MAXM][MAXN];

int a[MAXN]; bool vis[MAXN]; int pos[MAXN];

inline 
void init() {
	vector<pair<int, int>> f, g;//pair动态数组
	for (int i = 1; i <= n; i++) {//处理n个人，初始处理：考虑起始情况
		for (int j = pos[i], p = -1e9; j < pos[i + 1]; j++) {//逐个字典进行处理，p记录上一个a[j]==1位置
			if (j - p < m) f.emplace_back(i, j), ans[1][a[j]] = 1;//如果符合题目中长度小于k的条件，就记录从1可以到达a[j]，同时加入f数组中记录
			if (a[j] == 1) p = j;
		}
	}
	for (int t = 2; t <= 100; t++) {//处理进行多轮游戏的情况
		memset(cnt, 0xff, sizeof cnt);//清空cnt数组，-1代表该位置不可被到达
		for (pair<int, int> x : f) {//遍历上一层所有可以到达的位置
			int y = a[x.second];//记录起始位置的字典数字
			if (cnt[y] == -1) cnt[y] = x.first;//==-1说明该位置没有被访问过，设置成为有这个数字的序列号
			else if (cnt[y] != x.first) cnt[y] = 0;//处理被访问多次的情况
		}
		for (int i = 1; i <= n; i++) {
			for (int j = pos[i]; j < pos[i + 1]; j++) {//遍历所有序列
				if (~cnt[a[j]] && cnt[a[j]] != i) g.emplace_back(i, j);//记录接龙的起始点信息
			}
		}
		f.clear();//清空f
		for (pair<int, int> x : g) vis[x.second] = 1;//遍历g数组，如果可以作为起始点，则标记vis为1
		for (int i = 1; i <= n; i++) {
			for (int j = pos[i], p = -1e9; j < pos[i + 1]; j++) {//重复第一次的操作
				if (j - p < m) f.emplace_back(i, j), ans[t][a[j]] = 1;//第t次接龙可以于a[j]结束
				if (vis[j]) p = j;//可以作为起始点
			}
		}
		for (pair<int, int> x : g) vis[x.second] = 0;//清空vis数组，准备下一次访问
		g.clear();//清空g数组，准备下一次操作
	}
}

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	for (read(T); T--; ) {
		read(n), read(m), read(q);//读入n，k，q
		memset(ans, 0, sizeof ans);
		memset(vis, 0, sizeof vis);
		for (int i = 1, k; i <= n; i++) {
			read(k), pos[i + 1] = pos[i] + k;//使用pos记录每个人字典的首位下标,这样做可以减少空间消耗
			for (int j = pos[i]; j < pos[i + 1]; j++) read(a[j]);//读入字典
		}
//		clock_t st = clock();
		init();
//		fprintf(stderr, "init time: %.3lfs\n", (double)(clock() - st) / CLOCKS_PER_SEC);
		for (int r, c; q--; read(r), read(c), printf("%d\n", ans[r][c]));
	}
}
#endif

