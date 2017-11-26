#include <iostream>

using namespace std;

void quicksort(int a[], int i, int j)
{
    if(i<j){
        int flag_left = a[i*2-1],flag_right = a[i*2], l = i, r = j;
        while(l<r){
            while(a[r*2-1]>=flag_left && l<r)
                r--;
            a[l*2-1] = a[r*2-1];
            a[l*2] = a[r*2];
            while(a[l*2-1]<=flag_left && l<r)
                l++;
            a[r*2-1] = a[l*2-1];
            a[r*2] = a[l*2];
        }
        a[l*2-1] = flag_left;
        a[l*2] = flag_right;
        quicksort(a,i,l-1);
        quicksort(a,l+1,j);
    }
}

int main()
{
    int cars(0);
    cin >> cars;
    int *allpoint = new int[2*cars+1];
    allpoint[0] = 0;
    int i = 0;
    while(i++ < 2*cars){
        cin >> allpoint[i];
    }
    quicksort(allpoint, 1, cars);
    int length(0), l = allpoint[1], r = allpoint[2], r_b(0);
    for(i = 3; i < 2*cars+1; i+=2){
        if(allpoint[i] <= r){
            r = max(r,allpoint[i+1]);
        }
        else{
            length += r-l;
            l = allpoint[i];
            r = allpoint[i+1];
        }
    }
    length += r-l;
    cout << length;
}
