#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;
using point = array<ll, 2>;
using vec = array<ll, 2>;

int main(){
	int n;
	cin >> n;
	vector<point> ps(n);
	for(int i = 0; i < n; i ++) {
		cin >> ps[i][0] >> ps[i][1];
	}
	
	if(n < 3) {
		cout << -1 << endl;
		return 0;
	}
	
	// Const
	ll con = ps[0][1];
	bool flag = true;
	for(int i = 1; i < n; i ++) {
		if(ps[i][1] != con) {
			flag = false;
			break;
		}
	}
	if(flag) {
		cout << "Const" << endl;
		return 0;
	}
	
	// Line
	vec v1{ps[1][0] - ps[0][0], ps[1][1] - ps[0][1]};
	flag = true;
	for(int i = 2; i < n; i ++) {
		vec v2{ps[i][0] - ps[0][0], ps[i][1] - ps[0][1]};
		if((i128)v2[0] * v1[1] != (i128)v2[1] * v1[0]) {
			flag = false;
			break;
		}
	}
	if(flag) {
		cout << "Line" << endl;
		return 0;
	}
	
	// Parabola
	cout << "Parabola" << endl;
	
	return 0;
}