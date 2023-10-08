#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;

// 扩展欧几里得算法，用于计算最大公约数和线性组合的系数
ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    ll x1, y1;
    ll gcd = exgcd(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

// 解线性同余方程 ax ≡ b (mod m)
ll solveLinearCongruence(ll a, ll b, ll m) {
    ll x, y;
    ll gcd = exgcd(a, m, x, y);

    if (b % gcd != 0) {
        return -1; // 无解
    } else {
        ll x0 = (x * (b / gcd)) % m;
        return (x0 + m) % m; // 返回最小非负整数解
    }
}

bool check(ll a, ll b, ll c, ll d) {
	ll gcd_bd = __gcd(b, d);

    // 判断是否存在整数解
    if ((c - a) % gcd_bd == 0) {
        // ll x0, y0;
        // exgcd(b, d, x0, y0);
        // ll x = x0 * (c - a) / gcd_bd;
        // ll y = y0 * (c - a) / gcd_bd;

        return true;
    } else {
        return false;
    }
}

int main(){
	ll n, m, x0, y0, a, b;
	cin >> n >> m >> x0 >> y0 >> a >> b;
	ll g = __gcd(a, b);
	a /= g, b /= g;
	// cout << a << " " << b << endl;
	
	if(a == 0) {
		printf("%.10Lf\n", 1.0L * m);
		return 0;
	}
	if(b == 0) {
		printf("%.10Lf\n", 1.0L * n);
		return 0;
	}

	ll tn = abs(n), tm = abs(m), ta = abs(a), tb = abs(b);
	auto lcm = (i128)tn * tm * ta * tb / __gcd(tn * tb, tm * ta);
	auto k1 = lcm / (tn * tb);
	auto t = k1 * tn / ta;
	auto ans = t * sqrt(1.0L * ta * ta + tb * tb);
	
	// check sharp poll
	// 解第一个线性同余方程 (x0 + t * a) ≡ 0 (mod n)
    ll t1 = solveLinearCongruence(a, -x0, n);
    // 解第二个线性同余方程 (y0 + t * b) ≡ 0 (mod m)
    ll t2 = solveLinearCongruence(b, -y0, m);

    if (!(t1 != -1 && t2 != -1 && check(t1, n / __gcd(a, n), t2, m / __gcd(b, m)))) {
        ans *= 2;
    }
	
	printf("%.10Lf\n", ans);
	
	return 0;
}