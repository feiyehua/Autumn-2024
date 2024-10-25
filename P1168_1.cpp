/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-10-25 15:55:21
 * @LastEditTime : 2024-10-25 17:36:27
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1168_1.cpp
 * @     © 2024 FeiYehua
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
priority_queue<int,vector<int>,greater<int>> minQueue;//这是一个最小堆
priority_queue<int> maxQueue;//这是一个最大堆
int n;
int mid;
int main()
{
    scanf("%d",&n);
    scanf("%d",&mid);
    printf("%d\n",mid);
    for(int i=2;i<=n-1;i+=2)
    {
        int num1,num2;
        scanf("%d%d",&num1,&num2);
        if(num1<=mid)
        {
            maxQueue.push(num1);
            if(num2>=mid)
            {
                minQueue.push(num2);
            }
            else
            {
                if(num2>=maxQueue.top())
                {
                    minQueue.push(mid);
                    mid=num2;
                }
                else
                {
                    minQueue.push(mid);
                    mid=maxQueue.top();
                    maxQueue.pop();
                    maxQueue.push(num2);
                }
            }
        }
        else{
            minQueue.push(num1);
            if(num2<=mid)
            {
                maxQueue.push(num2);
            }
            else
            {
                if(num2<=minQueue.top())
                {
                    maxQueue.push(mid);
                    mid=num2;
                }
                else
                {
                    maxQueue.push(mid);
                    mid=minQueue.top();
                    minQueue.pop();
                    minQueue.push(num2);
                }
            }
        }
        printf("%d\n",mid);
    }
    return 0;
}