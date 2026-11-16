#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define endl '\n'

void build(vi a, vi& t, int i, int tl, int tr) {
	if (tr - tl == 1) t[i] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build(a, t, i*2, tl, tm);
		build(a, t, i*2 + 1, tm, tr);
		t[i] = t[i*2] + t[i*2+1];
	}
}

int sum(int i, vi &t, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l) return 0; // no overlap
	if (l <= tl && tr <= r) return t[i]; // nested segment

	int tm = (tl + tr) / 2;
	// partial overlap
	return sum(i * 2, t, tl, tm, l, r) + sum(i * 2 + 1, t, tm, tr, l, r);
}

void update(int v, vi &t, int tl, int tr, int pos, int new_val) {
	if (tr - tl == 1) t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos < tm) update(v*2, t, tl, tm, pos, new_val);
		else update(v * 2 + 1, t, tm, tr, pos, new_val);
	}
}

int main() {
	return 0;
}
