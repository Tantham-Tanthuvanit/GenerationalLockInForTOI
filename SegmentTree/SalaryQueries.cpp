#include <algorithm>
#include <bits/stdc++.h>
#include <bits/types/cookie_io_functions_t.h>
using namespace std;

typedef vector<int> vi;

struct query {
	char c;
	int a;
	int b;
};

struct segtree {
	int size;
	vi sums;

	void init(int n) {
		size = 1;

		while (size < n) size *= 2;
		sums.assign(2 * size, 0);
	}

	void set(int i, int v, int x, int lx, int rx) {
		// increase employee on this salary counter by one
		if (rx - lx == 1) {
			sums[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		// perform binary search
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
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && rx <= r) return sums[x];
		int m = (lx + rx) / 2;
		int lt = sum(l,r,2*x+1,lx,m);
		int rt = sum(l,r,2*x+2,m,rx);
		return lt + rt;
	}

	int sum(int l, int r) {
		return sum(l,r,0,0,size);
	}

};

void fast_io() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
	(void)freopen("input.txt","r",stdin);
	#endif
}

int bs(int salary, vi& coords) {
	return lower_bound(coords.begin(), coords.end(), salary) - coords.begin();
}

int main() {

	fast_io();

	int n; int q;
	cin >> n >> q;
	unordered_map<int,int> cnt;
	set<int> indicies;
	vector<int> p(n);

	vector<query> queries;

	for (int i = 0; i < n; ++i ){
		int x; cin >> x;
		cnt[x]++;
		indicies.emplace(x);
		p[i] = x;
	}

	for (int i = 0; i < q; ++i) {
		char c; cin >> c;
		int a,b; cin >> a >> b;
		queries.push_back({c,a,b});
		if (c == '!') {
			indicies.emplace(b);	
		}
	}

	vi coords(indicies.begin(), indicies.end());
	vector<pair<int,int>> freq(cnt.begin(),cnt.end());

	segtree st;
	st.init(coords.size());

	for (int i = 0; i < freq.size(); ++i) {
		st.set(bs(freq[i].first, coords), freq[i].second);
	}

	// process queriesss
	
	for (int i = 0; i < q; ++i) {
		char c = queries[i].c;
		int a = queries[i].a;
		int b = queries[i].b;

		if (c == '!') {
			int old = p[a-1];

			st.set(bs(old,coords), st.sum(bs(old,coords),bs(old,coords) + 1) - 1);

			st.set(bs(b, coords), 
					st.sum(bs(b,coords),bs(b,coords) + 1) + 1);

			p[a-1] = b;
		} else {
			int l = lower_bound(coords.begin(), coords.end(), a) - coords.begin();
			int r = upper_bound(coords.begin(), coords.end(), b) - coords.begin();
			
			cout << st.sum(l,r) << endl;
		}
	}
	
	return 0;
}
