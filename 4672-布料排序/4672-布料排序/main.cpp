//
//  main.cpp
//  4672-布料排序
//
//  Created by MacBook Pro on 2023/7/25.
//

#include <iostream>
using namespace std;

struct node{
    string c;
    int d;
    int id;
}nums1[1005],nums2[1005];

bool sort1(node& x1,node& x2){
    if(x1.c==x2.c){
        return x1.id<x2.id;
    }
    return x1.c<x2.c;
}

bool sort2(node& x1,node& x2){
    if(x1.d==x2.d){
        return x1.id<x2.id;
    }
    return x1.d<x2.d;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            cin>>nums1[i].c;
            scanf("%d%d",&nums1[i].d,&nums1[i].id);
            nums2[i].c=nums1[i].c;
            nums2[i].d=nums1[i].d;
            nums2[i].id=nums1[i].id;
        }
        //排序方法
        sort(nums1,nums1+n,sort1);
        sort(nums2,nums2+n,sort2);
//        for(int i=0;i<n;i++) cout<<"\t ******"<<nums1[i].id<<endl;
//        for(int i=0;i<n;i++) cout<<"\t ******"<<nums2[i].id<<endl;

        //检测重合个数
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums1[i].id==nums2[i].id) ans++;
        }
        cout<<"Case #"<<cases<<": "<<ans<<endl;
    }
}
