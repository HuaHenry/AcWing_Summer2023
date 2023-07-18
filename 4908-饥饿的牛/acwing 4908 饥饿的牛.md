# acwing 4908 饥饿的牛

![image-20230714094854705](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230714094854705.png)

![image-20230714094924562](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230714094924562.png)

本题本人的初始思路是使用差分离散化存储的方式，接着遍历所有日期并判断是否符合要求。时间复杂度为`O(T)`，指数级为14次。

```c++
//
//  main.cpp
//  4908-饥饿的牛
//
//  Created by MacBook Pro on 2023/7/14.
//

#include <iostream>
#include <map>
using namespace std;

int N,T;
// 非可行算法——差分离散化后模拟导致复杂度过高
//unordered_map<int, int> nums;   //存储差分数组
//
//int main(int argc, const char * argv[]) {
//    //差分离散化
//    cin>>N>>T;
//    for(int i=0;i<N;i++){
//        int index;
//        cin>>index;
//        cin>>nums[index];
//    }
//    int ans=0;
//    int day=0;
//    for(int i=1;i<=T;i++){
//        if(nums.find(i)!=nums.end()){
//            day+=nums[i];
//        }
//        if(!day){
//            ans++;
//        }
//        else{
//            day--;
//        }
//    }
//    cout<<T-ans<<endl;
//    return 0;
//}

int main(){
    cin>>N>>T;
    int nums=0;
    int day_before=1;
    long long int ans=0;
    for(int i=0;i<N;i++){
        int di,bi;
        scanf("%d %d",&di,&bi);
        int duration=di-day_before; //上一次喂干草的历时（不包含di）
        if(duration<=nums){
            nums-=duration;
            ans+=duration;
        }
        else{
            ans+=nums;
            nums=0;
        }
        day_before=di;
        nums+=bi;
    }
    int duration=T+1-day_before; //上一次喂干草的历时（不包含di）
    if(duration<=nums){
        ans+=duration;
    }
    else{
        ans+=nums;
    }
    cout<<ans<<endl;
    
}

```

该种方法时间复杂度过高，该进为遍历所有输入情况，并将本次输入和上次输入之间的时间计算中间结果。注意需要处理末尾的情况。

思路和`@zzc`相同 Code：

```c++
int main(){
    cin>>N>>T;
    int nums=0;
    int day_before=1;
    long long int ans=0;
    for(int i=0;i<N;i++){
        int di,bi;
        scanf("%d %d",&di,&bi);
        int duration=di-day_before; //上一次喂干草的历时（不包含di）
        if(duration<=nums){
            nums-=duration;
            ans+=duration;
        }
        else{
            ans+=nums;
            nums=0;
        }
        day_before=di;
        nums+=bi;
    }
    int duration=T+1-day_before; //上一次喂干草的历时（不包含di）
    if(duration<=nums){
        ans+=duration;
    }
    else{
        ans+=nums;
    }
    cout<<ans<<endl;
    
}
```

![image-20230714095532281](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230714095532281.png)