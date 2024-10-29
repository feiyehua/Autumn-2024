/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-10-29 20:12:02
 * @LastEditTime : 2024-10-29 20:12:04
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11217.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=2e5+10;
int n,q,w;
int a[maxN],b[maxN];//a为原始值，b为前缀和
int main()
{
    scanf("%d%d%d",&n,&q,&w);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=b[i-1]+a[i];
    }

    return 0;
}