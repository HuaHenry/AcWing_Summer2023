# Acwing-4382：打字

![image-20230716210614466](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230716210614466.png)

![image-20230716210630117](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230716210630117.png)

基本思路是两个字符串各开一个指针，`l`表示字符串`I`的指针，`r`表示字符串`P`的指针。

- Case1：`I[l]==P[r]` 则两个指针都自增，开始比较后一位
- Case2：`I[l]!=P[r]` 则`r++`，表示删除该位。

case2的合理性在于，即使前后出现了重复的符合片段，如`I="abcde"`，`P="abcfffabcde"`，不需要考虑abc取前面的还是后面的，因为在这种逻辑下取了前面的，继续匹配必然将`fffabc`删除。

设置判断的边界调节：

- 如果`l`指针已经到达`I`的末尾🔚，此时如果`r`还没有到达`P`的末尾，则需要删除`r`后面的所有字符。
- 如果`r`指针已经到达`P`的 末尾，但是`l`还没有到达`I`的末尾，即再怎么删也删不出理想的造型，那么就判定为不可达。

Code：

```c++
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

```

![image-20230716211638974](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230716211638974.png)