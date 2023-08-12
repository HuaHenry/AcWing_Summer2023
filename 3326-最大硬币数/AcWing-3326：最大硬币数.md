# AcWing-3326：最大硬币数



### 题目描述

![image-20230812143314843](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230812143314843.png)

![image-20230812143322878](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230812143322878.png)

#### 输入样例：

```
2
3
1 2 5
3 6 1
12 2 7
5
0 0 0 0 0
1 1 1 1 0
2 2 2 8 0
1 1 1 0 0
0 0 0 0 0
```

#### 输出样例：

```
Case #1: 14
Case #2: 9
```

#### 样例解释

对于测试数据 1，Mike 可以选择的行进路径为 (1,1)→(2,2)→(3,3)，可收集到的最大硬币数量为 14。

对于测试数据 2，Mike 可以选择的行进路径为 (2,3)→(3,4)，可收集到的最大硬币数量为 9。



### 算法求解

题意可以理解为，求最长的“斜边和”，且这个斜边是从左上角到右下角的。

这个“求和”的过程可以在数据输入时进行。每一条从左上到右下角的斜边都有特征——其斜边上每一个点`row-column`值相等。那么可以通过这个行列位置的差值作为和数组的下标，由于会产生负下标，可以选择使用`map`或所有差值都加上总行/列值来解决（以下代码采用后者）。

Code：

```c++
//
//  main.cpp
//  3326-最大硬币数
//
//  Created by MacBook Pro on 2023/8/12.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        long long int nums[3000]={0};
        int N;
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                int x; scanf("%d",&x);
                nums[i-j+N]+=x;
                
            }
        }
        long long int ans = 0;
        for(int i=1;i<=2*N-1;i++){
            ans = max(ans,(long long)(nums[i]));
        }
        printf("Case #%d: %lld\n",cases,ans);
    }
    return 0;
}

```

需要注意的是，和数组和结果都应该用` long long int `表示。