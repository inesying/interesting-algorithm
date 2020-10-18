#include<bits/stdc++.h>;
using namespace std;

typedef pair<int, int>pii;
#define fi first;
#define se second;

const int N = 2003;
int mind[N][N];
pii q[N*N];
int qh, qt;

pii to(int n, int m, int k, pii p) {
	switch (k) {
	case 0:return pii(0, p.se);
		break;
	case 1:return pii(p.fi(), 0);
		break;
	case 2:return pii(n, p.se());
		break;
	case 3:return pii(p.fi(), m);
		break;
	case 4:return pii(min(n, p.fi + p.se), max(0, p.se - (n - p.fi)));
		break;
	case 5:return pii(max(0, p.first - (n - p.se)), min(m, p.fi + p.se));
		break;
	default:return p;
		break;
	}
}
int getanswer(int n, int m, int t, int d) {
	memset(mind, -1, sizeof(mind));
	qh = qt = 0;
	q[++qt] =pii (0, 0);
	mind[0][0] = 0;
	while (qh < qt) {
		pii u = q[++qh];
		if (mind[u.fi][u.se] == t)
			break;
		for (int k = 0; k < 6; ++k) {
			pii v = to(n, m, k, u);
			if (mind[v.fi][v.se] != -1)
				continue;
			q[++qt] = v;
			mind[v.fi][v.se] = mind[u.fi][u.se] + 1;
		}

	}
	int ans = d;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if(mind[i][j]!=-1)
				ans = min(ans,abs( i + j - d));

		}
	}
	return ans;

}
int main() {
	int n, m, t, d;
	cin >> n;
	cin >> m;
	cin >> t;
	cin >> d;
	int ans = getanswer(n, m, t, d);
	cout << ans << endl;
	return 0;
}


