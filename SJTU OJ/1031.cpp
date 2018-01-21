#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

int h[10001],l[10001], N, M;

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> h[i];
    for(int i = 0; i < M; i++) cin >> l[i];
    sort(h,h+N);
    sort(l,l+M);
    int j(0);
    for(int i = 0; i < N; i++){
        if(h[i]>l[j]&&j<M) ++j;
    }
    cout << N+j << endl;
    return 0;
}
