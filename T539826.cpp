/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-15 19:22:30
 * @LastEditTime : 2024-11-15 20:42:43
 * @LastEditors  : FeiYehua
 * @Description  : 202411G 三角含数
 * @FilePath     : T539826.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;

int x;
int l,r;
int cnt;
bool can(int a,int b,int c)
{
    if(a+b>c&&a+c>b&&b+c>a) return 1;
    return 0;
}
void getTri(int x)
{
    int a[10]={0};
    int tmp1=x;
    int k=0;
    while(tmp1>0)
    {
        k++;
        if(tmp1%10==0) return;
        a[k]=tmp1%10;
        tmp1/=10;
    }
    sort(a+1,a+7);
    vector<int> b={1,2,3,4,5,6};
    do
    {
        if (can(a[b[0]], a[b[1]], a[b[2]]) && can(a[b[3]], a[b[4]], a[b[5]]))
        {
            cnt++;
            return;
        }
    } while (next_permutation(b.begin(), b.end()));
    return;
}
int main()
{
    cin>>l>>r;
    for(int i=l;i<=r;i++)
    {
        getTri(i);
    }
    cout<<cnt<<endl;
    return 0;
}