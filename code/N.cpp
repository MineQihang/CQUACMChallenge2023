#include <bits/stdc++.h>
using namespace std;

using i128 = __int128;
using a3 = array<i128, 3>;
const i128 I128_MAX = std::numeric_limits<__int128>::max();

// 重载输出操作符
std::ostream& operator<<(std::ostream& os, i128 value) {
    if (value < 0) {
        os << '-';
        value = -value;
    }
    if (value >= 10) {
        os << (value / 10);
    }
    os << static_cast<char>('0' + (value % 10));
    return os;
}

// 重载输入操作符
std::istream& operator>>(std::istream& is, i128& value) {
    std::string input;
    is >> input;
    try {
        size_t pos;
        value = std::stoll(input, &pos);
        if (pos != input.size()) {
            throw std::invalid_argument("Invalid input");
        }
    } catch (const std::invalid_argument& e) {
        is.setstate(std::ios::failbit);
    }
    return is;
}

int main(){
	i128 a, b, c, k;
	cin >> a >> b >> c >> k;
	a3 min_ans{I128_MAX, I128_MAX, I128_MAX};
	auto max_t0 = k / (b * c);
	// a3 rec;
	for(auto t0 = 0; t0 <= max_t0; t0 ++) {
		auto max_t1 = b - (a * b - k / c) / (a - t0);
		for(auto t1 = 0; t1 <= max_t1; t1 ++) {
			auto max_t2 = (a * b * c - k) / ((a - t0) * (b - t1));
			for(auto t2 = 0; t2 <= max_t2; t2 ++) {
				auto t = a * b * c - (a - t0) * (b - t1) * (c - t2);
				if(t > k || t0 >= a - 2 || t1 >= b - 2 || t2 >= c - 2) break;
				a -= t0, b -= t1, c -= t2;
				a3 temp{
					(a - 2) * 4 + (b - 2) * 4 + (c - 2) * 4,
					(a - 2) * (b - 2) * 2 + (a - 2) * (c - 2) * 2 + (b - 2) * (c - 2) * 2,
					(a - 2) * (b - 2) * (c - 2) - (k - t)
				};
				if(temp < min_ans) {
					min_ans = temp;
					// rec = {t0, t1, t2};
					// cout << t << endl;
				}
				a += t0, b += t1, c += t2;
			}
		}
	} 
	// cout << rec[0] << " " << rec[1] << " " << rec[2] << endl;
	cout << "0 0 0 8 " << min_ans[0] << " " << min_ans[1] << " " << min_ans[2] << endl;
	return 0;
}