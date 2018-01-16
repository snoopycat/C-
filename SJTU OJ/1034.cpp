#include <iostream>
#include <queue>
#include <cstdio>
#include <string.h>

using namespace std;

int rp[200000+1000];
int p[1000];
int top(0), rear(0);

bool empty()
{
    return top == rear;
}

void in(int x)
{
    while(!empty()){
        if(p[rear-1] < x)
            rear--;
        else
            break;
    }
    p[rear++] = x;
}

void out(int x)
{
    if(p[top]==x)
        top++;
}

int main()
{
    int N, K;
    int res(0);
    memset(p,0,1000);
    scanf("%d%d",&N,&K);
    for(int i = 1; i <= N; ++i){
        scanf("%d",&rp[i]);
        if(i<=K-1)
            rp[N+i] = rp[i];
    }
    for(int i = 1; i <= K; ++i){
        res = max(res,rp[i]);
        in(rp[i]);
    }
    for(int i = K+1; i <= N+K-1; ++i){
        out(rp[i-K]);
        in(rp[i]);
        res = min(res,p[top]);
    }
    cout << res;
    return 0;
}
