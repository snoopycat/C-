#include <iostream>
#include <queue>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int SIZE = 20010;
int stock_price[SIZE], N, K, n2m, p2m;
pair<int,int> ranking[SIZE];

bool cmp(const pair<int, int> &stock1, const pair<int, int> &stock2){
	if(stock1.second == stock2.second)
		return stock1.first < stock2.first;
	return stock1.second > stock2.second;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i){
        scanf("%d",&stock_price[i]);
    }
    cin >> K;
    char command;
    for(int i = 0; i < K; ++i){
        cin >> command;
        if(command == 'M'){
            cin >> n2m >> p2m;
            stock_price[n2m-1] = p2m;
        }
        else{
            for(int i  = 0; i < N; ++i){
                ranking[i].first = i;
                ranking[i].second = stock_price[i];
            }
            sort(ranking,ranking+N,cmp);
            int reqs, n;
            cin >> reqs;
            for(int i = 0; i < reqs; ++i){
                cin >> n;
                cout << ranking[n-1].first + 1 << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
