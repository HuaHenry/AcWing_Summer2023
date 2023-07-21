//
//  main.cpp
//  4726-步行者
//
//  Created by MacBook Pro on 2023/7/21.
//

#include <iostream>
#include <cstring>
using namespace std;

int john[35];       //JOHN每日步数
int maxstep[35];    //每日最高步数

int main() {
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        memset(maxstep,0,sizeof(maxstep));
        int M,N,P;
        long long int ans=0;
        scanf("%d%d%d",&M,&N,&P);
        for(int id=1;id<=M;id++){
            for(int days=1;days<=N;days++){
                int x;
                scanf("%d",&x);
                if(id==P){
                    //是john
                    john[days]=x;
                }
                maxstep[days]=max(maxstep[days],x);
            }
        }
        //cal bias
        for(int i=1;i<=N;i++){
            ans+=maxstep[i]-john[i];
        }
        printf("Case #%d: %lld\n",cases,ans);
    }
}
