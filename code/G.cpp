#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int n;
	cin >> n;
	vector<ll> w(n + 1, 0);
	for(int i = 1; i <= n; i ++) cin >> w[i];
	
	int q;
	cin >> q;
	while(q --) {
		int op;
		cin >> op;
		if(op == 1) {
			int x, v;
			cin >> x >> v;
			w[x] += v;
		} else {
			int x;
			cin >> x;
			ll sum = 0;
			for(int i = 1; x <= n; i += 1) {
				sum += w[x];
				w[x] = 0;
				x += i;
			}
			cout << sum << endl;
		}
	}
	
	return 0;
}