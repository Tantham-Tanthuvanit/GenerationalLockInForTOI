#include <bits/stdc++.h>
#include <pthread.h>
#include <queue>
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

void solve(){
	int n,k,p;
	cin >> n >> k >> p;
	priority_queue<int, vector<int>, greater<int>> gf;	

	int res = 0;
	
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		gf.push(x);
	}

	for (int i = 0; gf.size() >= k; ++i) {
		v(int) nums;
		for (int i = 0; i < k; ++i) {
			nums.push_back(gf.top());
			gf.pop();
		}

		int sm = 0;
		for (int i = 0; i < k; ++i) {
			sm += nums[i];
		}

		if (sm > p) res += sm;
		else res += p;
	}

	while (!gf.empty()) {
		res += gf.top();
		gf.pop();
	}

	cout << res << endl;
}

signed main() {
	fast_io();

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
