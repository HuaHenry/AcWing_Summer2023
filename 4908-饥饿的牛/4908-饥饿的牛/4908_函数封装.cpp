//
//  main.cpp
//  4908-饥饿的牛
//
//  Created by MacBook Pro on 2023/7/14.
//

#include <iostream>
#include <map>
using namespace std;

long long int N,T;
long long int nums=0;
long long int day_before=1;
long long int ans=0;

void deal_duration(long long int duration){
    if(duration<=nums){
        nums-=duration;
        ans+=duration;
    }
    else{
        ans+=nums;
        nums=0;
    }
}

int main(){
    cin>>N>>T;
    for(long long int i=0;i<N;i++){
        long long int di,bi;
        scanf("%lld %lld",&di,&bi);
        deal_duration(di-day_before);
        day_before=di;
        nums+=bi;
    }
    deal_duration(T+1-day_before);
    cout<<ans<<endl;
}
