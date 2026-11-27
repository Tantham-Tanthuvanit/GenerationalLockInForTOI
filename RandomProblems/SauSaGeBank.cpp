#include <bits/stdc++.h>
using namespace std;

#define v(i) vector<i>
#define endl '\n'
#define int long long

void fast_io() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
	(void)freopen("input.txt","r",stdin);
	#endif
}

void solve() {
	int d,k;
	cin >> d >> k;
	
	int res = 1;
	
	for (int i = 0; i < d - (k - 1); ++i)
		res *= 2;

	res += (k-1) * 2;

	cout << res << endl;
}

signed main() {
	fast_io();
	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}
