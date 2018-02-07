#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, C, color;
int balls[110], deal[101][101];

void put_balls()
{
    deal[0][0] = 1;
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= i; j++){
            deal[i][j] = deal[i-1][j-1];
            if(i-j>0) deal[i][j]+=deal[i-j][j];
        }
    }
}

int main()
{
    cin >> N >> C;
    long long ways(1);
    memset(balls,0,sizeof(balls));
    put_balls();
    for(int i = 0; i < N; i++){
        cin >> color;
        ++balls[color];
    }
    for(int i = 0; i < 110; i++){
        int ans = 0;
        //cout << i << " " << balls[i] << endl;
        if(balls[i]){
            for(int j = 1; j <= balls[i]; j++)
                ans+=deal[balls[i]][j];
            ways *= ans;
        }
    }
    cout << ways;
    return 0;
}
