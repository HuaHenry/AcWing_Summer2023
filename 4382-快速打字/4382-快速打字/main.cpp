//
//  main.cpp
//  4382-快速打字
//
//  Created by MacBook Pro on 2023/7/16.
//

#include <iostream>
using namespace std;

int T;
string I,P;

int main() {
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>I>>P;
        if(P.size()<I.size()){
            cout<<"Case #"<<i+1<<": "<<"IMPOSSIBLE"<<endl;
            continue;
        }
        //双指针开始遍历
        int l=0,r=0;
        bool ans=false;
        int res=0;
        while(true){
            if(I[l]==P[r]){
                //匹配，就直接后移一位
                l++; r++;
            }
            else{
                //不匹配，删去一位r
                res++;
                r++;
            }
            //判断是否结束
            if(l>=I.size()){
                ans=true;
                if(r<P.size()){
                    res+=(P.size()-r);
                }
                break;
            }
            else if(l<I.size()&&r>=P.size()){
                //不能满足
                ans=false;
                break;
            }
        }
        if(ans) cout<<"Case #"<<i+1<<": "<<res<<endl;
        else cout<<"Case #"<<i+1<<": "<<"IMPOSSIBLE"<<endl;
    }
}
