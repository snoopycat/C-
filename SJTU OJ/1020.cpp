#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int main()
{
    int N,tmp(0), ans[40], pow[40];
    memset(pow,0,sizeof(pow));
    cin >> N;
    int num = N;
    for(int i = 2; i <= sqrt(num); i++){
        if(num%i==0){
            ans[++tmp] = i;
            while(num%i==0){
                num/=i;
                ++pow[tmp];
            }
        }
    }
    if(num!=1){
        ans[++tmp] = num;
        pow[tmp] = 1;
    }
    cout << N << "=";
    for(int i = 1; i <= tmp; i++){
        cout << ans[i] << "(" << pow[i] << ")";
    }
    return 0;
}
