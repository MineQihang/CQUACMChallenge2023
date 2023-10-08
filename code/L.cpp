#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main(){
	int n; cin >> n;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i ++) cin >> v[i];
	vector<vector<int>> edge(n + 1);
	for(int i = 1; i < n; i ++) {
		int u, v_; cin >> u >> v_;
		edge[u].push_back(v_);
		edge[v_].push_back(u);
	}
	edge[1].push_back(0);
	
	vector<int> s(n + 1, 0);
	function<int(int, int)> dfs = [&](int u, int f) {
		s[u] = v[u];
		for(auto& v_ : edge[u]) {
			if(v_ != f)
				s[u] += dfs(v_, u);
		}
		return s[u];
	};
	dfs(1, 0);
	// for(int i = 1; i <= n; i ++) cout << s[i] << " ";
	
	vector<ld> d(n + 1, 0);
	function<void(int, int, ld)> solve = [&](int u, int f, ld add) {
		// cout << u << " " << add << endl;
		d[u] = s[u] + add;
		for(auto& v_ : edge[u]) {
			if(v_ == f) continue;
			if(edge[u].size() <= 2) solve(v_, u, add);
			else {
				// cout << "? " << (s[u] - v[u] - s[v_]) << " " << edge[u].size() << endl;
				auto td = 1.0L * (s[u] - v[u] - s[v_]) / 2 + add;
				solve(v_, u, td);
			}
		}
	};
	solve(1, 0, 0);
	
	for(int i = 1; i <= n; i ++) printf("%.2Lf%c", d[i], " \n"[i == n]);
	
	return 0;
}