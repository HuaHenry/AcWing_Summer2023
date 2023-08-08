//
//  main.cpp
//  3752-更小的字符串
//
//  Created by MacBook Pro on 2023/8/8.
//

/* 算法：数位统计 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010, MOD = 1e9 + 7;

int n, m;
char s[N];
int p[N];

int main()
{
    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++ )
    {
        scanf("%d%d", &n, &m);
        scanf("%s", s);

        p[0] = 1;
        for (int i = 1; i <= n; i++ )
            p[i] = (LL)p[i - 1] * m % MOD;  //m的i次方计算

        int res = 0;
        int mid = (n + 1) / 2;              //自由度计算
        for (int i = 0; i < mid; i++ )     //计算每一位 - 非相等情况的自由数
        {
            res += (LL)(s[i] - 'a') * p[mid - i - 1] % MOD; //中间值到本位的最高自由数
            res %= MOD;
        }

        int t = 0;
        for (int i = mid - 1, j = n - 1 - i; i >= 0; i --, j ++ )
            if (s[i] != s[j])
            {
                if (s[i] < s[j]) t = 1;
                break;
            }

        res = (res + t) % MOD;
        
        printf("Case #%d: %d\n", cases, res);
    }

    return 0;
}
