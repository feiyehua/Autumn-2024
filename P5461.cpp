/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-10-26 11:25:39
 * @LastEditTime : 2024-10-26 11:36:43
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P5461.cpp
 * @     © 2024 FeiYehua
 */
#include<iostream>
#include<cmath>
using namespace std;
bool a[1050][1050];
int n;
void editFree(int x,int y,int n,int profile)//从下标x开始，范围为2^n
{
    if(profile==0)
    {
        for(int i=x;i<x+pow(2,n);i++)
        {
            for(int j=y;j<y+pow(2,n);j++)
            {
                a[i][j]=1;
            }
        }
    }
    else
    {
        if(n==0)
        {
            //a[x][y]=1;
            return;
        }
        else
        {
            editFree(x,y,n-1,0);
            editFree(x+pow(2,n-1),y,n-1,1);
            editFree(x,y+pow(2,n-1),n-1,1);
            editFree(x+pow(2,n-1),y+pow(2,n-1),n-1,1);
        }
    }
}
int main()
{
    cin>>n;
    editFree(1,1,n,1);
    for(int i=1;i<=pow(2,n);i++)
    {
        for(int j=1;j<=pow(2,n);j++)
        {
            cout<<!a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}