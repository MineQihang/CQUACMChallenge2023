#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	vector<char> colors{'R', 'G', 'B'};
	
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			char color;
			if(i % 3 == 0) color = colors[j % 3];
			else if(i % 3 == 1) color = colors[(j + 2) % 3];
			else color = colors[(j + 1) % 3];
			cout << color;
		}
		cout << endl;
	}
	
	return 0;
}