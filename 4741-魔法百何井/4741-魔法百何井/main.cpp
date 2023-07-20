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
