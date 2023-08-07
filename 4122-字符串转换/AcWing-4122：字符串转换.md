# AcWing-4122：字符串转换

![image-20230807135356470](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230807135356470.png)

![image-20230807135411787](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230807135411787.png)

#### 输入样例1：

```
2
abcd
a
pppp
p
```

#### 输出样例1：

```toml
Case #1: 6
Case #2: 0
```

#### 输入样例2：

```
3
pqrst
ou
abd
abd
aaaaaaaaaaaaaaab
aceg
```

#### 输出样例2：

```toml
Case #1: 9
Case #2: 0
Case #3: 1
```



本题的就是简单的枚举问题，遍历每一个`s`字符串中的字符，找26个字母中最接近且在`f`中的字符即可。

Code：

```c++
//
//  main.cpp
//  4122-字符串转换
//
//  Created by MacBook Pro on 2023/8/7.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++)
    {
        string s, f;
        cin >> s >> f;
        int cnt = 0;
        for (int i = 0; i < int(s.length()); i++)
        {
            int ans = INT_MAX;
            for (int j = 0; j < int(f.length()); j++){
                ans=min(ans,min(abs(s[i]-f[j]),26-abs(s[i]-f[j])));
            }
            cnt += ans;
        }
        printf("Case #%d: %d\n", cases, cnt);
    }
    return 0;
}
```

![image-20230807135633747](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230807135633747.png)