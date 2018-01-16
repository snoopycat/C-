#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int m, n;
    cin >> m;
    int trade_record[m][3];
    for(int i = 0; i < m; i++)
        cin >> trade_record[i][0] >> trade_record[i][1] >> trade_record[i][2];
    cin >> n;
    int stock[n][2];
    for(int i = 0; i < n; i++)
        cin >> stock[i][0] >> stock[i][1];
    int i(0), j(0);
    double profit = 0.0, money = 0.0;
    for(; i < m; ++i){
        for(;j < n-1; ++j){
            if(trade_record[i][0] >= stock[j][0] && trade_record[i][0] < stock[j+1][0])
                break;
        }
        money = trade_record[i][1]*100*stock[j][1];
        profit -= ((money*0.002)>5?(money*0.002):5);
        profit -= (trade_record[i][1]/10.0+1.0);
        if(trade_record[i][2]==1){
            profit -= money;
        }
        else
            profit += (money-0.001*money);
    }
    cout << fixed << setprecision(2) << profit << endl;
    return 0;
}
