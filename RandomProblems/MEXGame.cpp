#include <bits/stdc++.h>
#include <ios>
using namespace std;

#define v(i) vector<i>
#define endl '\n'
typedef pair<int,int> pii;

void fast_io() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
	(void)freopen("input.txt","r",stdin);
	#endif
}

int mex(v(int) arr, int k) {
	v(int) a2 = arr;
	sort(a2.rbegin(),a2.rend());
	map<int,int> mp;

	for (int i = 0; i <= a2[0] + 1; ++i) mp[i] = 0;
	// k is second
	for (int i = 0; i < arr.size(); ++i) {
		mp[arr[i]]++;
	}
	// turn into vector and sort by second element(k) then first
	vector<pair<int,int>> vec(mp.begin(), mp.end());
	
	sort(vec.begin(), vec.end(), [](pii &a, pii &b) {
			if (a.second != b.second) return a.second < b.second;
			return a.first < b.first;
			});

	int res = a2[0] + 1;

	int it = 0;
	for (it = 0; it < vec.size() && vec[it].second < k; ++it) {
		res = min(vec[it].first, res);
	}

	return res;
}

void solve() {
	int n,k; cin >> n >> k;
	v(int) a,b,pile(n);

	for (int i = 0; i < n; ++i) cin >> pile[i];

	sort(pile.rbegin(), pile.rend());

	// construct ab
	stack<int> stk;
	for (int i = 0; i < n; ++i) stk.push(pile[i]);

	for (int i = 0; i < n; ++i) {
		i % 2 == 0 ? a.push_back(stk.top()) : b.push_back(stk.top());
		stk.pop();
	}

	// calculate mex
	if (mex(a,k) != mex(b,k)) cout << "YES" << endl;
	else cout << "NO" << endl;

}

int main() {
	fast_io();
	int t; cin >> t;
	
	while (t--) solve();

	return 0;
}
