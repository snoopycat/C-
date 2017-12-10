#include <iostream>
#include <string.h>
#include <cmath>
#include <string>
#include <stdio.h>

using namespace std;


int main()
{
    int M, ans(0);
    cin >> M;
    int k[M-1];
    for(int i = 0; i < M-1; i++){
        cin >> k[i];
    }
    for(int i = 2; i <= M; i++){
        ans = (ans+k[M-i])%i;
    }
     return 0;
}
