#include <iostream>
#include <string.h>
#include <cmath>
#include <string>
#include <stdio.h>

using namespace std;


int main()
{
    int n, i(0), l, r;
    char nth;
    string book_row, ans;
    cin >> n;
    string books[n];
    cin.get(nth);
    while(cin.get(nth) && i < n){
        if(nth != '\n'){
            book_row += nth;
        }
        else{
            books[i++] = book_row;
            book_row = "";
            if(i == n)
                break;
        }
    }
    for (i = 0; i < n-1; i++){
        cin >> l >> r;
        books[r-1] = books[r-1] + " " + books[l-1];
    }
    cout << books[r-1];
    return 0;
}
