/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-11-20 21:23:57
 * @LastEditTime : 2024-11-20 21:51:58
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P11273.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=2e5+10;
int a[maxN];
int backup[maxN];
int cnt;//计数
int b[maxN];
int ans[maxN];
int k,n;
map<int,int> m;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        backup[i]=a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1]) {b[++cnt]=a[i];m.insert(make_pair(a[i],cnt));}
    }
    ans[cnt]=0;
    for(int i=cnt-1;i>=1;i--)
    {
        if(b[i+1]-b[i]>k) ans[i]=max(ans[i+1]+1-(b[i+1]-b[i]-1)/k,0);
        else if(b[i+1]-b[i]<=k) ans[i]=ans[i+1]+1;
    }
    for(int i=1;i<=n;i++)
    {
        //for(int j=1;j<=cnt;j++)
        {
            cout<<ans[m[backup[i]]]<<" ";
        }
    }
    return 0;
}
// 这个题目的核心是要考虑到前一个的不可移动次数于后一个的不可移动次数密切相关：
// 首先从倒数第二个元素看起：如果最后一个元素与他的间距足够大，那么他的不可移动次数是0，每次都随着最后一个元素一起移动；
// 反之，在最后一个元素移动一次后，它也可以移动了。
// 再考虑更靠前的元素。当他们与前面元素的距离都足够小时，他的不可移动次数是前面一个元素的不可移动次数+1；
// 如果距离较大，则考虑移动数次后达到不可移动状态，再与前面元素一起等待；或者完全不受影响。
// 而且，我们不难发现，如果前一个元素不可移动时，后一个元素与其距离足够近，那么后一个元素也一起不可移动。因此上述递推关系是正确的。
// 做这种题，可以考虑先特殊再一般，尝试先排除掉一些特殊情况再考虑。