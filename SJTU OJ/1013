#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int V, N, v, w, res(0), f[10001];
    memset(f,0,sizeof(f));
    cin >> V >> N;
    for(int i = 1; i <= N; i++){
        cin >> v >> w;
        for(int j = v; j <= V; j++)f[j] = max(f[j],f[j-v]+w);
    }
    for(int i = 1; i <= V; i++)res = max(res,f[i]);
    cout << res;
    return 0;
}
