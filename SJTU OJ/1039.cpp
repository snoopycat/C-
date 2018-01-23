#include <iostream>
#include <string.h>
#define N 30010

using namespace std;

struct nodeinfo{
    int l = -1, r = -1;
}tree[N];

int nodenum[N];

void findindex(int node,int num)
{
    nodenum[node] = num;
    if(tree[node].l!=-1) findindex(tree[node].l, num*2);
    if(tree[node].r!=-1) findindex(tree[node].r, num*2+1);
}

void LRD(int parent)
{
    if(tree[parent].l!=-1)  LRD(tree[parent].l);
    if(tree[parent].r!=-1)  LRD(tree[parent].r);
    cout << parent << " ";
}
int main()
{
    int n, node, ls, rs, i(1);
    cin >> n;
    while(i <= n){
        cin >> node >> ls >> rs;
        tree[node].l = ls;
        tree[node].r = rs;
        ++i;
    }
    nodenum[1] = 1;
    findindex(1,1);
    for(i = 1; i <= n; i++)
        cout << nodenum[i] << " ";
    cout << endl;
    LRD(1);
    return 0;
}
