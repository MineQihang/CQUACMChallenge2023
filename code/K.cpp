#include <bits/stdc++.h>
using namespace std;

using ld = long double;
const ld EPS = 1e-9;

int main(){
	ld x1, y1, r1; cin >> x1 >> y1 >> r1;
	ld x2, y2, r2; cin >> x2 >> y2 >> r2;
	ld a, b, c, d; cin >> a >> b >> c >> d;
	
	ld t0 = sqrt(a * a + b * b), t1 = sqrt(c * c + d * d);
	a /= t0, b /= t0;
	c /= t1, d /= t1;
	// printf("%.10Lf %.10Lf %.10Lf %.10Lf\n", a, b, c, d);
	
	auto check = [&](ld t) {
		auto tx1 = x1 + a * t, ty1 = y1 + b * t;
		auto tx2 = x2 + c * t, ty2 = y2 + d * t;
		auto tr1 = r1 + t, tr2 = r2 + t;
		auto d2 = (tx1 - tx2) * (tx1 - tx2) + (ty1 - ty2) * (ty1 - ty2);
		auto r2 = (tr1 + tr2) * (tr1 + tr2);
		return d2 <= r2;
	};
	
	ld l = 0, r = 1e9 + 10;
	while(r - l >= EPS) {
		// cout << l << " " << r << endl;
		auto mid = (r + l) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	if(l > 1e9) cout << -1;  
	else printf("%.10Lf", l);
	
	return 0;
}