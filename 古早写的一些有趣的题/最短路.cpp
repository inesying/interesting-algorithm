#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int>pii;
const int N = 100005;
vector<pii> graph[N];
int mind[N];
bool flag[N];
priority_queue<pii, vector<pii>, greater<pii>>pq;
int Short(int n, int m, vector<int>U, vector<int>V, vector<int>W, int s, int t) {
	while (!pq.empty())
		pq.pop();
	for (int i = 0; i < n; ++i)
		graph[i].clear();
	memset(mind, 0, sizeof(mind));
	memset(flag, -1, sizeof(flag));
	for (int i = 0; i < m; ++i) {
		graph[U[i]].push_back(make_pair(V[i], W[i]));
		graph[V[i]].push_back(make_pair(U[i], W[i]));
	}
	mind[s] = 0;
	pq.push(make_pair(mind[s], s));
	while (!flag[t]) {
		int u = pq.top().second;
		pq.pop();
		if(!flag[u]){
		flag[u] = 1;
		for (vector<pii>::iterator it = graph[u].begin(); it != graph[u].end(); ++it) {
			int v = it->first,w = it->second;
			if (mind[v] <= mind[u] + w)
				continue;
			mind[v] = mind[u] + w;
			pq.push(make_pair(mind[v], v));
		
		}

	}
		return mind[t];


}

	
	int main() {
		int n, m, s, t;
		cin >> n;
		cin >> m;
		cin >> s;
		cin >> t;
		vector<int>u;
		temp
}

}