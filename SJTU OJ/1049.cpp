#include <iostream>
#include <cstdio>
#include <stack>


using namespace std;

int N, M;
int order[1001];

int main()
{
    int T;
    bool flag = true;
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i < N; i++) cin >> order[i];
        stack<int> control;
        int i = 0, j = 0;
        while(j<N){
            if(i == order[j]){
                i++;
                j++;
            }
            else if(!control.empty()&&control.top()==order[j]){
                control.pop();
                j++;
            }
            else if( i<N && control.size()<M){
                control.push(i++);
            }
            else{
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
        flag = true;
    }
    return 0;
}
