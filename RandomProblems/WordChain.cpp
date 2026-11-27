#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

#define vc(t) vector<t>

void fast_io() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	fast_io();

	int len,n; cin >> len >> n;
	vc(string) vs(n);

	for (int i = 0; i < n; ++i) {
		cin >> vs[i];
	}

	string last = "";

	for (int i = 0; i < n - 1; ++i) {
		int cnt = 0;
		for (int v = 0; v < len; ++v) {
			if (vs[i][v] != vs[i+1][v]) cnt++;
		}

		if (cnt > 2) {
			cout << vs[i] << endl;
			return 0;
		}
	}

	cout << vs[n-1] << endl;
	
	return 0;
}
