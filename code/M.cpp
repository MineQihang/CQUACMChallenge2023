#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MAXN = 0x3f3f3f3f3f3f3f3f;

// 计算2的幂次方的最大值，不超过n
int computeMaxPowerOfTwo(int n) {
    int power = 0;
    while (1 << (power + 1) <= n) {
        power++;
    }
    return power;
}

// 构建ST表
vector<vector<int>> buildSparseTable(const vector<int>& arr) {
    int n = arr.size();
    int maxPower = computeMaxPowerOfTwo(n);
    vector<vector<int>> sparseTable(maxPower + 1, vector<int>(n));
    for (int i = 0; i < n; i++) {
        sparseTable[0][i] = arr[i];
    }
    for (int k = 1; (1 << k) <= n; k++) {
        for (int i = 0; i + (1 << k) <= n; i++) {
            sparseTable[k][i] = min(sparseTable[k - 1][i], sparseTable[k - 1][i + (1 << (k - 1))]);
        }
    }
    return sparseTable;
}

// 查询区间最小值
int querySparseTable(const vector<vector<int>>& sparseTable, int left, int right) {
    int k = computeMaxPowerOfTwo(right - left + 1);
    return min(sparseTable[k][left], sparseTable[k][right - (1 << k) + 1]);
}


int main(){
	int n, m; cin >> n >> m;
	vector<int> a(n + 1, 0), b(n + 1, 0);
	vector<ll> d(n + 1, 0), dm0(n + 1, MAXN), dm1(n + 2, MAXN);
	for(int i = 1; i < n; i ++) {
		cin >> a[i];
		d[i + 1] = d[i] + a[i];
	}
	for(int i = 1; i <= n; i ++) cin >> b[i];
	for(int i = 1; i <= n; i ++) dm0[i] = min(dm0[i - 1], b[i] - 2 * d[i]);
	for(int i = n; i >= 1; i --) dm1[i] = min(dm1[i + 1], b[i] + 2 * d[i]);
	// for(int i = 1; i <= n; i ++) cout << dm0[i] << " \n"[i == n];
	// for(int i = n; i >= 1; i --) cout << dm1[i] << " \n"[i == 1];
	for(int i = 1; i <= n; i ++) b[i] = min((ll)b[i], min(dm0[i - 1] + 2 * d[i], dm1[i + 1] - 2 * d[i]));
	vector<vector<int>> mb = buildSparseTable(b);
	// for(int i = 1; i <= n; i ++) cout << b[i] << " \n"[i == n];
	
	int q; cin >> q;
	int sx, sy, tx, ty;
	while(q --) {
		cin >> sx >> sy >> tx >> ty;
		if(tx < sx) swap(sx, tx);
		cout << (sy == ty ? 0 : querySparseTable(mb, sx, tx)) + d[tx] - d[sx] << endl;
		// cout << "? " << querySparseTable(mb, sx, tx) << endl;
	}
	
	
	return 0;
}