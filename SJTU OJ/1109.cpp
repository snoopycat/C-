#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#define N 100010

using namespace std;

int a[N], c[N], num[N];
int n;

int main()
{
    int i(1);
    cin >> n;
    cin >> a[0] >> c[0];
    num[0] = 1;
    while(i < n){
        cin >> a[i] >> c[i];
        num[i] = i+1;
        for(int j = i; j >= 1; j--){
            if(a[j] > a[j-1] && c[j] > 0){
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                tmp = c[j-1];
                c[j-1] = c[j]-1;
                c[j] = tmp;
                num[j] = num[j-1];
                num[j-1] = i+1;
            }
            else
                break;
        }
        ++i;
    }
    for(i = 0; i < n; i++)
        cout << num[i] << " ";
    return 0;
}
