#include <bits/stdc++.h>
#include <set>
using namespace std;

typedef vector<int> vi;

#define int unsigned long long
#define endl '\n'

struct segmentTree {
	int n;
	vi sums;

	void init(int size) {
		n = 1;
		
		while (n < size) n *= 2;
		sums.assign(2*n, 0);
	}

	void set(int i, int v, int x, int lx, int rx) {
		// leaf node
		if (rx - lx == 1) {
			sums[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		// if current index is less than the middle
		if (i < m)
			set(i,v, 2*x+1, lx, m);	
		else
			set(i,v, 2*x+2, m, rx);

		sums[x] = sums[2*x+1] + sums[2*x+2];
	}

	void set(int i, int v) {
		set(i,v,0,0,n);
	}

	int sum(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && rx <= r) return sums[x];
		int m = (lx + rx) / 2;
		int lt = sum(l,r,2*x + 1,lx,m);
		int rt = sum(l,r,2*x+2,m,rx);

		return lt + rt;
	}

	int sum(int l, int r) {
		return sum(l,r,0,0,n);
	}
};

void fast_io() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
	(void)freopen("input.txt","r",stdin);
	#endif
}

signed main() {

	fast_io();

	int n,m; cin >> n >> m;
	
	segmentTree st;
	st.init(n);

	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		st.set(i,x);
	}

	for (int i = 0; i < m; ++i) {
		int cmd,a,b; cin >> cmd >> a >> b;
		if (cmd == 1) {
			st.set(a,b);	
		} else {
			cout << st.sum(a,b) << endl;
		}
	}

	return 0;
}
