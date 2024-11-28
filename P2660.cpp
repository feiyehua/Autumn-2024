/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-28 08:23:24
 * @LastEditTime : 2024-11-28 08:30:40
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P2660.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
long long x,y,ans;
int main()
{
	cin>>x>>y;
	while(x)
	{
	    if(y>x)
	    swap(x,y);
        long long c=x/y;
	    ans+=c*y*4;
	    x%=y;
	}
	cout<<ans;
	return 0;
}