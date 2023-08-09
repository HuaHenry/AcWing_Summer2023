# AcWing-4118：猫和狗

### 题目描述

![image-20230809150840665](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230809150840665.png)

![image-20230809150852010](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230809150852010.png)

#### 输入样例1：

```
3
6 10 4 0
CCDCDD
4 1 2 0
CCCC
4 2 1 0
DCCD
```

#### 输出样例1：

```
Case #1: YES
Case #2: YES
Case #3: NO
```

#### 样例1解释

在 Case 1 中，一共有 10 份狗粮和 4 份猫粮。

1. 前两只动物是猫，喂食它们后，还剩下 2 份猫粮。
2. 接下来是一只狗，喂食它后，还剩下 9 份狗粮。
3. 然后是一只猫，喂食它后，还剩下 1 份猫粮。
4. 最后是两只狗，喂食它们后，还剩下 7 份狗粮。

所有狗都被喂食。

在 Case 2 中，没有狗，因此，所有狗（0 只）都被喂食了。

在 Case 3 中，第二只狗前面的猫得不到喂食，所有第二只狗也没法得到喂食。

#### 输入样例2：

```
2
12 4 2 2
CDCCCDCCDCDC
8 2 1 3
DCCCCCDC
```

#### 输出样例2：

```
Case #1: YES
Case #2: NO
```

#### 样例2解释

在 Case 1 中，每只狗喂食完毕后，都会额外得到两份猫粮。

1. 首先是一只猫，喂食它后，还剩下 1 份猫粮。
2. 接下来是一只狗，喂食它后，还剩下 3 份狗粮和 3 份猫粮。
3. 接下来是三只猫，喂食它们后，还剩下 3 份狗粮和 0 份猫粮。
4. 接下来是一只狗，喂食它后，还剩下 2 份狗粮和 2 份猫粮。
5. 接下来是两只猫，喂食它们后，还剩下 2 份狗粮和 0 份猫粮。
6. 接下来是一只狗，喂食它后，还剩下 1 份狗粮和 2 份猫粮。
7. 接下来是一只猫，喂食它后，还剩下 1 份狗粮和 1 份猫粮。
8. 接下来是最后一只狗，喂食它后，还剩下 0 份狗粮和 3 份猫粮。

所有狗都被喂食。

在 Case 2 中，第二只狗前面的猫得不到喂食，所有第二只狗也没法得到喂食。



### 算法思路

直接模拟即可。需要注意的是`N*M`可能会超过`INT_MAX`，所以需要使用`long long int`存储。

```c++
//
//  main.cpp
//  4118-狗和猫
//
//  Created by MacBook Pro on 2023/8/9.
//

#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        long long N,D,C,M;
        scanf("%lld%lld%lld%lld",&N,&D,&C,&M);
        string s;
        cin>>s;
        //模拟猫狗进食
        bool flag=true;
        for(int i=0;i<N;i++){
            if(s[i]=='D'){
                if(D<=0){
                    flag=false;
                    break;
                }
                D--;
                C+=M;
            }
            else{
                if(C<=0){
                    //判断后面是否还有狗
                    bool is_dog=false;
                    for(int j=i+1;j<N;j++){
                        if(s[j]=='D'){
                            is_dog=true;
                            break;
                        }
                    }
                    if(is_dog){
                        flag=false;
                        break;
                    }
                    break;
                }
                C--;
            }
        }
        printf("Case #%d: ",cases);
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}

```

