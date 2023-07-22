# AcWing-4738：快乐子数组

![image-20230722214536558](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230722214536558.png)

![image-20230722214552840](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230722214552840.png)

该题由于数据量的关系，只能支持`O(n)`的时间复杂度，故前缀和+双指针的方法依然是复杂度过高的。故这里需要进行一些数学的推导：

假设前缀和数组是`S`，即原数组元素`I[x]=S[x]-S[x-1]`。那么需要符合要求的“快乐连续子数组”只需要确定起始位置`i`，然后找第一个`S[x]-S[i-1]<0`，即找到第一个`S[x]<S[i-1]`，问题就转换为，找到前缀和数组每个元素“右边”的第一个比他小的元素。

这种问题可以通过**单调栈**解决：

![image-20230722221057646](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230722221057646.png)

第二个技巧是二重前缀和，即为前缀和数组的二次前缀和，有效避免循环中累加。

Code：

```c++
#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

const int N = 4e5 + 10;
long long p[N], pp[N], r[N];

int main () {
    int T; cin >> T;
    for (int t = 1; t <= T; t ++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i ++) {
            int x; scanf("%d", &x);
            p[i] = p[i - 1] + x;
            pp[i] = pp[i - 1] + p[i];
        }

        stack<int> stk;
        stk.push(n + 1), p[n + 1] = -1e9;
        for (int i = n; i >= 0; i --) {
            while (p[i] <= p[stk.top()]) {
                stk.pop();
            }
            r[i + 1] = stk.top() - 1;
            stk.push(i);
        }

        long long res = 0;
        for (int i = 1; i <= n; i ++) {
            int j = r[i];
            res += pp[j] - pp[i - 1] - (j - i + 1) * p[i - 1];
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}
```

![image-20230722221542833](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230722221542833.png)