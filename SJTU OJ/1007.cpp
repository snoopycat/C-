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

int main()
{
    string a, b;
    cin >> a >> b;
    string a_int, b_int, a_dec, b_dec;
    a_int = a.substr(0,a.length()-3);
    a_dec = a.substr(a.length()-2,2);
    b_int = b.substr(0,b.length()-3);
    b_dec = b.substr(b.length()-2,2);
    string int_ans = p(a_int,b_int), dec_ans = p(a_dec,b_dec);
    if(dec_ans.length() == 3){
        cout << p(int_ans,"1") + '.' + dec_ans.substr(1,2);
    }
    else
        cout << int_ans + '.' + dec_ans;
    return 0;
}
