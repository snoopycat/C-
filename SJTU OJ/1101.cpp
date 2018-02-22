#include <iostream>
#include <cstring>

using namespace std;

int ans[15] = {0};

void plusX(unsigned long long x)
{
    int i = 0;
    while(x){
        ans[i] += (x%10);
        ans[i]%=10;
        x/=10;
        ++i;
    }
}

void SUPERXOR(unsigned long long l, unsigned long long r)
{
    memset(ans,0,sizeof(ans));
    for(unsigned long long i = l; i <= r; i++)
        plusX(i);
}

int main()
{
    int N;
    cin >> N;
    while(N--){
        unsigned long long x;
        cin >> x;
        if(x<99)
            SUPERXOR(1,x);
        else{
            unsigned long long l = (x/100)*100;
            SUPERXOR(l,x);
        }
        int i;
        for(i = 14; i >= 0; --i)
            if(ans[i]!=0)
                break;
        if(i==-1)
            cout << 0;
        else
            for(int j = i; j >= 0; --j)
                cout << ans[j];
        cout << endl;
    }
    return 0;
}
