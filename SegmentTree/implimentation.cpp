#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct segtree {

	int size;
	vi sums;
	
	void init(int n) {
		size = 1;

		while (size < n) size *= 2;
		sums.assign(2 * size, 0);
	}

	void set(int i, int v, int x, int lx, int rx) {
		// check if in leaf node
		if (rx - lx == 1) {
			sums[x] = v;
			return;
		}	
		int m = (lx + rx) / 2;
		// if its left of the middle then go left
		if (i < m) {
			set(i,v,2*x+1,lx,m);
		} else {
			set(i,v,2*x+2,m,rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}

	void set(int i, int v) {
		set(i,v,0,0,size);	
	}

	int sum(int l, int r, int x, int lx, int rx) {
		// outside boundries
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && rx <= r) return sums[x];
		int m = (lx + rx) / 2;
		int lt = sum(l,r,2*x + 1, lx, m);
		int rt = sum(l,r,2*x + 2, m, rx);
		return lt + rt;
	}

	int sum(int l,int r) {
		return sum(l,r,0,0,size);
	}

};

int main() {
	int n, m; cin >> n >> m;

	segtree st;
	st.init(n);

	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		st.set(i, v);
	}

	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int i, v;
			cin >> i >> v;
			st.set(i,v);
		} else {
			int l,r;
			cin >> l >> r;
			cout << st.sum(l,r) << '\n';
		}
	}

	return 0;
}
