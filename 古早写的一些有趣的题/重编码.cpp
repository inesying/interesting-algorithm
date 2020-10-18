#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll getanswer(int n, vector<ll>seq) {
	ll sum=0;
	priority_queue(ll, vector<ll>, greater<ll>)pq;
	for(int i=0;i<n;++i) {
		pq.push(seq[i])
	}
	while (pq.size() > 1) {
		ll newele = 0;
		for (int i = 0; i < 2; ++i) {
			ll ele = 0;
			ele = pq.pop();
			newele += ele;

		}
		sum += newele;
		pq.push(newele);
	}
	return sum;
}
int mian() {
	int n;
	cin >> n;
	vector<ll>seq;
	int x = n;
	while (x--) {
		int temp;
		cin >> temp;
		seq.push_back(temp);
	}
	ll sum;
	sum = getanswer(n, seq);
	cout << sum;
	return 0;
}
