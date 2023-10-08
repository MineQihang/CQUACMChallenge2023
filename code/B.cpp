#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, a1, a2, b1, b2;
	cin >> n >> a1 >> a2 >> b1 >> b2;
	
	int ta = 0, suma = 0;
	while(suma < n) {
		suma += a1;
		ta ++;
		a1 += a2;
	}
	// cout << ta << endl;
	
	int tb = 0, sumb = 0;
	while(sumb < n) {
		sumb += b1;
		tb ++;
		b1 += b2;
	}
	// cout << tb << endl;
	
	if(ta == tb) {	
		cout << "Same" << endl;
	} else if(ta < tb) {
		cout << "Plan A" << endl;
	} else {
		cout << "Plan B" << endl;
	}
	
	return 0;
}