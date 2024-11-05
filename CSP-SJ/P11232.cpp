/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-04 22:57:55
 * @LastEditTime : 2024-11-05 17:06:41
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11232.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
// 使用前后缀数组统计离南侧距离为a时测速仪的数量；
// 计算每辆车的超速区间；
// 特判不会超速的车；
// 每辆车对应不同的检测到的摄像头，需要保证每辆车有被检查到
// 使用线段树维护吗？
// 每辆车有一个超速线段，选择若干个点，使每个线段上都有至少一个点
// 前述思路不对，只需要将区间排序，找到最少的满足覆盖的点即可
struct detectedCar{
    int l;
    int r;
};
bool cmp(const detectedCar &a, const detectedCar &b)
{

    return a.l > b.l;
}
vector<detectedCar> detectedCars;
//priority_queue<detectedCar,vector<detectedCar>,cmp()>;

int fr()
{
    char ch;
    int num = 0;
    int flag = 1;
    do
    {
        ch = getchar();
        if (ch == '-')
            flag = -1;
    }while (ch < '0' || ch > '9');
    while (isdigit(ch))
    {
        num = num * 10 + ch - '0';
        ch = getchar();
    }
    return flag*num;
}
const int maxN=1e5+10;
const int maxL=1e6+10;
struct car
{
    int d,v,a;
    int l,r;
}cars[maxN];
bool haveMon[maxL];//存储这个位置是否有测速仪
int lMon[maxL];//前后缀测速仪数组
int t;
int n,m,l,v;//m个测速仪
int ansOfDetectedCar;
int ansOfRemovedMon;
int getDetectedCar()
{
    for (int i = 1; i <= n; i++)
    {
        if (cars[i].l == -1)
            continue;
        else
        {
            int l=cars[i].l,r=cars[i].r;
            //cout<<l<<" "<<r<<endl;
            if(lMon[r]-lMon[l]+haveMon[l]>0)
            {
                ansOfDetectedCar++;
                //我们记录下检测到车的摄像头的序号。
                detectedCar tmp;
                tmp.l=lMon[l];
                tmp.r=lMon[r];
                detectedCars.push_back(tmp);
            }
        }
    }
    return ansOfDetectedCar;
}
void getAnsOfRemovedMon()
{
    if(ansOfDetectedCar==0)
    {
        ansOfRemovedMon=m;
        return;
    }
    if(ansOfDetectedCar==1)//只有一辆车被检测到，那么可以移除m-1个测速仪
    {
        ansOfRemovedMon=m-1;
        return;
    }
    //处理各个区间中有包含关系的大区间
    //如果一个大区间包含了一个小区间，则不可能选择大区间内、小区间外的点，因为显然这样选出来的方案不是最优的。可以直接去除他们。
    sort(detectedCars.begin(),detectedCars.end(),cmp);//这样处理后，左端点递增，如果一个的右端点小于前一个，则直接删除上一个元素；
    for(int i=1;i<(int)detectedCars.size();i++)
    {
        while(detectedCars[i].l==detectedCars[i-1].l)
        {
            if(detectedCars[i].r>=detectedCars[i-1].r)
            {
                detectedCars.erase(detectedCars.begin()+i);
                if(i==detectedCars.size()) break;
            }
            else 
            {
                detectedCars.erase(detectedCars.begin()+i-1);
                if(i==detectedCars.size()) break;
            }
        }
        while(detectedCars[i].r<=detectedCars[i-1].r)
        {
            detectedCars.erase(detectedCars.begin()+i-1);
            if(i==detectedCars.size()) break;
        }
    }
    int curR=detectedCars[0].r;
    int ansOfRemainedMon=1;
    for(int i=1;i<detectedCars.size();i++)
    {
        if(curR<=detectedCars[i].r&&curR>=detectedCars[i].l)//当前保留的点被包含了，直接跳过
        {
            continue;
        }
        else{
            ansOfRemainedMon++;
            curR=detectedCars[i].r;
        }
    }
    ansOfRemovedMon=m-ansOfRemainedMon;
    detectedCars.clear();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./Autumn-2024/CSP-SJ/detect/detect4.in", "r", stdin);
    freopen("./Autumn-2024/CSP-SJ/detect/ans.ans", "w", stdout);
#endif
    t=fr();
    for(int i=1;i<=t;i++)//多测
    {
        memset(cars,0,sizeof(cars));
        memset(haveMon,0,sizeof haveMon);
        ansOfRemovedMon=0;
        ansOfDetectedCar=0;
        n=fr();
        m=fr();
        l=fr();//主干道长度
        v=fr();//限速
        for(int j=1;j<=n;j++)//第j辆车
        {
            cars[j].d=fr();//驶入
            cars[j].v=fr();
            cars[j].a=fr();
            int a=cars[j].a;
            if(a==0)
            {
                if(cars[j].v>v)
                {
                    cars[j].l=cars[j].d;
                    cars[j].r=l;
                }
                else
                {
                    cars[j].l=-1;
                    cars[j].r=-1;
                }
            }
            else if(a>0)
            {
                if(cars[j].v>v)//已经超速
                {
                    cars[j].l=cars[j].d;
                    cars[j].r = l;
                    continue;
                }
                int x = (v * v - cars[j].v * cars[j].v) / (2 * cars[j].a);//在这个点之后超速
                // if ((v * v - cars[j].v * cars[j].v) % (2 * cars[j].a) != 0)//如果这个点是一个小数，则需要l++；不是小数，也需要++！
                //     l++;
                if (x + cars[j].d + 1 <= l)
                {
                    cars[j].l = x +cars[j].d+1;
                    cars[j].r = l;
                }
                else 
                {
                    cars[j].l=-1;
                    cars[j].r=-1;
                }
            }
            else if(a<0)
            {
                if(cars[j].v>v)//可能超速
                {
                    int x = ((-v * v) + cars[j].v * cars[j].v) / (2 * -cars[j].a);//结束超速的点，由于是整除，被向下取整；如果可以被整除，则这个点无法检测到超速，需要额外处理
                    if(((-v * v) + cars[j].v * cars[j].v) % (2 * -cars[j].a)==0) x--;//在点x及之前能被检测到超速
                    cars[j].l=cars[j].d;
                    cars[j].r=min(cars[j].d+x,l);
                    //cout<<cars[j].l<<" "<<cars[j].r<<endl;
                }
                else 
                {
                    cars[j].l=-1;
                    cars[j].r=-1;
                }
            }
            //这样处理后，在整个闭区间内都可以被检测到超速
            //如果没有不满足超速条件，则不做处理
        }
        for(int j=1;j<=m;j++)
        {
            int p=fr();
            haveMon[p]=1;//存储有测速仪的信息
        }
        lMon[0]=haveMon[0];//维护前缀数组
        for(int i=1;i<=l;i++)
        {
            lMon[i]=lMon[i-1]+haveMon[i];
        }
        getDetectedCar();//计算能被检测到的车数量
        getAnsOfRemovedMon();
        cout<<ansOfDetectedCar<<" "<<ansOfRemovedMon<<endl;
    }
}

