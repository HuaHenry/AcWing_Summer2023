//
//  main.cpp
//  4443-无限区域
//
//  Created by MacBook Pro on 2023/8/7.
//

#include <iostream>
#include <algorithm>
using namespace std;

const double pai = 3.141592654;

int main() {
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        int r,a,b;
        scanf("%d%d%d",&r,&a,&b);
        double ans = .0;
        while(r!=0){
            ans += pai*r*r;
            r = a*r;
            ans += pai*r*r;
            r = floor(double(r)/b);
        }
        printf("Case #%d: %lf\n",cases,ans);
    }
}
