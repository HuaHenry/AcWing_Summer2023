//
//  main.cpp
//  4122-字符串转换
//
//  Created by MacBook Pro on 2023/8/7.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++)
    {
        string s, f;
        cin >> s >> f;
        int cnt = 0;
        for (int i = 0; i < int(s.length()); i++)
        {
            int ans = INT_MAX;
            for (int j = 0; j < int(f.length()); j++){
                ans=min(ans,min(abs(s[i]-f[j]),26-abs(s[i]-f[j])));
            }
            cnt += ans;
        }
        printf("Case #%d: %d\n", cases, cnt);
    }
    return 0;
}
