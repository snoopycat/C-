#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int S, T, dp[200001], tmp, ans(1);
    long long times[200001],repeat(0);
    cin >> S >> T;
    /*memset(repeat,0,sizeof(repeat));*/
    for(int i = S; i <= T; i++){
        dp[i] = times[i] = 1;
    }
    for(int i = S; i <= T; i++){
        for(int j = 1; j <= 100; j++){
            if(i*j%100 == 0){
                tmp = i + i*j/100;
                if(tmp <= T){
                    if(dp[tmp] < dp[i]+1){
                        dp[tmp] = dp[i]+1;
                        times[tmp] = times[i];
                    }
                    else if(dp[tmp]==dp[i]+1){
                        times[tmp] += times[i];
                    }
                    /*ans = max(dp[tmp],ans);
                    repeat[dp[i]+1] += times[i];*/
                }
            }
        }
    }
    for(int i = 0; i <= T; i++){
        if(ans<dp[i]){
            ans = dp[i];
            repeat = times[i];
        }
        else if(ans == dp[i])
            repeat+=times[i];
    }
    cout << ans << endl << repeat;
    return 0;
}
