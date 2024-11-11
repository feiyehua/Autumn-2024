/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-11 19:13:46
 * @LastEditTime : 2024-11-11 19:45:57
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1045.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int p,n,m;
long long a[600];
long long tmp=(long long)1<<32;
void highMultiply(int x)
{
	for(int i=1;i<=x/32;i++)//乘n次2
	{
		for(int j=499;j>=0;j--)
		{
			a[j]=a[j]*tmp;
		}
        for(int j=0;j<=499;j++)
        {
            a[j+1]+=a[j]/10;
            a[j]=a[j]%10;
        }
	}
	for(int i=1;i<=x%32;i++)//乘n次2
	{
		for(int j=499;j>=0;j--)
		{
			a[j]=a[j]*2;
			a[j+1]+=a[j]/10;
			a[j]=a[j]%10;
		}
	}
}
int main()
{
	cin>>p;
	a[0]=1;
	n=0;
	m=p*log10(2)+1;
	highMultiply(p);
	cout<<m<<endl;
	for(int i=499;i>0;i--)
	{
		cout<<a[i];
		if(i%50==0)
		cout<<"\n";
	}
	cout<<a[0]-1;
	return 0;
}