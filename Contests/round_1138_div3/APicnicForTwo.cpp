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
	int l,a,b;
	cin >> l >> a >> b;

	v(bool) s(l,false);
	v(bool) bb(l,false);

	for (int i = 0; !s[i]; i = (a + i) % l) {	
		s[i] = true;
	}

	for (int i = 0; !bb[i]; i = (b + i) % l) {	
		bb[i] = true;
	}

	int cnt = 0;

	for (int i = 0; i < l; ++i) {
		if (s[i] && bb[i]) cnt++;
	}

	cout << cnt << endl;

}

int main() {
	fast_io();
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
