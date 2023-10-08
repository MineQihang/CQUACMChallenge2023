#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	
	int i = 0, j = 0;
	while(j < 4 * n && k > 0) {
		if(s[j] == '1') {
			int delta = j - i;
			if(delta <= k) {
				swap(s[i], s[j]);
				k -= delta;
				i ++;
			} else {
				swap(s[j - k], s[j]);
				k = 0;
				i ++;
			}
		}
		j ++;
	}
	// cout << s << endl;
	
	string ans;
	for(int i = 0; i < n; i ++) {
		int t = (s[i * 4] - '0') * 8 + (s[i * 4 + 1] - '0') * 4 + 
		        (s[i * 4 + 2] - '0') * 2 + (s[i * 4 + 3] - '0');
		ans += char(t + 'A');
	}
	cout << ans << endl;
	
	return 0;
}