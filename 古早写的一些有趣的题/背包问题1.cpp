#include<bits/stdc++.h>
using namespace std;

const int N = 5005;
int f[N];
int getanswer(int n, int V, vector<int>op, vector<int>w, vector<int>v) {
	for (int i = 0; i < n; ++i) {
		if (op[i] == 0) 
			for (int j = V; j >= v[i]; --j) 
				f[j] = max(f[j], f[j - v[i]] + w[i]);
			
		else
			for (int j = v[i]; j <= V; ++j) 
				f[j] = max(f[j], f[j - v[i]] + w[i]);
		return f[V];
	}
}

int main() {
	int n;
	cin >> n;
	int V;
	cin >> V;
	vector<int>op, w, v;
	int a, b, c;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		cin >> b;
		cin >> c;
		op.push_back(a);
		w.push_back(b);
		v.push_back(c);
	}
	int ans = getanswer(n, V, op, w, v);
	cout << ans;
	return 0;
}