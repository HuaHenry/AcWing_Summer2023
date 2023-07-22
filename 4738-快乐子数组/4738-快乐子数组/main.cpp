//
//  main.cpp
//  4738-快乐子数组
//
//  Created by MacBook Pro on 2023/7/22.
//

//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int nums[400005];   //前缀和数组
//
////双指针 判读该区间是否是快乐子数字
//bool detfun(int l,int r){
//    int bases = nums[l-1];
//    for(int i=l;i<=r;i++){
//        if(nums[i]<bases) return false;
//    }
//    return true;
//}
//
//int main() {
//    int T;
//    scanf("%d",&T);
//    for(int cases=1;cases<=T;cases++){
//        memset(nums,0,sizeof(nums));
//        int n;
//        scanf("%d",&n);
//        for(int i=1;i<=n;i++){
//            scanf("%d",&nums[i]);
//            nums[i]+=nums[i-1];     //前缀和计算
//        }
//        long long int ans=0;
//        for(int i=1;i<=n;i++){
//            for(int j=i;j<=n;j++){
//                if(detfun(i, j)) ans+=nums[j]-nums[i-1];
//                else break;
//            }
//        }
//        printf("Case #%d: %lld\n",cases,ans);
//    }
//}

// 二重前缀和
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
        stk.push(n + 1);
        p[n + 1] = -1e9;
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


