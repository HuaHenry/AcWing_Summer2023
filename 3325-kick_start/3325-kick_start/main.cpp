//
//  main.cpp
//  3325-kick_start
//
//  Created by MacBook Pro on 2023/8/11.
//

#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        string s;
        cin>>s;
        int nums = 0,ans = 0;
        for(int i=0;i<s.size();i++){
            if(s.substr(i,4)=="KICK"){
                nums++;
                i+=2;
            }
            else if(s.substr(i,5)=="START"){
                ans += nums;
                i+=4;
            }
        }
        printf("Case #%d: %d\n",cases,ans);
    }
}
