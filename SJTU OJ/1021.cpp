#include <iostream>
#include <iomanip>
#include <string.h>
 
using namespace std;
 
int main(){
	int i, j;
	int n;
	int *map;
	cin >> n;
	map = new int[n * n];
	memset(map, 0, sizeof(map));
	int h_offset = 1;
	int x_offset = 0;
	int y_offset = 0;
	for (int len = n - 1; len > 0; len-= 2){	//a loop fills a circle, from outer to inner
	    for (i = 0; i < len; ++i){
		map[x_offset * n + (y_offset + i)] = h_offset + i;
		map[(x_offset + i) * n +  (n - 1 - y_offset)] = h_offset + len + i;
		map[(n - 1 - x_offset) * n + (n - 1 - y_offset - i)] = h_offset + 2 * len + i;
		map[(n - 1 - x_offset - i) * n + (y_offset)] = h_offset + 3 * len + i;
		}
		h_offset += 4 * len;
		x_offset ++;
		y_offset ++;
	}
	if(n % 2 == 1)
		map[n * n / 2] = n * n;
	for (i = 0; i < n; ++i){
            for (j = 0; j < n; ++j){
		cout << setw(6) << map[i * n + j];
	    }
	    cout << endl;
	}
	delete []map;
	return 0;
