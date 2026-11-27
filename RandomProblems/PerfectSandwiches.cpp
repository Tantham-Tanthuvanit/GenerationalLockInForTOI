#include <bits/stdc++.h>
using namespace std;

#define v(i) vector<i>
#define endl '\n'

void fast_io() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
	(void)freopen("input.txt","r",stdin);
	#endif
}

void solve() {
	int a,b; cin >> a >> b;
	if (a <= b) {
		cout << -1 << endl;
		return;
	} else {
		cout << min(b, a-b) << endl;
	}
}

int main() {
	fast_io();
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
