#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    while(n--){
        cin >> x;
        if(!x)
            cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}
