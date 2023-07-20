# AcWing-4741：魔法百合井

![image-20230720112725036](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230720112725036.png)

![image-20230720112740842](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230720112740842.png)

该题是个`dp`问题，子问题在于 `dp[n]表示还剩n朵花时可以使用最少的硬币数将其取出`，那么可以划分子问题的求解方法：

- 实现的序列中最后一个投入是1
- 实现的序列中最后一个投入是42...2的序列

如果是第一个种情况，`dp[n]=min(dp[n],dp[n-1]+1)`

如果是第二种情况，需要枚举2的个数，枚举出所有情况中投币最少的情况。这种情况其实本质上可以理解为`1...142..2`的情况，那么前面1的个数就决定了这里4时获得数量，后续不断叠加的就是这个数量。因此需要满足整除关系，在枚举时可以直接枚举倍数值。

Code：

```c++
//
//  main.cpp
//  4741-魔法百何井
//
//  Created by MacBook Pro on 2023/7/19.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;   //计算所有数值后存储

int dp[N];              //剩余x朵花的最小银币数

int main() {
    memset(dp,0x3f,sizeof(dp));      //预处理为无穷大
    //计算所有值
    dp[0]=0;
    for(int i=1;i<N;i++){
        dp[i]=min(dp[i],dp[i-1]+1);     //考虑第一种情况
        for(int j=2;j*i<N;j++){
            //枚举倍数
            dp[i*j] = min(dp[i*j],dp[i]+4+2*(j-1));
        }
    }
    int T;
    cin>>T;
    for(int cases=1;cases<=T;cases++){
        int n;
        cin>>n;
        printf("Case #%d: %d\n",cases,dp[n]);
    }
    return 0;
}

```