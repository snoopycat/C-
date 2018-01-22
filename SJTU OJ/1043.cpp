#include <iostream>
#include <string.h>
#include <queue>
#define N 1000010
using namespace std;

struct nodeinfo{
    int l, r, pre;
}tree[N];
queue<int> record;

int main()
{
    memset(&tree,0,sizeof(N));
    int nodes, num, i(1);
    cin >> nodes;
    tree[0].pre = 0;
    while(i < nodes){
        cin >> num;
        tree[i].pre = num;
        if(tree[num].l==0)
            tree[num].l = i;
        else tree[num].r = i;
        ++i;
    }
    if(tree[0].l) record.push(tree[0].l);
    if(tree[0].r) record.push(tree[0].r);
    bool flag = false, complete = true;
    int current;
    while(!record.empty()){
        current = record.front();
        record.pop();
        if(!tree[current].l&&!tree[current].r) flag = true;
        if(tree[current].l){
            record.push(tree[current].l);
            if(flag){
                complete = false;
                break;
            }
        }
        if(tree[current].r) record.push(tree[current].r);
    }
    if(complete)
        cout << "true";
    else cout << "false";
    return 0;
}
