# AcWing-4737：冰壶

![image-20230723200626091](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230723200626091.png)

![image-20230723200640404](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230723200640404.png)

#### 输入样例1：

```
2
1 5
4
1 -1
6 1
0 6
-5 0
0
10 100
2
-3 -4
200 200
0
```

#### 输出样例1：

```sql
Case #1: 3 0
Case #2: 1 0
```

#### 样例1解释

Case 1 的冰壶分布情况如下图所示。

![QQ截图20221109145214.png](https://cdn.acwing.com/media/article/image/2022/11/09/19_121250515f-QQ%E6%88%AA%E5%9B%BE20221109145214.png)

在这种情况下，黄队没有冰壶在得分区域内，所以红队在得分区域内的每个冰壶都是得分冰壶。

红队除了以 (6,1) 为圆心的那个冰壶以外，其他所有的冰壶都在得分区域内，所以红队得 3 分。

#### 输入样例2：

```
2
1 5
2
1 0
-3 0
1
0 2
10 50
2
-40 -31
-35 70
3
59 0
-10 0
30 40
```

#### 输出样例2：

```sql
Case #1: 1 0
Case #2: 0 2
```

#### 样例2解释

Case 1 的冰壶分布情况如下图所示。

![QQ截图20221109145734.png](https://cdn.acwing.com/media/article/image/2022/11/09/19_e104dffe5f-QQ%E6%88%AA%E5%9B%BE20221109145734.png)

在这种情况下，两支队伍都有冰壶在得分区域内。

红队圆心为 (1,0) 的冰壶在得分区域内，且没有黄队的冰壶比它距离得分中心更近，所以它值 1 分。

红队圆心为 (−3,0) 的冰壶在得分区域内，但是黄队圆心为 (0,2) 的冰壶比它距离得分中心更近，所以它不能得分。

黄队圆心为 (0,2) 的冰壶在得分区域内，但是红队圆心为 (1,0) 的冰壶比它距离得分中心更近，所以它不能得分。

因此，红队得 1 分，黄队得 0 分。





**解题思路**：非常简单的模拟+枚举问题，主要思路为分别存储红队和黄队**在得分区内**的冰壶位置，使用`vector<pair<int,int>>`存储，并在输入时分别记录两队得分区内距离原点最近的冰壶。

当输入和存储完毕，只需要比较两队距离原点最近的冰壶分别的距离，如果不一致，那么距离大的必定得分为0，接着计算距离小的一队得分即可。如果距离相等，那么会有两种情况——都不在得分区，或都有得分区内的冰壶且最小距离相等，那么分别计算即可。

Code：

```c++
//
//  main.cpp
//  4737-冰壶
//
//  Created by MacBook Pro on 2023/7/23.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int T;

vector<pair<int,int>> red;
vector<pair<int,int>> yel;


int main() {
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        red.clear(); yel.clear();
        int rs,rh,n,m;
        int x1=-1,y1=-1,x2=-1,y2=-1;
        int len1=INT_MAX,len2=INT_MAX;
        scanf("%d%d",&rs,&rh);
        //red
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x*x+y*y<=(rs+rh)*(rs+rh)){
                //得分区内
                red.push_back({x,y});
                if(x*x+y*y<len1){
                    len1=x*x+y*y;
                    x1=x; y1=y;
                }
            }
        }
        //yellow
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x*x+y*y<=(rs+rh)*(rs+rh)){
                //得分区内
                yel.push_back({x,y});
                if(x*x+y*y<len2){
                    len2=x*x+y*y;
                    x2=x; y2=y;
                }
            }
        }
        //conclude
        if(len1<len2){
            //red更有优势
            int ans=0;
            for(int i=0;i<red.size();i++){
                int x=red[i].first,y=red[i].second;
                if(x*x+y*y<=len2) ans++;
            }
            printf("Case #%d: %d 0\n",cases,ans);
        }
        else if(len1>len2){
            //yellow更有优势
            int ans=0;
            for(int i=0;i<yel.size();i++){
                int x=yel[i].first,y=yel[i].second;
                if(x*x+y*y<=len1) ans++;
            }
            printf("Case #%d: 0 %d\n",cases,ans);
        }
        else{
            //相同
            int ans1=0,ans2=0;
            for(int i=0;i<yel.size();i++){
                int x=yel[i].first,y=yel[i].second;
                if(x*x+y*y<=len1) ans1++;
            }
            for(int i=0;i<red.size();i++){
                int x=red[i].first,y=red[i].second;
                if(x*x+y*y<=len2) ans2++;
            }
            printf("Case #%d: %d %d\n",cases,ans1,ans2);
        }
    }
    return 0;
}

```

![image-20230723201135330](/Users/macbookpro/Library/Application Support/typora-user-images/image-20230723201135330.png)