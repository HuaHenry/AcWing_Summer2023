# AcWing-4633：学生和导师

![image-20230805214059636](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230805214059636.png)

![image-20230805214122237](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230805214122237.png)

![image-20230805214143032](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230805214143032.png)

根据题意，就是要找出分数小于等于两倍自己分数的同学作为自己的导师，如果找不到就输出`-1`。需要注意的是不可以自己做自己的导师，导师分数可以小于自己。

那么问题就转化为一个排序后的查找问题。根据数据量，算法的时间复杂度需要控制在`O(nlogn)`，而排序的时间复杂度已经达到上限，故可以选择同样为`nlogn`的二分作为查找算法。

查找完成后需要判定当前找到的是否大于两倍分数，如果大于就要向左移一项。同时“判定是否为自己”也可以用左移一项的方式，即如果找到的导师分数和自己一样，那么需要判断是否只有自己一个人“占有”这个分数。这里通过统一左移一项避免讨论——如果是自己，那么真正需要找的是恰好比自己分数少的那一个人；如果不是自己，那么左移一项仍然是这个分数数值，不会影响。

Code：

```c++
//
//  main.cpp
//  4333-学生和导师
//
//  Created by MacBook Pro on 2023/8/5.
//

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010;
int a[N],s[N];
int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        memcpy(s,a,sizeof a);
        sort(s+1,s+1+n);
        printf("Case #%d: ",t);
        for(int i=1;i<=n;i++)
        {
            int l=1,r=n;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(s[mid]>2*a[i])r=mid;
                else l=mid+1;
            }
            
            //都进行左移一位的操作（避免临界大于or自己）
            if(s[r]>2*a[i])r--;
            if(a[i]==s[r])r--;
            if(r!=0)
                printf("%d ",s[r]);
            else
                printf("-1 ");
        }
        printf("\n");
    }
    return 0;
}
```

![image-20230805224228784](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230805224228784.png)