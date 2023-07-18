//
//  main.cpp
//  4742-电
//
//  Created by HzzzQ's MacBook Pro on 2023/7/17.
//  Tongji University, Shanghai, China
//

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <unordered_map>
//#include <cstring>
//using namespace std;
//
//const int N = int(2e5+5);
//
//struct Node{
//    int lstn;   //节点编号
//    int num;    //电容值
//    int tog;    //连通电压的总节点
//    vector<int> neigh;  //电容小于该节点且相连的节点
//}list[N];
//
//bool cmp(Node& p1,Node& p2){
//    return p1.num<p2.num;
//}
//
//int main() {
//    int T;
//    scanf("%d",&T);
//    for(int index=1;index<=T;index++){
//        memset(list,0,sizeof(list));
//        int N;
//        scanf("%d",&N);
//        for(int i=1;i<=N;i++){
//            list[i].lstn=i;
//            scanf("%d",&list[i].num);   //录入电容值
//        }
//        for(int i=0;i<N-1;i++){
//            int x1,x2;
//            scanf("%d%d",&x1,&x2);
//            if(list[x1].num<list[x2].num)
//                list[x2].neigh.push_back(x1);
//            else if(list[x1].num>list[x2].num)
//                list[x1].neigh.push_back(x2);
//        }
//        //按照电容值排序
//        int ans=0;
//        sort(list+1,list+N+1,cmp);
//        int Maps[N];
//        for(int i=1;i<=N;i++){
//            Maps[list[i].lstn]=i;       //录入转换后的节点编号和位置对应关系
//        }
//        for(int i=1;i<=N;i++){
//            int nodeLight=0;
//            for(int ii=0;ii<list[i].neigh.size();ii++){
//                nodeLight+=list[Maps[list[i].neigh[ii]]].tog;
//            }
//            list[i].tog=nodeLight+1;
//            if(list[i].tog>ans)
//                ans=list[i].tog;
//        }
//        printf("Case #%d: %d\n",index,ans);
//    }
//}

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

const int N = int(2e5+5);

struct Node{
    int num;    //电容值
    vector<int> neigh;  //电容小于该节点且相连的节点
}list[N];

int val[N];     //记忆化数组

int dfs(int index){
    //计算index的总亮数
    if(val[index]!=0) return val[index];
    
    int temp=1;
    for(int i=0;i<list[index].neigh.size();i++){
        temp+=dfs(list[index].neigh[i]);
    }
    val[index]=temp;
    return temp;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int index=1;index<=T;index++){
        memset(list,0,sizeof(list));
        memset(val,0,sizeof(val));
        int N;
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            scanf("%d",&list[i].num);   //录入电容值
        }
        for(int i=0;i<N-1;i++){
            int x1,x2;
            scanf("%d%d",&x1,&x2);
            if(list[x1].num<list[x2].num)
                list[x2].neigh.push_back(x1);
            else if(list[x1].num>list[x2].num)
                list[x1].neigh.push_back(x2);   //只存储有效边
        }
        int ans=0;      //结果
        for(int i=1;i<=N;i++){
            ans=max(ans,dfs(i));
        }
        printf("Case #%d: %d\n",index,ans);
    }
}
