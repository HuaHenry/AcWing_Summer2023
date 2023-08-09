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
