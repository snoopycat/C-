#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#define N 100010

using namespace std;

int counter[3], line[3][N], Time[N];
long long sumoftime[2], last[2];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &Time[i]);
        line[i%3][++line[i%3][0]] = i;
    }
    for(int i = 0; i < 3; i++){
        long long t = 0;
        for(int j = 1; j <= line[i][0]; j++){
            t += Time[line[i][j]];
            sumoftime[0] += Time[line[i][j]]*(line[i][0]-j);
        }
        last[0] = max(last[0],t);
    }
    counter[0] = Time[1],counter[1] = Time[2],counter[2] = Time[3];
    int i = 4;
    while(i <= n){
        int tmin = 1<<30;
        for(int j = 0; j < 3; j++){
            tmin = min(tmin,counter[j]);
            if(counter[j] == 0 && i <= n)
                counter[j] = Time[i++];
        }
        sumoftime[1] += (long long)tmin*(n-i+1);
        last[1] += tmin;
        for(int j = 0; j < 3; j++)
            counter[j] -= tmin;
        for(int j = 0; j < 3; j++)
            if(counter[j]==0 && i <= n) counter[j] = Time[i++];
    }
    int maxcounter(0);
    for(int j = 0; j < 3; j++) maxcounter = max(counter[j],maxcounter);
    last[1] += maxcounter;
    cout << sumoftime[0] << " " << last[0] << endl << sumoftime[1] << " " << last[1] << endl;
    return 0;
}
