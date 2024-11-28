/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-28 16:58:12
 * @LastEditTime : 2024-11-28 17:05:09
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11204.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m;
        int base=m/n;
        int left=m%n;
        //base是基准数量，left是余下的数量，且left一定小于n，即一定一定可以找到不加长的木棍；
        //显然是否能组成三角形取决于基准和加长的木棍长度。
        //如果基准为1，则只有在加长木棍数量为0或者n-1的时候时可以组成；
        //基准大于1时，无论如何都可以组成三角形
        int l=left;
        int s=n-left;//分别表示长、短的木棍
        if(base==1)
        {
            if(l==0||l==n-1)
            {
                cout<<"Yes"<<endl;
            }
            else cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}