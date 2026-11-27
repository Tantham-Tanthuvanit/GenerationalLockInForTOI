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
	string s; cin >> s;
	int res = 1;

	bool dec = false;
	bool inc = false;

	for (int i = 1; i < s.size() - 1 && (dec == false || inc == false); ++i) {
		if (s[i-1] == s[i+1] && s[i] == s[i-1]) inc = true;	
		if (s[i-1] == s[i+1] && s[i] != s[i-1]) dec = true;
	}

	res += dec + inc;

	cout << res << endl;
};

int main() {
	fast_io();
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
