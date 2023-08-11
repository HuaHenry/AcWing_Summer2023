//
//  main.cpp
//  3748-递增子串
//
//  Created by MacBook Pro on 2023/8/10.
//

#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        int n;
        string s;
        cin>>n>>s;
        int bef = 0;
        printf("Case #%d:",cases);
        for(int i=0;i<n;i++){
            if(i>0 && s[i]>s[i-1]){
                printf(" %d",++bef);
            }
            else{
                printf(" %d",1);
                bef = 1;
            }
            
        }
        printf("\n");
    }
}
