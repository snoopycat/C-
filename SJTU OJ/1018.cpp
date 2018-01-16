#include <iostream>
#include <string>
 
using namespace std;
 
string p(string a, string b)
{
    int tmp = 0, carry = 0, al = a.length(), bl = b.length();
    int i = 0;
    string ans;
    while(i < min(al,bl)){
        tmp = a[al-i-1] - '0' + b[bl-i-1] - '0' + carry;
        carry = tmp/10;
        tmp = tmp%10;
        ans = char(tmp+48) + ans;
        ++i;
    }
    while(i < al){
        tmp = a[al-i-1] - '0' + carry;
        carry = tmp/10;
        tmp = tmp%10;
        ans = char(tmp+48) + ans;
        ++i;
    }
    while(i < bl){
        tmp = b[bl-i-1] - '0' + carry;
        carry = tmp/10;
        tmp = tmp%10;
        ans = char(tmp+48) + ans;
        ++i;
    }
    if(carry)
        return char(carry+48)+ans;
    return ans;
}
 
int main(){
    string a, b;
    while(cin >> a >> b){
        cout << p(a,b) << endl;
    }
    return 0;
}
