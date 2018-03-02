#include <cstdio>
#include <queue>
 
using namespace std;
 
int n, m, op, a, b;
priority_queue<int,vector<int>,greater<int> > girls[300010];
 
 
int main() {
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
        scanf("%d",&a);
        girls[i].push(a);
	}
	for(int i = 0; i < m; i++){
        scanf("%d",&op);
        switch(op){
            case 0:
                scanf("%d%d",&a,&b);
                while(!girls[b].empty()){
                    girls[a].push(girls[b].top());
                    girls[b].pop();
                }
                break;
            case 1:
                scanf("%d",&a);
                if (girls[a].empty()) printf("%d\n",-1);
                else {
                    printf("%d\n",girls[a].top());
                    girls[a].pop();
                }
                break;
            case 2:
                scanf("%d%d",&a,&b);
                girls[a].push(b);
                break;
        }
	}
	return 0;
}
