/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-11 17:33:13
 * @LastEditTime : 2024-11-11 19:01:59
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1005.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[100][100];
__int128 b[100][100][100];
__int128 ans[100];
__int128 c=0;
__int128 fr()
{
    char ch;
    __int128 num=0;
    ch=getchar();
    while(isspace(ch)) ch=getchar();
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar();
    }
    return num;
}
__int128 max(__int128 x,__int128 y)
{
    if(x>=y) return x;
    return y;
}
void printInt128(__int128 x)
{
    if(x>=10)
    {
        printInt128(x/10);
    }
    putchar(x%10+'0');
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        __int128 l=1;
        for(int j=1;j<=m;j++)//取了j个数
        {
            l*=2;
            b[i][j][0]=b[i][j-1][0]+l*a[i][m-j+1];
            #ifdef TEST
            printInt128(b[i][j][0]);
            printf(" %d %d %d\n",i,j,0);
            #endif
            for(int k=1;k<j;k++)//其中行首取了了k个
            {
                b[i][j][k]=max(b[i][j-1][k-1]+l*a[i][k],b[i][j-1][k]+l*a[i][m-j+k+1]);
                #ifdef TEST
                printInt128(b[i][j][k]);
                printf(" %d %d %d\n",i,j,k);
                #endif
            }
            b[i][j][j]=b[i][j-1][j-1]+l*a[i][j];//
            #ifdef TEST
            printInt128(b[i][j][j]);
            printf(" %d %d %d\n",i,j,j);
            #endif
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            ans[i]=max(ans[i],b[i][m][j]);
        }
        // printInt128(ans[i][m]);
        // printf("\n");
        c+=ans[i];
    }
    printInt128(c);
    fflush(stdout);
    return 0;
}