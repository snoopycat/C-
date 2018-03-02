#include <cstdio>
#include <queue>

using namespace std;

int n, F;
int girls[100001] = {0}, pre[100001] = {0};

int main() {
	scanf("%d%d",&n,&F);
	for(int i = 1; i <= n; i++){
        scanf("%d", &girls[i]);
        pre[i] = pre[i-1]+girls[i];
	}
    int ans = -1;
    for(int i = 0, j = 0; i <= n-F; i++){
        if(i>j && (pre[i]-pre[j])*(F) < (pre[i+F]-pre[i])*(i-j))
            j = i;
        ans = max(ans,1000*(pre[i+F]-pre[j])/(i-j+F));
    }
    printf("%d\n",ans);
	return 0;
}

