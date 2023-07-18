# Acwing-4440：照相

![image-20230716002149091](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230716002149091.png)

> ```cpp
> Key1 -> 偶数 N 头牛顺次两两一组，无论如何反转，组内并不会破坏相邻关系
> Key2 -> 组类有四种：GG HH GH HG，反转过程中 GG HH 无影响，可忽略，
>         问题简化为尽可能多得将 GH 转化为 HG
> Key3 -> 将 GH HG 分别用 1 0 替代，问题即尽可能将 1 转化为 0
> Key4 -> 一串由 0 1 构成的数组，反转次数就是间隔数(两边是相异的数) + 0 or 1
>         若最后一个数是 0，则加 0；若最后一个数是 1，则加 1.
> ```

code：

```c++
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

```

 