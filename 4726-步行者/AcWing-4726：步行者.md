# AcWing-4726：步行者

![image-20230721093450702](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230721093450702.png)

![image-20230721093518670](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230721093518670.png)



该题是个很简单的求差`模拟`问题，很方便的解决方法是存储两个数组，`maxstep`存储每日最高步数，`john`存储每日john这个家伙的步数，最后做差即可。

时间复杂度最高的地方在于输入，达到`O(MN)`，后续处理复杂度较低，空间复杂度较高，达到`O(N)`，实际上是`2N`。

Code：

```c++
//
//  main.cpp
//  4726-步行者
//
//  Created by MacBook Pro on 2023/7/21.
//

#include <iostream>
#include <cstring>
using namespace std;

int john[35];       //JOHN每日步数
int maxstep[35];    //每日最高步数

int main() {
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        memset(maxstep,0,sizeof(maxstep));
        int M,N,P;
        long long int ans=0;
        scanf("%d%d%d",&M,&N,&P);
        for(int id=1;id<=M;id++){
            for(int days=1;days<=N;days++){
                int x;
                scanf("%d",&x);
                if(id==P){
                    //是john
                    john[days]=x;
                }
                maxstep[days]=max(maxstep[days],x);
            }
        }
        //cal bias
        for(int i=1;i<=N;i++){
            ans+=maxstep[i]-john[i];
        }
        printf("Case #%d: %lld\n",cases,ans);
    }
}

```

⚠️ 需要注意的是每一组数据处理前一定要**清空**`maxstep`数组！