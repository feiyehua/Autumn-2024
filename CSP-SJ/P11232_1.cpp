/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-20 11:37:02
 * @LastEditTime : 2024-11-20 19:16:52
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11232_1.cpp
 * @     © 2024 FeiYehua
 */
/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-04 22:57:55
 * @LastEditTime : 2024-11-05 20:03:32
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
const int maxN=1e5+10;
const int maxL=1e6+10;
struct detectedCar{
    int l;
    int r;
    bool flag;
    int last;//使用一个链表结构来维护上一个元素
}detectedCars[maxN];
bool cmp(const detectedCar &a, const detectedCar &b)
{

    if(a.r!=b.r) return a.r < b.r;
    else return a.l<b.l;
}
//vector<detectedCar> detectedCars;
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
                detectedCars[ansOfDetectedCar].l=lMon[l]+!(haveMon[l]);
                detectedCars[ansOfDetectedCar].r=lMon[r];
            }
        }
    }
    return ansOfDetectedCar;
}
int getLast(int i)
{
    //while(detectedCars[i-1].flag==1&&i>=1) i--;
    return detectedCars[i].last;
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
    sort(detectedCars+1,detectedCars+ansOfDetectedCar+1,cmp);//这样处理后，左端点递增，如果一个的右端点小于前一个，则直接删除上一个元素；
    // 2024.11.20承P1803
    //如果尝试以右端点为关键字排序，是否可以去除掉“删除大元素“这个步骤？
    //detectedCars的l，r即为左右端点，我们需要考虑最少需要选出多少个点
    int curEnd=detectedCars[1].r;
    int ansOfRemainedMon=1;
    for(int i=2;i<=ansOfDetectedCar;i++)
    {
        if(detectedCars[i].l<=curEnd) continue;
        ansOfRemainedMon++;
        curEnd=detectedCars[i].r;

    }
    ansOfRemovedMon=m-ansOfRemainedMon;
    //就这样子，也是可以的！比原来的方法节省了上百行代码。
    //很舒服！
    //我们考虑可以这样做的原因：在这个问题中，我们只需要考虑能否“续上”，续不上就答案+1.显然续不续得上取决于前一个的结束位置和第二个的开始位置
    //按照区间起点排序，会导致的问题是，找不到当前考虑的区段之后是否存在更短的区间，即上述“不平凡的”、被其他区段包含的区段，这些区段会导致实际答案数量上升，而算法中不易处理。
    //按照区间终点排序，就保证了每次放置摄像头的“结束点”一定是最优的：既可以保证当前区段被覆盖了，也可以保证之后能被覆盖到的区段最多。由于左端点一定小于右端点，可以证明，此后的点只要出现，只要左端点被覆盖到了，这个点就一定被覆盖到了，即保证了局部最优解确实是全局最优解。
    //显然按照区间起点排序，再删去较大的区间，也是保证了区间右端点单调增。而这些区间即使不去掉，显然也是不会使得摄像头数量增加的，因为他们的起点总是更靠前。因此，即使不去掉这些点，得到的答案依然正确。
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./detect/detect5.in", "r", stdin);
    freopen("./detect/ans.ans", "w", stdout);
#endif
    t=fr();
    for(int i=1;i<=t;i++)//多测
    {
        
        memset(cars,0,sizeof(cars));
        memset(haveMon,0,sizeof haveMon);
        memset(detectedCars,0,sizeof detectedCars);
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
        //if(i<=2) continue;
        getDetectedCar();//计算能被检测到的车数量
        getAnsOfRemovedMon();
        
        //cout<<ansOfDetectedCar<<" "<<ansOfRemovedMon<<endl;
        printf("%d %d\n",ansOfDetectedCar,ansOfRemovedMon);
    }
    return 0;
}

