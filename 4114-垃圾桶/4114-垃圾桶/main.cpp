//
//  main.cpp
//  4114-垃圾桶
//
//  Created by MacBook Pro on 2023/8/12.
//

#include <iostream>
#include <math.h>
using namespace std;

// O(n^2) 时间复杂度过高
//int main() {
//    int T;
//    scanf("%d",&T);
//    for(int cases=1;cases<=T;cases++){
//        int N;
//        scanf("%d",&N);
//        char s[500005];
//        scanf("%s",s);
//        long long ans = 0;
//        for(int i=0;i<N;i++){
//            if(s[i]=='0'){
//                //寻找垃圾桶
//                int offset = 1;
//                while(true){
//                    if((i+offset<N && s[i+offset]=='1')||(i-offset>=0 && s[i-offset]=='1')) break;
//                    else offset++;
//                }
//                ans += offset;
//            }
//        }
//        printf("Case #%d: %lld\n",cases,ans);
//    }
//}

char s[500005];
int lefts[500005],rights[500005]; //分别存储左右最近

// O(n) 存储法
int main() {
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        int N;
        scanf("%d",&N);
        scanf("%s",s+1);
        long long ans = 0;
        //dp思想
        lefts[0] = -1e6; rights[N + 1] = 1e6;
        for(int i=1;i<=N;i++){
            lefts[i]=(s[i]=='1'?i:lefts[i-1]);
        }
        for(int i=N;i>=1;i--){
            rights[i]=(s[i]=='1'?i:rights[i+1]);
        }
        //O(N)求结果
        for(int i=1;i<=N;i++){
            ans += min(i-lefts[i],rights[i]-i);
        }
        printf("Case #%d: %lld\n",cases,ans);
    }
}
