/***
 * @Author       : FeiYehua
 * @Date         : 2024-10-25 20:22:53
 * @LastEditTime : 2024-10-25 20:28:18
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P1281.cpp
 * @     © 2024 FeiYehua
 */
// 二分答案？
#include <iostream>
using namespace std;
int m, k;
int a[550];
int l,r;
struct copy{
    int l,r;
}copyInfo[550];
void getAns(int x)
{
    int curTime=0;
    int end=m;
    int peopleCount=k;
    for(int i=m;i>=1;i--)
    {
        curTime+=a[i];
        if(curTime+a[i-1]>x)
        {
            copyInfo[peopleCount].l=i,copyInfo[peopleCount].r=end;
            end=i-1;
            peopleCount--;
            curTime=0;
        }
    }
    copyInfo[1].l=1,copyInfo[1].r=end;
    return;
}
bool isOk(int x)
{
    int cur = 0;
    int count = 0;
    for (int i = 1; i <= m; i++)
    {
        if (cur + a[i] > x)
        {
            count++;
            if (count > k)
            {
                return 0;
            }
            cur = a[i];
            continue;
        }
        cur += a[i];
    }
    count++;
    if (count > k)
    {
        return 0;
    }
    else{
        return 1;
    }
}
int main()
{
    cin >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        r+=a[i];
    }
    while(l!=r)
    {
        int mid=(l+r)/2;
        if(isOk(mid))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    getAns(l);
    for(int i=1;i<=k;i++)
    {
        cout<<copyInfo[i].l<<" "<<copyInfo[i].r<<endl;
    }
    return 0;
}