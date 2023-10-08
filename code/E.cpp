#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	map<char, int> cnt{{'R', 2}, {'Y', 2}, {'B', 2}, {'G', 2}};
	int cnt4 = 4;
	int prv = 2;
	
	for(int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		if(x == 4) {
			if(cnt4 <= 0) {
				cout << "No" << endl;
				return 0;
			}
			cnt4 --;
		} else {
			char c;
			cin >> c;
			if(cnt[c] <= 0 || prv == 4) {
				cout << "No" << endl;
				return 0;
			}
			cnt[c] --;
		}
		prv = x;
	}
	
	cout << "Yes" << endl;
	
	return 0;
}