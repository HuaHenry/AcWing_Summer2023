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
