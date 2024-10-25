/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-10-25 15:23:22
 * @LastEditTime : 2024-10-25 15:52:04
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
/*
vector的使用：
类似于数组的元素访问；
访问begin，end方法可以返回迭代器，用于与其他STL配合使用；
insert方法：第一个参数为一个迭代器，第二个参数为数量n，第三个参数为值；
在该迭代器前插入n个对应数值
*/