//
//  main.cpp
//  4440-照相
//
//  Created by MacBook Pro on 2023/7/15.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string x;
int flag[300000];

int main() {
    scanf("%d",&n);
    cin>>x;
    int check=-1;
    int cnt=0;
    for(int i=0;i<n;i+=2){
        if(x[i]=='G'&&x[i+1]=='H'){
            //需要调换
            flag[cnt++]=1;
        }
        else if(x[i]=='H'&&x[i+1]=='G'){
            //不需要调换
            flag[cnt++]=0;
        }
    }
    int ans=0;
    for(int i=0;i<cnt;i++){
        if(flag[i]!=flag[i+1]) ans++;
    }
    cout<<ans<<endl;
}
