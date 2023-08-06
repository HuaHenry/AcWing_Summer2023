//
//  main.cpp
//  3321-ATM队列
//
//  Created by MacBook Pro on 2023/8/6.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <cmath>
using namespace std;

struct person{
    int num;    //编号
    int times;  //取钱次数
};

vector<person> que;

bool cmp(const person& p1,const person& p2){
    if(p1.times!=p2.times) return p1.times<p2.times;
    else{
        return p1.num<p2.num;
    }
}

int main() {
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        que.clear();
        int N,X;
        scanf("%d%d",&N,&X);
        for(int i=1;i<=N;i++){
            int tmp;
            scanf("%d",&tmp);
            que.push_back({i,int(ceil(double(tmp)/X))});
        }
        sort(que.begin(),que.end(),cmp);
        printf("Case #%d:",cases);
        for(int i=0;i<que.size();i++){
            printf(" %d",que[i].num);
        }
        printf("\n");
    }
    return 0;
}
