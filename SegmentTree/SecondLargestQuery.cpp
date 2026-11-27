#include <bits/stdc++.h>
#include <ios>
using namespace std;

typedef vector<int> vi;

struct query {
	int cmd;
	int a;
	int b;
};

struct segmentTree {
	int size;
	vi tr;

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		tr.assign(size,0);
	}


}

void fast_io() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
	(void)freopen("input.txt","r",stdin);
	#endif
}

int main() {
	fast_io();

	int n,q; cin >> n >> q;
	vi v(n);	
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	vector<query> queries(q);
	for (int i = 0; i < q; ++i) {
		int a,b,c;
		cin >> a >> b >> c;
		queries.push_back({a,b,c});
	}

	return 0;
}
