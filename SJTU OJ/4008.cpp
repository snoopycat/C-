#include <cstring>
#include <iostream>

using namespace std;

int m[101] = {0}, n[101] = {0}, ans[101] = {0};
char a[101], b[101];

int main() {
	cin >> a >> b;
	for(int i = 0; i <= strlen(a)-1; i++) m[strlen(a)-i] = int(a[i]-'a');
	for(int i = 0; i <= strlen(b)-1; i++) n[strlen(b)-i] = int(b[i]-'a');
	int len = max(strlen(a),strlen(b));
	for(int i = 1; i <= len; i++){
        ans[i] += m[i]+n[i];
        ans[i+1] = ans[i]/26;
        ans[i] = ans[i]%26;
	}
	if(ans[len+1]) len++;
	for(int i = len; i >= 1; i--) cout << char('a'+ans[i]);
	return 0;
}

