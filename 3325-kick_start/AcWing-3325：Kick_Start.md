# AcWing-3325：Kick_Start

### 题目描述

![image-20230811210809209](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230811210809209.png)

#### 输入样例：

```
3
AKICKSTARTPROBLEMNAMEDKICKSTART
STARTUNLUCKYKICK
KICKXKICKXSTARTXKICKXSTART
```

#### 输出样例：

```
Case #1: 3
Case #2: 0
Case #3: 5
```



### 算法求解

枚举问题，题目本意是要找出所有`KICK`开头`START`结尾的字符串个数，可以通过一次遍历字符串实现：

使用一个变量`nums`记录当前的`KICK`个数

- 遇到一个`KICK`，`nums`自增
- 遇到一个`START`，结果增加一个`nums`值，即所有在他前面的`KICK`都可以与之组成一个符合要求的字符串。

可以通过`substr`函数实现。

Code：

```c++
//
//  main.cpp
//  3325-kick_start
//
//  Created by MacBook Pro on 2023/8/11.
//

#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        string s;
        cin>>s;
        int nums = 0;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s.substr(i,4)=="KICK"){
                nums++;
                i+=2;
            }
            else if(s.substr(i,5)=="START"){
                ans += nums;
                i+=4;
            }
        }
        printf("Case #%d: %d\n",cases,ans);
    }
}

```

