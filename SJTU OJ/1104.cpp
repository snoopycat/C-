#include <iostream>

using namespace std;

int calc(int n)
{
    long long ans = 1;
    for(int i = 1; i < n; i++)
        ans <<= 1;
    return ans;
}

int main()
{
    int T, n;
    cin >> T;
    while(T--){
        cin >> n;
        cout << calc(n) << endl;
    }
    return 0;
}
