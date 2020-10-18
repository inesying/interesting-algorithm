#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
vector<int>pos, f;
int getanswer(int n, vector<int>a, vector<int>b) {
	pos.resize(n + 1);
	f.resize(n + 2, inf);
	for (int i = 1; i <= n; ++i) {
		pos[b[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = pos[a[i]];
	}
	f[0] = 0;
	for (int i = 1; i <= n; ++i) {
		*lower_bound(f.begin(), f.end(), a[i]) = a[i];
	}
	return int(lower_bound(f.begin(), f.end(), n + 1) - f.begin()) - 1;
}
int main() {
	int n;
	cin >> n;
	vector<int>a;
	a.clear();
	a.push_back(-1);
	int temp;
	for (int i = 1; i <=n; ++i) {
		cin >> temp;
		a.push_back(temp);
	}
	vector<int>b;
	b.clear();
	b.push_back(-1);
	for (int i = 1; i <= n; ++i) {
		cin >> temp;
		b.push_back(temp);
	}
	int ans = getanswer(n, a, b);
	cout << ans;
	return 0;
}

