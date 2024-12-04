/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-03 17:33:44
 * @LastEditTime : 2024-12-04 20:03:36
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11372.cpp
 * @     © 2024 FeiYehua
 */
//lower_bound,upper_bound二分查找、sort函数等传入的起始、终止区间全都是左闭右开的，与迭代器的性质相同，所以不需要用.end()-1，而是直接.end()即可
#include<bits/stdc++.h>
using namespace std;
bool guardStart;
constexpr int maxN=1e3+10;
int n,k;
int m,x,y;

//考虑三维的情况  
//发现n的范围并不大，考虑能不能预处理出有两个坐标相同的点，然后就可以直接判断能不能被看见了。
//询问第每个教练看见oier的个数
//考虑将“可能遮挡”的三种元素的坐标排序，然后扫描一遍，这样总复杂度就是
//多维向量的初始化如下所示
vector<vector< vector< pair<int,int> > > > a(maxN, vector< vector< pair<int,int> > >(maxN,vector<pair<int,int>>(0)));
vector<vector< vector< pair<int,int> > > > b(maxN, vector< vector< pair<int,int> > >(maxN,vector<pair<int,int>>(0)));
vector<vector< vector< pair<int,int> > > > c(maxN, vector< vector< pair<int,int> > >(maxN,vector<pair<int,int>>(0)));

struct node{
    //int x,y,z;
    int dim[5];
};
node oi[maxN],ob[maxN],te[maxN];
void add(int x,int y,int z,int type)
{
    // a[x][y].push
    a[x][y].push_back(make_pair(z,type));
    b[x][z].push_back(make_pair(y,type));
    c[y][z].push_back(make_pair(x,type));
    return;
}
vector<vector<pair<int,int>>> a2(maxN);
vector<vector<pair<int,int>>> b2(maxN);
vector<pair<int,int>> a1;
void add2(int x,int y,int type)
{
    a2[x].push_back(make_pair(y,type));
    b2[y].push_back(make_pair(x,type));
    return;
}
void trav(const vector<pair<int,int>>& v,std::vector<std::pair<int, int>>::iterator it,int* ans)
{
    int loc=it-v.begin();
    if(loc-1>=0&&v[loc-1].second==1) (*ans)++;
    if(loc+1<v.size()&&v[loc+1].second==1) (*ans)++;
    return;
}
int ans[maxN];
bool guardEnd;
int main()
{
    #ifdef TEST
    cout<<-(&guardStart-&guardEnd)/1024<<endl;
    #endif
    cin>>n>>k;
    cin>>m>>x>>y;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=k;j++)
        {
            cin>>oi[i].dim[j];
        }
        if(k==3) add(oi[i].dim[1],oi[i].dim[2],oi[i].dim[3],1);
        else if(k==2) add2(oi[i].dim[1],oi[i].dim[2],1);
        else if(k==1) a1.push_back(make_pair(oi[i].dim[1],1));
    }
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=k;j++)
        {
            cin>>ob[i].dim[j];
        }
        if(k==3) add(ob[i].dim[1],ob[i].dim[2],ob[i].dim[3],2);
        else if(k==2) add2(ob[i].dim[1],ob[i].dim[2],2);
        else if(k==1) a1.push_back(make_pair(ob[i].dim[1],2));
    }
    for(int i=1;i<=y;i++)
    {
        for(int j=1;j<=k;j++)
        {
            cin>>te[i].dim[j];
        }
        if(k==3) add(te[i].dim[1],te[i].dim[2],te[i].dim[3],3);
        else if(k==2) add2(te[i].dim[1],te[i].dim[2],3);
        else if(k==1) a1.push_back(make_pair(te[i].dim[1],3));
    }
    if(k==3)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j].size()>1)
                sort(a[i][j].begin(),a[i][j].end());
                if(b[i][j].size()>1)
                sort(b[i][j].begin(),b[i][j].end());
                if(c[i][j].size()>1)
                sort(c[i][j].begin(),c[i][j].end());
            }
        }
        for(int i=1;i<=y;i++)
        {
            //对于每个教练来说，找到在每一个维度上会被挡住的oier即可
            int locx=te[i].dim[1],locy=te[i].dim[2],locz=te[i].dim[3];
            auto it=lower_bound(a[locx][locy].begin(),a[locx][locy].end(),make_pair(locz,3));
            trav(a[locx][locy],it,&ans[i]);
            it=lower_bound(b[locx][locz].begin(),b[locx][locz].end(),make_pair(locy,3));
            trav(b[locx][locz],it,&ans[i]);
            it=lower_bound(c[locy][locz].begin(),c[locy][locz].end(),make_pair(locx,3));
            trav(c[locy][locz],it,&ans[i]);
        }
    }
    else if(k==2)
    {
        for(int i=1;i<=n;i++)
        {
            if(a2[i].size()>1)
            sort(a2[i].begin(),a2[i].end());
            if(b2[i].size()>1)
            sort(b2[i].begin(),b2[i].end());
        }
        for(int i=1;i<=y;i++)
        {
            int locx=te[i].dim[1],locy=te[i].dim[2];
            auto it=lower_bound(a2[locx].begin(),a2[locx].end(),make_pair(locy,3));
            trav(a2[locx],it,&ans[i]);
            it=lower_bound(b2[locy].begin(),b2[locy].end(),make_pair(locx,3));
            trav(b2[locy],it,&ans[i]);
        }
    }
    else if(k==1)
    {
        sort(a1.begin(),a1.end());
        for(int i=1;i<=y;i++)
        {
            int locx=te[i].dim[1];
            auto it=lower_bound(a1.begin(),a1.end(),make_pair(locx,3));
            trav(a1,it,&ans[i]);
        }
    }
    for (int i = 1; i <= y; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
