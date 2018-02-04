#include <iostream>
#include <cstdio>
#include <stack>


using namespace std;

int N;

int main()
{
    int res(0);
    cin >> N;
    while(N--){
        int a;
        cin >> a;
        while(a){
            if(a%2) ++res;
            a/=2;
        }
    }
    cout << res;
    return 0;
}
