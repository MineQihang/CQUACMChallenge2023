#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int qpow(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = 1ll * ans * x % MOD;
		x = 1ll * x * x % MOD;
		y >>= 1;
	}
	return ans;
}

void solve() {
	int n, m;
	cin >> n >> m;
	cout << qpow(1 + m, n) << endl;
}

int main(){
	int t;
	cin >> t;
	
	while(t --) solve();
	
	return 0;
}