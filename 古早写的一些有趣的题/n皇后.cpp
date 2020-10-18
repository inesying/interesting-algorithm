#include<bits/stdc++.h>
using namespace std;
int ans=0;
int allone;
void dfs(int pos, int left, int right) {
	if (pos == allone){
		++ans;
		return; }
	for (int t = allone & (~(pos | right | left)); t;) {
		int p = t & (-t);
			dfs(pos | p, ((left | p) << 1)&allone, (right | p) >> 1);
			t ^= p;
	}

}
int getanswer(int n) {
	ans = 0;
		allone = (1 << n) - 1;
		dfs(0, 0, 0);
		return ans;
}


int main() {
	int n;
	cin >> n;
	int ans = getanswer(n);
	cout << ans;
	return 0;
}