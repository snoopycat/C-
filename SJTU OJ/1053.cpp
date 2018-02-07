#include <iostream>
#include <algorithm>


using namespace std;

const int N = 100001;

struct p{
    int x, y, z;
}points[N];

int n, m;

bool comp(const p& a, const p& b){
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}

int tofind(int x, int y)
{
    p tf;
    tf.x = x; tf.y = y;
    p* f = lower_bound(points,points+n,tf,comp);
    if((f != points+n) && (f->x == x) && (f->y == y)) return f->z;
    return 0;
}

int main()
{
    cin >> n;
    int row[N], col[N];
    for(int i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y >> points[i].z;
    for(int i = 0; i < N; ++i) row[i] = i;
    for(int i = 0; i < N; ++i) col[i] = i;
    cin >> m;
    int op, x, y;
    sort(points,points+n,comp);
    while(m--){
        cin >> op >> x >> y;
        if(op==0){
            swap(row[x],row[y]);
        }
        else if(op==2)
            cout << tofind(row[x],col[y]) << endl;
        else{
            swap(col[x],col[y]);
        }
    }
    return 0;
}
