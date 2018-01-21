#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

int matrix[601][601], res[601][601];

void operation(int n, int op)
{
    memset(&matrix,0,sizeof(matrix));
    memset(&res,0,sizeof(res));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    if(op == 0){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                res[i][j] = matrix[i][n-j-1];
    }
    else if(op == 1){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                res[i][j] = matrix[n-i-1][j];
    }
    else{
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                res[i][j] = matrix[j][i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int num, n, op;
    cin >> num;
    while(num--){
        cin >> n >> op;
        operation(n,op);
    }
    return 0;
}
