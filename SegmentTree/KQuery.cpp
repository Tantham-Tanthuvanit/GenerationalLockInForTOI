#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'

struct query {
	int l;
	int r;
	int k;
	int i;
	int ans;
};

struct segtree {
	int size;
	vi v;

	void init(int n) {
		size = 1;

		while (size < n) size *= 2;
		v.assign(2 * size, 0);
	}

	void set(int i, int x, int lx, int rx) {
		if (rx - lx == 1) {
			v[x] = 1;
			return;
		}

		int m = (lx + rx) / 2;
		if (i < m) {
			set(i,2*x+1,lx,m);
		} else {
			set(i,2*x+2,m,rx);
		}

		v[x] = v[2*x+1] + v[2*x+2];
	}

	void set(int i) {
		set(i,0,0,size);
	}

	int query(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && rx <= r) return v[x];
		int m = (lx + rx) / 2;
		int lt = query(l,r,2*x+1,lx,m);
		int rt = query(l,r,2*x+2,m,rx);
		return lt + rt;
	}
	
	int query(int l, int r) {
		return query(l,r,0,0,size);
	}

};

void fast_io() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
	(void)freopen("input.txt","r",stdin);
	#endif
}

int main() {
	fast_io();

	int n; cin >> n;
	vi nums(n);
	vector<pair<int,int>> sorted_nums;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
		sorted_nums.push_back({nums[i],i});
	}

	sort(sorted_nums.rbegin(), sorted_nums.rend());

	segtree st;
	st.init(n);

	int q; cin >> q;
	vector<query> queries;
	for (int i = 0; i < q; ++i) {
		int a,b,c;
		cin >> a >> b >> c;
		queries.push_back({a,b,c,i,0});
	}

	sort(queries.begin(), queries.end(), [](query a, query b) {
		return a.k > b.k;
			});

	vi ans(q);
	int ptr = 0;

	for (auto& qu : queries) {
		// activate queries


		while (ptr < n && sorted_nums[ptr].first > qu.k) {
			st.set(sorted_nums[ptr].second);
			ptr++;
		}

		qu.ans = st.query(qu.l - 1, qu.r);
	}

	sort(queries.begin(), queries.end(), [](query a, query b) {
			return a.i < b.i;
			});

	for (auto& q : queries)
		cout << q.ans << endl;

	return 0;

}
