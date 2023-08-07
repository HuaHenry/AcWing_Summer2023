# AcWing-4443：无限区域

![image-20230807170147368](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230807170147368.png)

![image-20230807170201012](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230807170201012.png)

#### 输入样例：

```
2
1 3 6
5 2 5
```

#### 输出样例：

```
Case #1: 31.415927
Case #2: 455.530935
```

#### 样例解释

对于 case #1，首先画一个半径为 1 的右圆，然后画一个半径为 1×3=3 的左圆，随后停止绘画，因为下一个右圆的半径为 ⌊3/6⌋=0。

对于 case #2：

1. 第一步画一个半径为 5 的右圆；
2. 第二步画一个半径为 5×2=10 的左圆；
3. 第三步画一个半径为 ⌊10/5⌋=2 的右圆；
4. 第四步画一个半径为 2×2=4 的左圆；
5. 停止绘画，因为下一个右圆的半径为 ⌊4/5⌋=0。



简单的模拟题，代码实现上做了一个简单的简化：左右分别判断改为判断一次，在`r`处理后即将作为右圆的半径计算时进行判断。

此外注意计算精度，需要记 $\pi=3.141592654$ 才能达到精度要求。

Code：

```c++
//
//  main.cpp
//  4443-无限区域
//
//  Created by MacBook Pro on 2023/8/7.
//

#include <iostream>
#include <cmath>
using namespace std;

const double pai = 3.141592654;

int main() {
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        int r,a,b;
        scanf("%d%d%d",&r,&a,&b);
        double ans = .0;
        while(r!=0){
            ans += pai*r*r;
            r = a*r;
            ans += pai*r*r;
            r = floor(double(r)/b);
        }
        printf("Case #%d: %lf\n",cases,ans);
    }
}
```

![image-20230807170618868](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230807170618868.png)