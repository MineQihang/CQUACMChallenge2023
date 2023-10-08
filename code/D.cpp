#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < n; i ++) {
		int a, b;
		cin >> a >> b;
		if(k / a < k - b) k /= a;
		else k -= b;
		if(k < 0) break;
	}
	
	if(k < 0) k = 0;
	
	cout << k << endl;
	
	return 0;
}