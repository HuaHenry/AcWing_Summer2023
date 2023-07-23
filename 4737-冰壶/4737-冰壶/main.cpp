//
//  main.cpp
//  4737-冰壶
//
//  Created by MacBook Pro on 2023/7/23.
//

#include <iostream>
#include <vector>
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
