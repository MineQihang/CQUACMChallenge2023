#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int len, left;
	node() : len(0), left(0) {};
	node(int l1, int l2) : len(l1), left(l2) {};
	friend bool operator<(const node& x, const node& y) {
		if((x.len - 1) / 2 == (y.len - 1) / 2) return x.left > y.left;
		return x.len < y.len;
	}
};

int main(){
	int n, m; cin >> n >> m;
	string s; cin >> s;
	int l = 1;
	unordered_set<int> st;
	priority_queue<node> q;
	q.push({n, 1});
	for(char c : s) {
		if(c == '0') {
			// update q
			while(!q.empty()) {
				auto tp = q.top(); 
				// cout << tp.len << " " << tp.left << " ?" << q.size() << endl;
				if(st.count(tp.left)) {
					q.pop();
					if(tp.len == 1) continue;
					q.push({tp.len - 1, tp.left + 1});
				} else break;
			}
			// cout << endl;
			// give
			auto tp = q.top();
			q.pop();
			int mid = tp.left + (tp.len - 1) / 2;
			cout << mid << endl;
			st.insert(mid);
			if(mid - tp.left > 0) q.push({mid - tp.left, tp.left});
			if(tp.left + tp.len - 1 - mid > 0) q.push({tp.left + tp.len - 1 - mid, mid + 1});
		} else {
			// update l
			while((l <= n) && st.count(l)) l ++;
			// give
			cout << l << endl;
			st.insert(l);
		}
	}
	return 0;
}