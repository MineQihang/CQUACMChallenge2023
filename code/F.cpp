#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(int i = 0; i < n; i ++) cin >> a[i];
	int x0, y0, x, y;
	cin >> x0 >> y0 >> x >> y;
	x0 --, y0 --;
	
	int x1 = x0, y1 = y0;
	vector<int> ans;
	set<int> st;
	do {
		int t = (a[x1][y1] - '0') * 10 + (a[(x1 + (y1 + 1) / m) % n][(y1 + 1) % m] - '0');
		x1 = (x1 + (y1 + 2) / m) % n;
		y1 = (y1 + 2) % m;
		if(t == 0 || t > x) continue;	// 不在有效范围内
		if(st.count(t)) continue;	// 已经被选出来过了
		ans.push_back(t);
		st.insert(t);
		if((int)ans.size() == y) break;	// 已经选出y个了
	} while(!(x1 == x0 && y1 == y0));
	
	if((int)ans.size() == y) {
		for(int i = 0; i < y; i ++) {
			cout << ans[i] << " \n"[i == y - 1];
		}
	} else {
		cout << -1 << endl;
	}
	
	return 0;
}