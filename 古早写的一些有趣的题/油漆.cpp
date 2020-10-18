#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>>dp;

ll getanswer(int n, vector<vector<int>>a) {
	dp.resize(n + 1);
	for (int i = 0; i <= n; ++i)
		dp[i].resize(i + 2);
	for (int i = 1; i <= n; ++i) 
		for(int j=1;j<=i;++j){
		dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
	}
	int ans = 0;
	for (int j = 1; j <= n; ++j) {
		ans = max(ans, dp[n][j]);
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>>a;
	a.resize(n + 1);
	for (int i = 0; i < n; ++i)
		a[i].resize = (i + 1);
	
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= i; ++j) {
			int temp;
			cin >> temp;
			a.push_back(temp);
		}
	ll ans = getanswer(n, a);
	cout << ans;
	return 0;



}