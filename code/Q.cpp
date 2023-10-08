#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MASK = (1ll << 31) - 1;

vector<vector<int>> get_groups(vector<int>& nxt) {
	int n = nxt.size() - 1;
	vector<int> f(n + 1, 0);
	for(int i = 1; i <= n; i ++) f[i] = i;
	
	function<int(int)> find = [&](int x) {
		if(x == f[x]) return x;
		else return f[x] = find(f[x]);
	};
	
	auto merge = [&](int x, int y) {
		if(find(x) == find(y)) return false;
		f[find(x)] = find(y);
		return true;
	};
	
	for(int u = 1; u <= n; u ++) {
		auto v = nxt[u];
		merge(u, v);
	}
	
	map<int, vector<int>> mp;
	for(int i = 1; i <= n; i ++) {
		mp[find(i)].push_back(i);
	}
	vector<vector<int>> groups;
	for(auto& it : mp) {
		groups.push_back(it.second);
	}
	return groups;
}

int main(){
	int n; cin >> n;
	vector<int> a(n + 1, 0);
	for(int i = 1; i <= n; i ++) cin >> a[i];
	vector<int> f(n + 1, 0), x(n + 1, 0);
	for(int i = 1; i <= n; i ++) cin >> f[i] >> x[i];
	vector<vector<int>> rf(n + 1);
	for(int i = 1; i <= n; i ++) rf[f[i]].push_back(i);
	
	// 并查集得到集合
	auto groups = get_groups(f);
	// cout << groups.size() << endl;
	
	// 合并and
	function<void(int, int, set<int>&)> merge = [&](int v, int fa, set<int>& st) {
		// cout << v << " " << fa << endl;
		for(auto u : rf[v]) {
			if(!st.count(u) && x[u] && f[u] != -1) {
				a[fa] &= a[u];
				f[u] = -1;
				merge(u, fa, st);
			} else f[u] = fa;
		}
	};
	
	ll ans = 0;
	for(auto group : groups) {
		// 找出group中的loop
		set<int> loop;
		vector<bool> b(n + 1, false);
		for(auto i : group) {
			// cout << "? " << i << endl;
			if(b[i]) break;
			while(!b[i]) {
				b[i] = true;
				i = f[i];
			}
			loop.insert(i);
			int y = f[i];
			while(y != i) {
				loop.insert(y);
				y = f[y];
			}
			break;
		}
		// 对loop中的元素与外面的and先结合
		for(auto v : loop) {
			merge(v, v, loop);
		}
		// 计算外面的所有or
		int outer = 0;
		// 先合并and
		// cout << "==" << endl;
		for(auto i : group) {
			if(f[i] == -1) continue;
			if(loop.count(i)) continue;
			if(!x[i]) merge(i, i, loop);
		}
		// 再计算
		for(auto i : group) {
			// cout << f[i] << " ";
			if(f[i] == -1) continue;
			if(loop.count(i)) continue;
			// cout << a[i] << endl;
			outer |= a[i];
		}
		// cout << endl;
		// cout << outer << endl;
		// 枚举得到loop中最大的数
		// 转化为数组模式
		vector<int> v;
		for(auto i : loop) {
			if(!x[i]) {
				v.push_back(f[i]);
				int t = f[i];
				i = f[t];
				while(i != t) {
					v.push_back(i);
					i = f[i];
				}
				break;
			}
		}
		// 全是and
		int inner = MASK;
		if(v.empty()) {
			for(auto i : loop) inner &= a[i];
			ans += inner | outer;
			continue;
		}
		// 有or -> 求前后缀
		// 前缀
		int m = v.size();
		vector<int> pref(m), land(m), l(m);
		pref[0] = a[v[0]], land[0] = a[v[0]], l[0] = -1;
		for(int i = 1; i < m; i ++) {
			if(x[v[i - 1]]) {
				land[i] = land[i - 1] & a[v[i]];
				l[i] = l[i - 1];
				pref[i] = land[i] | (l[i] != -1 ? pref[l[i]] : 0);
			} else {
				land[i] = a[v[i]];
				l[i] = i - 1;
				pref[i] = land[i] | pref[i - 1];
			}
			// cout << v[i] << " " << land[i] << " " << l[i] << " " << pref[i] << endl;
		}
		// cout << endl;
		// 后缀
		vector<int> suff(m), rand(m), r(m);
		suff[m - 1] = a[v[m - 1]], rand[m - 1] = a[v[m - 1]], r[m - 1] = m;
		for(int i = m - 2; i >= 0; i --) {
			if(x[v[i]]) {
				rand[i] = rand[i + 1] & a[v[i]];
				r[i] = r[i + 1];
				suff[i] = rand[i] | (r[i] != m ? suff[r[i]] : 0);
			} else {
				rand[i] = a[v[i]];
				r[i] = i + 1;
				suff[i] = rand[i] | suff[i + 1];
			}
			// cout << v[i] << " " << rand[i] << " " << r[i] << " " << suff[i] << endl;
		}
		// cout << endl;
		// 合并求解
		int tmax = 0;
		for(int i = 0; i < m - 1; i ++) {
			// cout << v[i] << " "  << pref[i] << " " << suff[i + 1] << endl;
			inner = pref[i] | suff[i + 1];
			tmax = max(tmax, inner | outer);
			// cout << "? " << (inner | outer) << endl;
		}
		ans += tmax;
	}
	
	cout << ans << endl;
	
	return 0;
}