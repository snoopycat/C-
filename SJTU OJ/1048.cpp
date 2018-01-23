#include <iostream>
#include <cstdio>
#include <queue>
#define N 1024

using namespace std;

struct nodeinfo{
    int l = 0, r = 0, pre = 0;
}tree[N];

int main()
{
    int n, root, node, l, r;
    scanf("%d",&n);
    while(scanf("%d%d%d",&node,&l,&r) != EOF){
        tree[node].l = l;
        tree[node].r = r;
        tree[r].pre = node;
        tree[l].pre = node;
    }
    for(int i = 1; i <= n; i++){
        if(!tree[i].pre){
            root = i;
            break;
        }
    }
    queue<int> record;
    record.push(root);
    while(!record.empty()){
        int tmp = record.front();
        record.pop();
        printf("%d\n",tmp);
        if(tree[tmp].l) record.push(tree[tmp].l);
        if(tree[tmp].r) record.push(tree[tmp].r);
    }
    return 0;
}
