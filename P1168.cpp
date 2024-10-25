/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-10-25 15:23:22
 * @LastEditTime : 2024-10-25 15:45:37
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1168.cpp
 * @     © 2024 FeiYehua
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int> a;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int num;
        scanf("%d",&num);
        auto tmp=upper_bound(a.begin(),a.end(),num);
        a.insert(tmp,1,num);
        if(i%2==1)
        {
            printf("%d\n",a[i/2]);
        }
    }
    return 0;
}